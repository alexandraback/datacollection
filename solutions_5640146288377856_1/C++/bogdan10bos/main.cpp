#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

#define INF (1<<30)
#define mod 666013

using namespace std;
int n, m, k, cs, t, x;

int mincost(int n, int m, int k)
{
    if(k == 1)
        return n * m;
    int x = k + (m / k) * n;
    if(m % k == 0)
        x--;
    return x;


    if(m == k || k == 1)
        return m;
    x = k + m / k;
    if(m % k == 0)
        x--;
    return x;
}

int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        cs++;
        printf("Case #%d: ", cs);

        scanf("%d%d%d", &n, &m, &k);
        printf("%d\n", mincost(n, m, k));
    }
    return 0;
}
