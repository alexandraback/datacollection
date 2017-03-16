#define LARGE
//#define SMALL

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int T, N, J;

int main()
{
#if defined(LARGE)
    freopen("../C-large.in", "r", stdin);
    freopen("../C-large.out", "w", stdout);
#elif defined(SMALL)
    freopen("../C-small-attempt2.in", "r", stdin);
    freopen("../C-small.out", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
#endif

    cin >> T;

    const int P = 10;
    long long int p[P] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    const int L = 9, D1 = 16, D2 = 32;
    int i, j;
    long long int _n, n;

    long long int divs[L];
    long long int table[L][D1];
    for (i = 0; i < L; ++i)
    {
        table[i][0] = 1;
        table[i][1] = (long long int) (i+2);
    }
    for (i = 0; i < L; ++i)
    {
        for (j = 2; j < D1; ++j)
        {
            table[i][j] = table[i][j-1] * table[i][1];
        }
    }

    cin >> N >> J;
    cout << "Case #1:\n";

    if (N == D1)
    {
        string s = "1000000000000001";

        for (; J != 0;)
        {
            for (i = 0; i < L; ++i)
            {
                n = 0;
                for (j = 0; j < N; ++j)
                {
                    if (s[N-j-1] == '1') n += table[i][j];
                }

                for (j = 0; j < P; ++j)
                {
                    if (n % p[j] == 0)
                    {
                        divs[i] = p[j];
                        break;
                    }
                }

                if (j == P) break;
            }

            if (i == L)
            {
                cout << s;
                for (i = 0; i < L; ++i) cout << " " << divs[i];
                cout << "\n";
                --J;
            }

            for (j = N-2, ++s[j]; s[j] == '2'; --j)
            {
                s[j] = '0';
                ++s[j-1];
            }
        }
    }
    else if (N == D2)
    {
        string s = "10000000000000000000000000000001";

        for (; J != 0;)
        {
            for (i = 0; i < L; ++i)
            {
                _n = 0;
                n = 0;
                for (j = 0; j < N/2; ++j)
                {
                    if (s[N/2-j-1] == '1') _n += table[i][j];
                    if (s[N-j-1] == '1') n += table[i][j];
                }

                for (j = 0; j < P; ++j)
                {
                    if (((_n % p[j]) * table[i][1] * table[i][D1-1] + n) % p[j] == 0)
                    {
                        divs[i] = p[j];
                        break;
                    }
                }

                if (j == P) break;
            }

            if (i == L)
            {
                cout << s;
                for (i = 0; i < L; ++i) cout << " " << divs[i];
                cout << "\n";
                --J;
            }

            for (j = N-2, ++s[j]; s[j] == '2'; --j)
            {
                s[j] = '0';
                ++s[j-1];
            }
        }
    }

    return 0;
}
