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

LD dp[407][407];
int T, n, x, y;

int main()
{
#ifdef harhro94
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> T;
    FOR1(test, T)
    {
        cin >> n >> x >> y;
        int sum = 0;
        int cur = 0;
        int rank = 0;
        while (sum + cur + cur + 1 <= n)
        {
            sum += cur + cur + 1;
            rank++;
            cur += 2;
        }
        n -= sum;
        x = abs(x);
        y = abs(y);
        cout << "Case #" << test << ": ";
        if (x + y <= 2 * rank - 2)
        {
            cout << fixed << setprecision(8) << 1.0 << endl;
            continue;
        }
        if (n == 0 || x == 0 ||  x + y > 2 * rank)
        {
            cout << fixed << setprecision(8) << 0.0 << endl;
            continue;
        }
        int need = y + 1;
        int rest =  n - need;
        int can = 2 * rank;
        if (abs(need - rest) > 200)
        {
            cout << fixed << setprecision(8) << 0.0 << endl;
            continue;
        }
        if (n == 2 * can)
        {
            cout << fixed << setprecision(8) << 1.0 << endl;
            continue;
        }
        FOR(i, 407)
        {
            FOR(j, 407)
            {
                dp[i][j] = 0.0;
            }
        }
        dp[0][0] = 1.0;
        FOR1(i, n)
        {
            FOR(j, can + 1)
            {
                int ot = i - j;
                if (ot < 0 || ot > can)
                {
                    continue;
                }
                if (ot == can)
                {
                    dp[i][j] += 0.5 * dp[i - 1][j];
                    if (j != 0)
                    {
                        dp[i][j] += dp[i - 1][j - 1];
                    }
                }
                else if (j == can)
                {
                    dp[i][j] += 0.5 * dp[i - 1][j - 1];
                    dp[i][j] += dp[i - 1][j];
                }
                else
                {
                    if (j == 0)
                    {
                        dp[i][j] = 0.5 * dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = 0.5 * (dp[i - 1][j - 1] + dp[i - 1][j]);
                    }
                }
            }
        }
        LD ans = 0.0;
        FORA(i, need, can)
        {
            ans += dp[n][i];
        }
        cout << fixed << setprecision(8) << ans << endl;
    }

#ifdef harhro94
    cerr << fixed << setprecision(3) << "\nExecution time = " << clock() / 1000.0 << "s\n";
#endif
    return 0;
}
