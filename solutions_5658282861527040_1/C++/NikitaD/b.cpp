#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

template <class T> inline T sqr(T x) { return x * x; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

int getBinaryLen(int a)
{
    int res = 0;
    while (a)
    {
        ++res;
        a >>= 1;
    }
    return res;
}

int inline getBit(int x, int i)
{
    return (x & (1 << i)) ? 1 : 0;
}

ll d[40][2][2][2];

void solve()
{
    int A, B, K;
    scanf("%d%d%d", &A, &B, &K);

    int na = getBinaryLen(A);
    int nb = getBinaryLen(B);
    int nk = getBinaryLen(K);
    int n = max(max(na, nb), nk);

    
    memset(d, 0, sizeof(d));
    d[n][1][1][1] = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        int ai = getBit(A, i);
        int bi = getBit(B, i);
        int ki = getBit(K, i);
        for (int i1 = 0; i1 < 2; ++i1)
        {
            for (int i2 = 0; i2 < 2; ++i2)
            {
                for (int i3 = 0; i3 < 2; ++i3)
                {
                    for (int c1 = 0; c1 < 2; ++c1)
                    {
                        if (i1 == 1 && c1 > ai)
                            continue;

                        for (int c2 = 0; c2 < 2; ++c2)
                        {
                            if (i2 == 1 && c2 > bi)
                                continue;
                            if (i3 == 1 && (c1 * c2) > ki)
                                continue;

                            int j1 = i1;
                            int j2 = i2;
                            int j3 = i3;

                            if (c1 == 0 && ai == 1)
                                j1 = 0;
                            if (c2 == 0 && bi == 1)
                                j2 = 0;
                            if (c1 * c2 == 0 && ki == 1)
                                j3 = 0;

                            d[i][j1][j2][j3] += d[i + 1][i1][i2][i3];
                        }
                    }
                }
            }
        }
    }

    ll ans = d[0][0][0][0];
    printf("%I64d\n", ans);
}


int main()
{
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++test)
    {
        printf("Case #%d: ", test);
        solve();
    }



    return 0;
}