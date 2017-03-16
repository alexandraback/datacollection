#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s[10005];
int dp[10005];
int dpf[10005];
int a[10005];
int c[4][4]=
{
    {1,2,3,4},
    {2,-1,4,-3},
    {3,-4,-1,2},
    {4,3,-2,-1},
};

int trans(char ch)
{
    if (ch=='i') return 2;
    if (ch=='j') return 3;
    if (ch=='k') return 4;
}

int multi(int x,int y)
{
    int ret=c[abs(x)-1][abs(y)-1];
    if (x*y<0) return -ret;
    return ret;
}

int main()
{
    freopen("cs.in","r",stdin);
    freopen("cs.out","w",stdout);
    int T,i,j,n,x,l,cnt=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&l,&x);
        scanf("%s",s);
        for (i=0;i<x*l;i++)
        {
            a[i]=trans(s[i%l]);
        }
        dp[0]=a[0];
        for (i=1;i<x*l;i++)
        {
            dp[i]=multi(dp[i-1],a[i]);
          //  printf("%d..\n",dp[i]);
        }
        dpf[x*l-1]=a[x*l-1];
        for (i=x*l-2;i>=0;i--)
        {
            dpf[i]=multi(a[i],dpf[i+1]);
        }
        if (dp[x*l-1]!=-1)
        {
            printf("Case #%d: NO\n",cnt++);
            continue;
        }
        int frt=100005,tail=-1;
        for (i=0;i<x*l;i++)
        {
            if (dp[i]==2)
            {
                frt=i;
                break;
            }
        }
        for (i=x*l-1;i>=0;i--)
        {
            if (dp[i]==4)
            {
                tail=i;
                break;
            }
        }
    //    printf("%d...%d\n",frt,tail);
        if (frt<tail) printf("Case #%d: YES\n",cnt++);
        else printf("Case #%d: NO\n",cnt++);
    }
    return 0;
}
