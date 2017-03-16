#pragma comment(linker, ”/STACK:56777216“)
#define _USE_MATH_DEFINES
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <cstring>
#include <cmath>
#include <queue>
#include <functional>
#include <cstdio>
#include <stack>

#define mp make_pair
#define mt(x,y,z) mp((x), mp((y), (z)))
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

// globals starts here

const int MAX_N = 1000050;

ll dp[MAX_N];

ll rev(ll x)
{
    ll res = 0;
    while (x % 10 == 0)
    {
        return -1;
    }

    while (x > 0)
    {
        ll d = x % 10;
        res = res * 10 + d;
        x /= 10;
    }
    return res;
}

void f(ll n)
{
    stack<ll> st;
    st.push(n);

    while (!st.empty())
    {
        ll cur = st.top();
        
        if (dp[n] != -1)
        {
            st.pop();
            continue;
        }

        if (cur == 1)
        {
            st.pop();
            dp[cur] = 1;
            continue;
        }

        ll r1 = 1e9;
        if (dp[cur - 1] == -1)
        {
            st.push(cur - 1);
            continue;
        }
        else
        {
            r1 = dp[cur - 1];
        }

        ll rn = rev(cur);
        ll r2 = 1e9;
        if (rn != -1 && rn < cur)
        {
            if (dp[rn] == -1)
            {
                st.push(rn);
                continue;
            }
            else
            {
                r2 = dp[rn];
            }
        }

        dp[cur] = min(r1, r2) + 1;
        st.pop();
    }
}

int main()
{
#ifdef DEBUGAGA
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
#elif defined(CONTEST)
    freopen(CONTEST ".in", "r", stdin);
    freopen(CONTEST ".out", "w", stdout);
#endif

    fill(dp, dp + MAX_N, -1);
    f(1000000);

    int tests;
    cin >> tests;
    for (int tc = 0; tc < tests; ++tc)
    {
        int n;
        cin >> n;

        printf("Case #%d: %d\n", tc + 1, dp[n]);
    }

    return 0;
}