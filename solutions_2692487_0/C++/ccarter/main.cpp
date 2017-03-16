#include <iostream>
#define min(x,y) (((x)<(y))?(x):(y))
using namespace std;
int mote[100010];
int dp[102][100010];
int set(int x,int y,int n)
{
    if (y>=100001) y=100001;
    if (dp[x][y]==-1) dp[x][y]=n;
    else dp[x][y]=min(dp[x][y],n);
}
int calc(int a,int b, int r[])
{
    int cnt=0;
    //printf("#\n");
    while (a<=b)
    {
        a+=a-1;
        cnt++;
    }
    r[0]=cnt;
    r[1]=a;
}
int main()
{

    int tt,ri=1;
    int r[2];
    scanf("%d",&tt);
    while (tt--)
    {

        int a,n;
        scanf("%d %d",&a,&n);

        for (int i=1;i<=n;i++)
            scanf("%d",&mote[i]);
        sort(mote+1,mote+n+1);
        printf("Case #%d: ",ri++);
        if (a==1) {printf("%d\n",n);continue;}
        //printf("!\n");
        memset(dp,-1,sizeof(dp));
        dp[0][a]=0;
        for (int i=0;i<=n;i++)
        {
            for (int j=100001;j>=2;j--)
            {
                if (dp[i][j]==-1) continue;
                if (j>mote[i]) set(i+1,j+mote[i],dp[i][j]);
                else
                {
                    calc(j,mote[i],r);
                    set(i+1,r[1]+mote[i],dp[i][j]+r[0]);
                    set(i+1,j,dp[i][j]+1);
                }
                //printf("%d %d\n",i,j);
            }
        }
        //printf("!\n");
        int ans=10000;
        for (int i=1;i<=100001;i++)
        {
            if (dp[n+1][i]!=-1 && dp[n+1][i]<ans) {ans=dp[n+1][i];}
        }
        //printf("!\n");
        printf("%d\n",ans);
    }
    return 0;
}
