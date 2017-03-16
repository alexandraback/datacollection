/*
* File:    main.cpp
* Author:  Hrayr [HarHro94]
* Problem:
* IDE:     Visual C++ 2012
*/
//#pragma comment(linker, "/STACK:66777216")
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define LL long long
#define LD long double

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define FOR1(i, n) for(int i = 1; i <=n; ++i)
#define FORD(i, n) for(int i = n - 1; i >= 0; --i)
#define FORD1(i, n) for(int i = n; i >= 1; --i)
#define FORA(i, a, b) for(int i = a; i <= b; ++i)
#define FORDA(i, a, b) for(int i = a; i >= b; --i)

const int N = 107;
const int SIZE = 1000007;
const int INF = 1000000000;
int n, T, size, a[N];
LL dp[N][N];

int main()
{
#ifdef harhro94
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &T);
    FOR1(test, T)
    {
        scanf("%d%d", &size, &n);
        FOR(i, n)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int cnt;
        FOR(i, N)
        {
            FOR(j, N)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = size;
        FOR(i, n)
        {
            FOR(j, n)
            {
                LL cur = dp[i][j];
                if (cur == 0)
                {
                    continue;
                }
                if (cur > a[i])
                {
                    dp[i + 1][j] = max(dp[i + 1][j], cur + a[i]);
                }
                else
                {
                    dp[i + 1][j + 1] = max(dp[i + 1][j + 1], cur);
                    int t = 0;
                    if (cur != 1)
                    {
                        while (cur <= a[i])
                        {
                            cur += (cur - 1);
                            ++t;
                            dp[i][j + t] = max(dp[i][j + t], cur);
                        }
                    }
                }
            }
        }
        FOR(j, n+1)
        {
            if (dp[n][j] != 0)
            {
                cnt = j;
                break;
            }
        }
        printf("Case #%d: %d\n", test, cnt);
    }

#ifdef harhro94
    cerr << fixed << setprecision(3) << "\nExecution time = " << clock() / 1000.0 << "s\n";
#endif
    return 0;
}
