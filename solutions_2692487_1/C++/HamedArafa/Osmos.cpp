#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int mincost (int,int);
int list [200];
int Dp[102][1000002];
int n;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("newfile.out","w",stdout);
    int T,mote;
    int t=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&mote,&n);
        for (int i=0;i<n;i++)
            scanf("%d",&list[i]);
        sort(list ,list+n);

        memset(Dp,-1,sizeof Dp);

        printf("Case #%d: %d\n",t,mincost(mote,0));
        t++;
    }

}
int mincost (int size ,int place)
{
    if (place==n)             // base case
        return 0;

    if (size>1000000)
        size =1000001;

    if (Dp[place][size]!=-1)
        return Dp[place][size];

    if (size>list[place])              // no problem with it;
        return Dp[place][size]= mincost(size+list[place],place+1);

    int a,b;
    a=1<<30;
    b=1<<30;

    if (size!=1)
        a=mincost(size+size-1,place);

    b=mincost(size,place+1);

    return Dp[place][size]= min(a,b)+1;
}
