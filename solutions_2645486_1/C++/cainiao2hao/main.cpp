#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <stack>
using namespace std;
#define N 10005
long long n, E, R, v[N], next[N];

int main()
{
    freopen("D:\\bdata.in", "r", stdin);
    freopen("D:\\bdata1.out", "w", stdout);
    long long cas, t = 0;
    scanf("%lld", &cas);
    while (cas--)
    {
        scanf("%lld %lld %lld", &E, &R, &n);
        for (long long i = 1; i <= n; i++)
            scanf("%lld", &v[i]);
        stack<long long> st;
        while(!st.empty())
            st.pop();
        memset(next, -1, sizeof (next));
        st.push(n);
        for (long long i = n - 1; i > 0; i--)
        {
            while (!st.empty() && v[st.top()] < v[i])
                st.pop();
            if (!st.empty())
                next[i] = st.top();
            st.push(i);
        }
        long long ans = 0;
        long long enr = E;
        if (R > E)R = E;
        for (long long i = 1; i <= n; i++)
        {
            if (next[i] == -1)
            {
                ans += enr * v[i];
                enr = R;
                continue;
            }
            long long step = next[i] - i;
            long long eat = E - step*R;
            if (eat < 0)
                eat = 0;
            long long add = enr - eat;
            if (add < 0)
            {
                enr += R;
                continue;
            }
            ans += add * v[i];
            enr = enr - add + R;
        }
        printf("Case #%lld: %lld\n",++t,ans);
    }
    return 0;
}