#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

void testCase()
{
    long long p, q;
    cin >> p;
    cin.ignore();
    cin >> q;

    if(q == 0)
    {
        cout << " impossible" << endl;
        return;
    }

    long long factor = (1LL<<40LL);

    while(q%2 == 0 && factor>1)
    {
        q /= 2LL;
        factor /= 2LL;
    }
    if(p % q != 0)
    {
        cout << " impossible" << endl;
        return;
    }
    long long c = (p/q)*factor;
    for(long long i=1; i<=40; i++)
    {
        long long bit = (1LL<<(40LL-i));
        if(c & bit)
        {
            cout << " " << i << endl;
            return;
        }
    }
    cout << " impossible" << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cout << "Case #" << i+1 << ":";
        testCase();
    }
}


