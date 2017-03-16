#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int p[1<<10];
int n,m;

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int c,t,i,j,s,r;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        scanf("%d",&n);
        m=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&p[i]);
            m=max(m,p[i]);
        }
        r=m;
        for(j=1;j<=m;j++)
        {
            s=0;
            for(i=1;i<=n;i++)
            {
                s=s+(p[i]-1)/j;
            }
            r=min(r,s+j);
        }
        printf("Case #%d: %d\n",c+1,r);
    }
    return 0;
}
