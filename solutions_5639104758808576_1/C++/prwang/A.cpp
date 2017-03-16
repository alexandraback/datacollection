#include <cstdio>
#include <cstring>

using namespace std;
const int maxn = 2333;
char pp[maxn];
inline int solve()
{
    int l, x(0), a(0); scanf("%d%s", &l, pp);
    for (int i = 0; i <= l; ++i)
    {
        if (x < i) a += i - x,  x = i;
        x += pp[i] - '0';
    }
    return a;
}
int main()
{
    int T; scanf("%d", &T);
    for (int tt = 1; tt <= T; ++tt)
        printf("Case #%d: %d\n", tt, solve());
}


