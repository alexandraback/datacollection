#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1050;

int A[N];

void solve(int cs)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    int ans = 1000;
    for (int t = 1; t <= 1000; t++)
    {
        int sp = 0;
        for (int i = 0; i < n; i++)
            sp += (A[i] - 1) / t;
        ans = min(ans, sp + t);
    }
    printf("Case #%d: %d\n", cs, ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i + 1);
}
