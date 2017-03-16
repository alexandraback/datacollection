#include <cstdio>
#include <cstring>
using namespace std;

long long a[110], A[110], b[110], B[110], n, m, ans;

long long max(long long a, long long b){
	return (a > b ? a : b);
}

long long min(long long a, long long b){
	return (a < b ? a : b);
}

void dfs(long long d, long long s, long long end, long long cur)
{
    if (s + end <= ans) return;
    ans = max(ans, s);
    if (d == n + 1) return;
    dfs(d + 1, s, end - a[d], cur);
    long long aNow = a[d];
    for (long long i = cur; i <= m; ++i)
        if (A[d] == B[i])
        {
            long long delta = min(b[i], aNow);
            aNow -= delta;
            b[i] -= delta;
            s += delta;
            if (!b[i])
                dfs(d + 1, s, end - a[d], i + 1);
            else
                dfs(d + 1, s, end - a[d], i);
            b[i] += delta;
            if (!aNow) break;
        }
}

int main()
{
    freopen("Cs.in", "r", stdin);
    freopen("Cs.out", "w", stdout);
    long long T;
    scanf("%lld", &T);
    for (long long cs = 0; cs < T; ++cs)
    {
        ans = 0;
        scanf("%lld%lld", &n, &m);
        for (long long i = 1; i <= n; ++i)
            scanf("%lld%lld", &a[i], &A[i]);
        for (long long i = 1; i <= m; ++i)
            scanf("%lld%lld", &b[i], &B[i]);
        long long s = 0;
        for (long long i = 1; i <= n; ++i)
            s += a[i];
        dfs(1, 0, s, 1);
        printf("Case #%lld: %lld\n", cs + 1, ans);
    }
    return 0;
}
