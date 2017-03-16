#include <iostream>
#include <vector>

using namespace std;

bool checkDivisibility(long long coin, int base, int d)
{
    int modtotal=0;
    int cur = 1;
    while(coin)
    {
        if(coin % 2)
        {
            modtotal += cur;
        }
        coin /= 2;
        cur *= base;
        cur %= d;
    }
    //cout << "check " << base << " " << d << " " << modtotal << endl;
    return !(modtotal % d);
}

void printCoin(long long coin, int n)
{
    for(int i=n-1; i >= 0; i--)
    {
        if( coin & (1LL << i) )
            cout << "1";
        else
            cout << "0";
    }
}

void doCase()
{
    int n, j;
    cin >> n >> j;
    cout << endl;
    long long coin = (1LL << (n-1)) + 1;
    int coins=0;
    while(coins < j)
    {
        vector<int> divs;
        for(int base=2; base<=10; base++)
        {
            for(int d=3; d < 1000; d+=2)
            {
                if(checkDivisibility(coin, base, d))
                {
                    divs.push_back(d);
                    break;
                }
            }
        }
        if(divs.size() == 9)
        {
            printCoin(coin,n);
            for(int i=0; i<9; i++)
                cout << " " << divs[i];
            cout << endl;
            coins++;
        }
        coin += 2;
    }
    return;
}

int main()
{
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        cout << "Case #" << i+1 << ": ";
        doCase();
    }
    return 0;
}
