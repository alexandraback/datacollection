#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    (void)argc; (void)argv;
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int t;
    cin >> t;
    for(int caso=1; caso<=t; caso++)
    {
        if(caso!=1)
            cout << endl;
        int n, m, k;
        cin >> n;
        cin >> m;
        cin >> k;
        if(k<=4)
        {
            cout << "Case #" << caso << ": " << k;
            continue;
        }
        if(n<=2 || m<=2)
        {
            cout << "Case #" << caso << ": " << k;
            continue;
        }
        if(k>=n*m-4)
        {
            int te=k-(n*m-4);
            int p=((n-2)*2)+((m-2)*2)+te;
            cout << "Case #" << caso << ": " << p;
            continue;
        }
        int pietre=4;
        int nbound=1;
        int mbound=1;
        int posti=5;
        while(posti<k)
        {
            if((nbound<mbound && nbound+2<n) || mbound>=m)
            {
                posti+=mbound;
                pietre+=2;
                posti+=2;
                nbound++;
            }
            else
            {
                posti+=nbound;
                pietre+=2;
                posti+=2;
                mbound++;
            }
        }
        cout << "Case #" << caso << ": " << pietre;
    }
    return 0;
}
