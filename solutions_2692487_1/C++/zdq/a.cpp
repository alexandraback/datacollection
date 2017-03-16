#include <cstdio>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int initS, n;
int d[101];

void init()
{
    scanf("%d%d", &initS, &n);
    for (int i=1; i<=n; i++)
        scanf("%d", &d[i]);
    sort(d+1, d+n+1);
}

int work()
{
    if (initS == 1)
        return n;
    int ans = n;
    int curS = initS;
    int curAdd = 0;
    for (int i=1; i<=n; i++)
    {
        ans = min(ans, curAdd + n-i+1);
        if (d[i] < curS)
        {
            curS += d[i];
        }
        else
        {
            while (d[i] >= curS)
            {
                curS = curS*2-1;
                curAdd++;
            }
            curS += d[i];
        }
    }
    ans = min(ans, curAdd);
    return ans;
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int tim=1; tim<=T; tim++)
    {
        init();
        printf("Case #%d: %d\n", tim, work());
    }
    return 0;
}
