#include <iostream>
#include <vector>

using namespace std;

class Automat
{
protected:
    vector<Automat> atm;
    int woter;
    int sugar;
    int coffee;
    int tea;
    int coffeeC;
    int teaC;
    int cache;

public:
    Automat(int woter = 5000, int sugar = 2000, int coffee = 1500, int tea = 1000, int coffeeC = 2, int teaC = 1, int cache = 0)
    {
        this->woter = woter;
        this->sugar = sugar;
        this->coffee = coffee;
        this->tea = tea;
        this->coffeeC = coffeeC;
        this->teaC = teaC;
        this->cache = cache;
    }

    void SetWoter()
    {
        if (this->woter == 0)
        {
            cout << "Add woter: ";
            cin >> woter;
            this->woter = +woter;
        }
    }
    void SetSugar()
    {
        if (this->sugar == 0)
        {
            cout << "Add sugar: ";
            cin >> sugar;
            this->sugar = +sugar;
        }
    }
    void SetCoffee()
    {
        if (this->coffee == 0)
        {
            cout << "Add coffee: ";
            cin >> coffee;
            this->coffee = +coffee;
        }
    }
    void SetTea()
    {
        if (this->tea == 0)
        {
            cout << "Add tea: ";
            cin >> tea;
            this->tea = +tea;
        }
    }
    void SetMark()
    {
        cout << "Cina cofefe: ";
        cin >> coffeeC;
        this->coffeeC = coffeeC;
        cout << "Cina tea: ";
        cin >> teaC;
        this->teaC = teaC;
    }
    int GetWoter() { return this->woter; }
    int GetSugar() { return this->sugar; }
    int GetCoffee() { return this->coffee; }
    int GetTea() { return this->tea; }
    int GetCoffeeC() { return this->coffeeC; }
    int GetTeaC() { return this->teaC; }
    int GetCache() { return this->cache; }

    void Show()
    {
        cout << "Automat is full: \n";
        cout << "Woter: \t" << woter << endl;
        cout << "Sugar: \t" << sugar << endl;
        cout << "Cofe: \t" << coffee << " Price: " << coffeeC << " $.\n";
        cout << "Tea: \t" << tea << " Price: " << teaC << " $.\n";
        cout << "Cache: \t" << cache << endl;
    }
    int SetCache()
    {
        return this->cache = coffeeC + teaC;
    }
};

class Coffee :public Automat
{
    int coffeeWoter;
    int coffeeSugar;
    int coffeeCoffee;
    int coffeePrice;
public:
    Coffee()
    {
        coffeeWoter = 100;
        coffeeSugar = 10;
        coffeeCoffee = 15;
        coffeePrice = 2;
    }
    void CookingCoffee()
    {

        this->woter = -coffeeWoter;
        this->sugar = -coffeeSugar;
        this->coffee = -coffeeCoffee;
        this->cache = +coffeePrice;
    }

};

class Tea : public Automat
{
    int teaWoter;
    int teaSugar;
    int teaCoffee;
    int teaPrice;
public:
    Tea()
    {
        teaWoter = 150;
        teaSugar = 15;
        teaCoffee = 20;
        teaPrice = 1;
    }
    void CookingTea()
    {
        this->woter = -teaWoter;
        this->sugar = -teaSugar;
        this->coffee = -teaCoffee;
        this->cache = +teaPrice;
    }
};

class Admin
{
    Automat* tmp;
public:
    void Add()
    {
        tmp = new Automat;
        tmp->SetWoter();
        tmp->SetSugar();
        tmp->SetCoffee();
        tmp->SetTea();
    }
    void Mark()
    {
        tmp->SetMark();
    }
    void RemovingCache()
    {
        if (tmp->GetCache() != 0)
        {
            cout << "Cashe = " << tmp->GetCache() << endl;
            tmp->SetCache();
        }
        else
            cout << "There are no funds in the machine!\n";
    }
    void ShowStatistic()
    {
        tmp->Show();
    }
};

class Client :public Coffee, public Tea
{

public:
    void DrinkCofe()
    {
        Coffee* drink = new Coffee;
        drink->CookingCoffee();
    }
    void DrinkTea()
    {
        Tea* drink = new Tea;
        drink->CookingTea();
    }
};


int main()
{
    Admin ad;
    Client bob;
    char choice;
    do
    {
        cout << "1 - Cofe.\n";
        cout << "2 - Tea.\n";
        cout << "a - Admin Add products.\n";
        cout << "s - Output statistics for the presence of components for the preparation of drinks.\n";
        cout << "d - Changing prices for drinks.\n";
        cout << "f - Admin Removing is cache\n";
        cout << "x - Exit\n";
        cin >> choice;
        switch (choice)
        {
        case '1':
            cout << "Cofe.\n";
            bob.DrinkCofe();
            break;
        case '2':
            cout << "Tea.\n";
            bob.DrinkTea();
            break;
        case 'a':
            cout << "Admin Add products.\n";
            ad.Add();
            break;
        case 's':
            cout << "Output statistics for the presence of components for the preparation of drinks.\n";
            ad.ShowStatistic();
            break;
        case 'd':
            cout << "Changing prices for drinks.\n";
            ad.Mark();
            break;
        case 'f':
            cout << "Admin Removing is cache\n";
            ad.RemovingCache();
            break;
        case 'x':
            cout << "Goodbye!\n";
            return 0;
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    } while (choice != 0);
    system("pause");
    return 0;
}