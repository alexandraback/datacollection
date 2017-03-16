#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define maxn 100010
#define po 500
using namespace std;
struct attack
{
    int day;
    int l,r;
    int w;
}node[1010];
int num=0;
bool cmp(attack a,attack b)
{
    if(a.day==b.day)
    {
        return a.w<b.w;
    }
    return a.day<b.day;
}
int wall[2010];
int solve(int x,int y)
{
    int sum=0,i;
    for(i=x;i<=y;i++)
    {
        int l=node[i].l+po,r=node[i].r+po,w=node[i].w,tru=0;
        for(int j=2*l;j<=2*r;j++)
        {
            if(wall[j]<w)
            {
                tru=1;
                break;
            }
        }
        sum+=tru;
    }
    for(i=x;i<=y;i++)
    {
        int l=node[i].l+po,r=node[i].r+po,w=node[i].w;
        for(int j=2*l;j<=2*r;j++)
        {
            if(wall[j]<w)
            {
               wall[j]=w;
            }
        }
    }
    return sum;
}
int main()
{
    freopen("dd.txt","r",stdin);
    freopen("out.txt","w+",stdout);
    int ncase,time=0;
    scanf("%d",&ncase);
    while(ncase--)
    {
        num=0;
        memset(wall,0,sizeof(wall));
        printf("Case #%d: ",++time);
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int d,ni,l,r,w,dd,dlr,ds;
            scanf("%d%d%d%d%d%d%d%d",&d,&ni,&l,&r,&w,&dd,&dlr,&ds);
            node[num].day=d,node[num].l=l,node[num].r=r,node[num].w=w;
            num++;
            while(--ni)
            {
                node[num].day=node[num-1].day+dd;
                node[num].l=node[num-1].l+dlr;
                node[num].r=node[num-1].r+dlr;
                node[num].w=node[num-1].w+ds;
                num++;
            }
        }
        sort(node,node+num,cmp);
        int ans=0;
        int l=0,r=0;
        for(int i=1;i<num;i++)
        {
            if(node[i].day!=node[i-1].day)
            {
                ans+=solve(l,r);
                l=r=i;
            }
            else
            r++;
        }
        ans+=solve(l,r);
        printf("%d\n",ans);
    }
    return 0;
}
