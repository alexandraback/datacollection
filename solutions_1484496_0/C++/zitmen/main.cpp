#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define N 20
#define NN 1048576U

int n[N];

unsigned long long getSum(unsigned int i)
{
    unsigned long long sum = 0;
    for(int x = 0; x < 20 && i > 0; x++)
    {
        if(i%2==1) sum += n[x];
        i/=2;
    }
    return sum;
}

void printSubset(unsigned int i)
{
    bool first = true;
    for(int x = 0; x < 20 && i > 0; x++)
    {
        if(i%2==1)
        {
            if(!first) cout << ' ';
            first = false;
            cout << n[x];
        }
        i/=2;
    }
    cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        int pocet;
        cin >> pocet;
        for(int i = 0; i < N; i++)
            cin >> n[i];
        //
        unsigned int i, j;
        for(i = 1; i < NN; i++)
        {
            for(j = i+1; j < NN; j++)
            {
                if((i&j) == 0)
                {
                    if(getSum(i) == getSum(j))
                    {
                        goto _ok;
                    }
                }
            }
        }
        goto _no;
        //
_ok:    cout << "Case #" << t << ":\n";
        printSubset(i);
        printSubset(j);
        continue;
_no:    cout << "Case #" << t << ":\nImpossible\n";
        continue;
    }
    return 0;
}