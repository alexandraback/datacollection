#include <iostream>
#include <stdio.h>
#include <algorithm>
struct node
{
    int data,num;
} v[10009];
int e,r,n,sum[10009],i,j,tep,cas,k;
long long tot;
using namespace std;
bool cmp(node x,node y)
{
    return x.data>y.data;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&cas);
    for (k=1; k<=cas; k++)
    {
        scanf("%d%d%d",&e,&r,&n);
        for (i=1; i<=n; i++)
        {
            scanf("%d",&v[i].data);
            v[i].num=i;
            sum[i]=e+r*(i);
        }
        sort(v+1,v+1+n,cmp);
        tot=0;
        for (i=1; i<=n; i++)
        {
            tep=min(e,sum[v[i].num]);
            tot+=tep*v[i].data;
            for (j=v[i].num+1; j<=n; j++)
                sum[j]=sum[j]-tep;
                for (j=1;j<=v[i].num-1;j++)
                sum[j]=min(sum[j],max
                           (sum[v[i].num]-tep,0));
        }
        printf("Case #%d: %I64d\n",k,tot);
    }
    return 0;
}
