#include <iostream>
#include <vector>
#include <cmath>
typedef long long LL;
using namespace std;
LL get_divisor(LL n)
{
    if (n % 3 == 0) return 3;
    if (n % 5 == 0) return 5;
    if (n % 7 == 0) return 7;
    if (n % 11 == 0) return 11;
    if (n % 13 == 0) return 13;
    if (n % 17 == 0) return 17;
    if (n % 19 == 0) return 19;
    return 0;
}


int main()
{
    LL M = 3 * 5 * 7 * 11 * 13 * 17 * 19;
    int T, n, J;
    cin >> T;
    vector<LL> divisors(11);
    for (int I = 1; I <= T; ++I)
    {
        cin >> n >> J;
        LL m = 1 << (n-2);
        vector<int> vec(n);
        vec[0] = 1;
        vec[n-1] = 1;
        cout << "Case #" << I << ": " << endl;
        for (LL i = 0; i < m; ++i)
        {
            LL p = i;
            for (int j = 1; j < n-1; ++j)
            {
                vec[j] = p % 2;
                p >>= 1;
            }
            bool found = true;
            for (int j = 2; j <= 10; ++j)
            {
                p = 0;
                for (int k = 0; k < n; ++k)
                    p = (p * j + vec[k]) % M;
                LL divisor = get_divisor(p);
                if (divisor == 0)
                {
                    found = false;
                    break;
                }
                else
                    divisors[j] = divisor;
            }
            if (found)
            {
                --J;
                for (int j = 0; j < n; ++j) cout << vec[j];
                for (int j = 2; j <= 9; ++j) cout << " " << divisors[j];
                cout << endl;
            }
            else
            {
 //               for (int j = 0; j < n; ++j) cout << vec[j]; cout << endl;
            }
            if (J == 0) break;
        }
    }
}
