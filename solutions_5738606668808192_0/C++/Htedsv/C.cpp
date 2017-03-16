#include <iostream>
#include <vector>
#include <cmath>
typedef long long LL;
using namespace std;
int get_divisor(LL n)
{
    for (int i = 2; i < sqrt(n); ++i)
    {
        if (n % i == 0)
            return i;
    }
    return 0;
}


int main()
{
    int T, n, J;
    cin >> T;
    vector<int> divisors(11);
    for (int I = 1; I <= T; ++I)
    {
        cin >> n >> J;
        int m = 1 << (n-2);
        vector<int> vec(n);
        vec[0] = 1;
        vec[n-1] = 1;
        cout << "Case #" << I << ": " << endl;
        for (int i = 0; i < m; ++i)
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
                    p = p * j + vec[k];
                int divisor = get_divisor(p);
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
                for (int j = 2; j <= 10; ++j) cout << " " << divisors[j];
                cout << endl;
            }
            if (J == 0)
                break;
        }
    }
}
