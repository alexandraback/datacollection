// Author: Harhro94 [Harutyunyan Hrayr]
#pragma comment(linker, "/STACK:66777216")
#define _CRT_SECURE_NO_WARNINGS
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
typedef long double LD;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

int a, b, k;
vector<int> A, B, K;
LL dp[32][2][2][2];

int main()
{
#ifdef harhro94
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#define task "london"
    freopen(task".in", "r", stdin);
    freopen(task".out", "w", stdout);
#endif

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        printf("Case #%d: ", t);
        scanf("%d%d%d", &a, &b, &k);
        A.clear();
        B.clear();
        K.clear();
        A.resize(30);
        B.resize(30);
        K.resize(30);
        for (int i = 0; i < 30; ++i)
        {
            A[i] = ((a >> i) & 1);
            B[i] = ((b >> i) & 1);
            K[i] = ((k >> i) & 1);
        }
        reverse(all(A));
        reverse(all(B));
        reverse(all(K));
        memset(dp, 0, sizeof dp);
        dp[0][1][1][1] = 1;
        for (int i = 0; i < 30; ++i)
        {
            int da = A[i];
            int db = B[i];
            int dk = K[i];
            for (int ma = 0; ma < 2; ++ma)
            {
                for (int mb = 0; mb < 2; ++mb)
                {
                    for (int mk = 0; mk < 2; ++mk)
                    {
                        for (int na = 0; na < 2; ++na)
                        {
                            for (int nb = 0; nb < 2; ++nb)
                            {
                                int tma, tmb, tmk;
                                int nk = na & nb;
                                if (ma == 1 && na > da) continue;
                                if (mb == 1 && nb > db) continue;
                                if (mk == 1 && nk > dk) continue;
                                tma = ma;
                                tmb = mb;
                                tmk = mk;
                                if (ma == 1 && na < da) tma = 0;
                                if (mb == 1 && nb < db) tmb = 0;
                                if (mk == 1 && nk < dk) tmk = 0;
                                dp[i + 1][tma][tmb][tmk] += dp[i][ma][mb][mk];
                            }
                        }
                    }
                }
            }
        }
        printf("%I64d\n", dp[30][0][0][0]);
    }

#ifdef harhro94
    cerr << fixed << setprecision(3) << "\nExecution time = " << clock() / 1000.0 << "s\n";
#endif
    return 0;
}