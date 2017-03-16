#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1050;

char S[N];

void solve(int cs)
{
    int n;
    scanf("%d", &n);
    scanf(" %s", S);
    int cur = 0;
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int add = max(0, i - cur);
        ans += add;
        cur += add + S[i] - '0';
    }
    printf("Case #%d: %d\n", cs, ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
        solve(i + 1);
    return 0;
}
