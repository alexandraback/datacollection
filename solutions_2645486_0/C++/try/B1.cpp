#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAXN 10
using namespace std;

int v[MAXN+1];
int e,r,n,m;

void backtrack(int k,int p,int s)
{
    int i;
    if(k==n)
    {
        m=max(m,s);
        return;
    }
    for(i=0;i<=p;i++)
    {
        backtrack(k+1,min(p-i+r,e),s+i*v[k]);
    }
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0_1.out","w",stdout);
    int c,t,i;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        scanf("%d %d %d",&e,&r,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&v[i]);
        }
        m=0;
        backtrack(0,e,0);
        printf("Case #%d: %d\n",c+1,m);
    }
    return 0;
}
