#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

void solve()
{
    int k, c, s;
    scanf("%d%d%d", &k, &c, &s);
    for (int i = 1; i <= s; i++)
        printf("%d%c", i, i == s ? '\n' : ' ');
}

int main()
{
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
