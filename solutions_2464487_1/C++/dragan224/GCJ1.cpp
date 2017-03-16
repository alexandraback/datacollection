#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#define msg(var) cerr << #var << " = " << var << endl
using namespace std;

typedef long double ll;

int t;
ll r, p;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("ss.in", "r", stdin);
    freopen("ss.out", "w", stdout);

    cin >> t;
    for (int T = 1; T <= t; T++)
    {
        cin >> r >> p;
        long long ans = 0;

        ll lo = 1, hi = (int)(1e18), mid;
        ll sum;

        while (lo < hi)
        {
            mid = floor((lo + hi) / 2);
            sum = mid * r * 2 + mid + mid * 2 * (mid - 1);
            //msg(mid); msg(sum);
            if (sum >= p) hi = mid;
            else lo = mid + 1;
        }
        sum = hi * r * 2 + hi + hi * 2 * (hi - 1);
        if (sum == p)
            ans = (long long)(floor(hi));
        else
            ans = (long long)(floor(hi)) - 1;
        printf("Case #%d: %lld\n", T, ans);
    }

    return 0;
}
