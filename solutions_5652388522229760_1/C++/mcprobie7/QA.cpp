#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("outputA.txt", "w", stdout);
    int nT;
    cin >> nT;
    for (int iT = 0; iT < nT; iT++)
    {
        int n;
        cin >> n;
        if (n == 0) { cout << "Case #" << iT + 1 << ": " << "INSOMNIA" << endl; }
        else
        {
           int bm = 0;
           long long k = n;
           while (1)
           {
                long long k0 = k;
                while (k0 > 0)
                {
                    bm = bm | (1 << (k0 % 10));
                    k0 /= 10;
                }
                if (bm == ((1 << 10) - 1)) { cout << "Case #" << iT + 1 << ": " << k << endl; break; }
                else k = k + n;
           }
        }
    }
    return 0;

}
