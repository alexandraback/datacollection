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

const long long MAXN = 10224;

long long t, n;
long long e, r, v[MAXN];
long long used[MAXN];

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("ss.in", "r", stdin);
    freopen("ss.out", "w", stdout);

    cin >> t;
    for (long long T = 1; T <= t; T++)
    {
        memset(used, 0, sizeof(used));
        cin >> e >> r >> n;
        for (long long i = 1; i <= n; i++)
            cin >> v[i];

        long long ans = v[1] * e;
        used[1] = e;

        for (long long i = 2; i <= n; i++)
        {
            long long toAdd = e - r;
            ans += v[i] * r;
            //msg(ans);
            used[i] = r;
            long long j = i - 1;
            while (v[i] > v[j] && toAdd > 0)
            {
                long long toDec = min(toAdd, used[j]);
                toAdd -= toDec;
                used[j] -= toDec;
                used[i] += toDec;
                ans += v[i] * toDec - v[j] * toDec;
                j--;
            }
        }

        printf("Case #%lld: %lld\n", T, ans);
    }

    return 0;
}
