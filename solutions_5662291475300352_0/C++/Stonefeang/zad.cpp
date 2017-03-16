#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;

int t;
int n;

int wyn;

long long deg[5];
long long pre[5];
long long il[5];

int main()
{
    scanf("%d", &t);
    for (int h=1; h<=t; h++)
    {
        scanf("%d", &n);
        for (int i=1; i<=n; i++)
        {
            scanf("%lld%lld%lld", &deg[i], &il[i], &pre[i]);
        }
        wyn=0;
        if (n==2 && ( ((360-deg[1])*pre[1]>=(720-deg[2])*pre[2]) || ((360-deg[2])*pre[2]>=(720-deg[1])*pre[1]) ))
        {
            wyn=1;
        }
        printf("Case #%d: %d\n", h, wyn);
    }
    return 0;
}

