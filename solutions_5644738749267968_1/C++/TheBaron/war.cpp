#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;

void display(int row)
{
    cout << ' ' << row;
}

int main(int argc, char* argv[])
{
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test)
    {
        cout << "Case #" << test << ": ";
        int columns;
        cin >> columns;
        set<double> naomi;
        set<double> ken;
        double data;
        for (int i=0; i<columns; ++i)
        {
            cin >> data;
            naomi.insert(data);
        }
        for (int i=0; i<columns; ++i)
        {
            cin >> data;
            ken.insert(data);
        }
        set<double> ken2 = ken;
        int warloss=0;
        int dwarloss=0;
        set<double>::iterator nit;
        set<double>::iterator kit;
        set<double>::iterator kfit;
        set<double>::iterator klit;
        
        nit = naomi.begin();
        while (nit != naomi.end())
        {
            kfit = ken.begin();
            klit = ken.end();
            --klit;
            if (*nit > *klit) break; // Everything else is a winner
            else if (*nit < *kfit)
            {
                ++dwarloss;
                ken.erase(klit);
            }
            else
            {
                ken.erase(kfit);
            }
            ++nit;
        }
        
        nit = naomi.begin();
        while (nit != naomi.end())
        {
            kit = ken2.lower_bound(*nit);
            if (kit != ken2.end())
            {
                ++warloss;
                ken2.erase(kit);
            }
            else ken2.erase(ken2.begin());
            ++nit;
        }

        cout << columns - dwarloss << ' ' << columns - warloss << endl;


    }
    return 0;
}
