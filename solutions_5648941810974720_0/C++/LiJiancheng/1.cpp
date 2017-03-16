#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 2005
char s[10][6] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR",
    "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
char a[N];
int f[256], ans[11];
int n;

void check(int x, char c)
{
    if (f[c] > 0)
    {
        int w = f[c];
        ans[x] += w;
        n -= w * strlen(s[x]);
        for (int i = 0; i < strlen(s[x]); ++i)
            f[s[x][i]] -= w;
    }
}

void solve()
{
    scanf("%s", a);
    n = strlen(a);
    memset(f, 0, sizeof(f));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; ++i)
        ++f[a[i]];
    check(0, 'Z');
    check(2, 'W');
    check(4, 'U');
    check(6, 'X');
    check(8, 'G');
    check(1, 'O');
    check(3, 'T');
    check(5, 'F');
    check(7, 'S');
    check(9, 'I');
    for (int i = 0; i <= 9; ++i)
        if (ans[i])
            for (int j = 0; j < ans[i]; ++j)
                printf("%d", i);
    puts("");
}

int main()
{
    int t;
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &t);
    for (int tt = 1; tt <= t; ++tt)
    {
        printf("Case #%d: ", tt);
        solve();
    }
    return 0;
}