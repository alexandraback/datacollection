#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define REP(i, l, n) for(int i = l;i < int(n);++i)
const int N = 200;
int val[N];

bool judge(int n, int x, int now, double tar, double per)
{
    double res = 0;
    REP(i, 0, n)
    {
        if(i == now) continue;
        res += max(0.0, (tar - val[i]) / x);
    }
    return res > per;
}
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int t, n, x;
    scanf("%d", &t);
    REP(cas, 0, t)
    {
        scanf("%d", &n);
        vector<double> ans(n);
        REP(i, 0, n) scanf("%d", val + i);
        x = accumulate(val, val + n, 0);
        REP(i, 0, n)
        {
            double lo = 0, hi = 1, mid;
            REP(k, 0, N)
            {
                mid = (lo + hi) / 2;
                if(judge(n, x, i, val[i] + x * mid, 1 - mid))
                    hi = mid;
                else
                    lo = mid;
            }
            ans[i] = mid;
        }
        printf("Case #%d:", cas + 1);
        REP(j, 0, n) printf(" %.06f", ans[j] * 100);
        puts("");
    }
    return 0;
}
