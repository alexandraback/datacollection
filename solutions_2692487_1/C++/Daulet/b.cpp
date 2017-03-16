#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

int a[200], d[200], p[200], n;

int go(int *a, int v, int A, int k)
{
    if (v == n+1) return k;
    int ret = 1<<30;
    if (a[v] < A)
        ret = go(a, v+1, A+a[v], k);
    else {
        ret = go(a, v+1, A, k+1);
        while (A != 1 && a[v] >= A) {
            A += A-1;
            k++;
        }
        if (A != 1)
            ret = min(ret, go(a, v+1, A+a[v], k));
    }
    return ret;
}

int solve(int A, int *a, int n)
{
    return go(a, 1, A, 0);
}

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int T;
    cin >> T;
    int A;
    for (int t = 1; t <= T; ++t) {
        scanf("%d%d", &A, &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        sort(a+1, a+1+n);
        printf("Case #%d: %d\n", t, solve(A, a, n));
    }

    return 0;
}
