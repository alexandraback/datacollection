#include <cstdio>
#include <memory.h>
using namespace std;

const int N = 1000500;
int D[N];

int lpt = 0, rpt = 0;
int Q[N];

int rev(int x)
{
    int ans = 0;
    while (x > 0)
        ans = 10 * ans + (x % 10), x /= 10;
    return ans;
}

void solve(int cs)
{
    int n;
    scanf("%d", &n);
    memset(D, -1, sizeof(D));
    lpt = rpt = 0;
    Q[rpt++] = 1;
    D[1] = 1;
    int ans = -1;
    while (lpt != rpt)
    {
        int x = Q[lpt++];
        if (x == n)
        {
            ans = D[x];
            break;
        }
        if (x + 1 < N && D[x + 1] == -1)
        {
            D[x + 1] = D[x] + 1;
            Q[rpt++] = x + 1;
        }
        int r = rev(x);
        if (r < N && D[r] == -1)
        {
            D[r] = D[x] + 1;
            Q[rpt++] = r;
        }
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
