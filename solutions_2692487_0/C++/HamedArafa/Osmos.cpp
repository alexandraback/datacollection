#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int mincost (int,int);
int list [200];
int n;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T,mote;
    int t=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&mote,&n);
        for (int i=0;i<n;i++)
            scanf("%d",&list[i]);
        sort(list ,list+n);
        printf("Case #%d: %d\n",t,mincost(mote,0));
        t++;
    }

}
int mincost (int size ,int place)
{
    if (place==n)
        return 0;
    int a,b;
    if (size>list[place])
        return mincost(size+list[place],place+1);
    a=1<<30;
    b=1<<30;
    if (size!=1)
        a=mincost(size+size-1,place);
    b=mincost(size,place+1);
    return min(a,b)+1;

}
