#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
#define N 110
using namespace std;

double dp[N][N][N],sum[N][N];
double p[N];
int cnt[N];
char str[N];

int main()
{
    int t,ys=0;

    freopen("B-small-attempt0.in","r",stdin);
    freopen("dataB.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        int n,m,s;
        char temp[N];
        scanf("%d%d%d",&n,&m,&s);
        scanf("%s%s",temp,str+1);

        memset(cnt,0,sizeof(cnt));
        for (int i=0;i<n;i++)
            cnt[temp[i]-'A']++;
        for (int i=0;i<26;i++)
            p[i]=(double)cnt[i]/n;

        dp[0][0][0]=1.0;
        sum[0][0]=1.0;
        for (int i=1;i<=s+1;i++)
            for (int j=0;j<=i;j++)
            {
                for (int k=0;k<=m;k++)
                {
                    dp[i][j][k]=0.0;
                    if (k==0)
                    {
                        if (j>0) dp[i][j][k]+=dp[i-1][j-1][m]*(1.0-p[str[1]-'A']);
                        dp[i][j][k]+=sum[i-1][j]*(1.0-p[str[1]-'A']);
                    }
                    else if (k==1)
                    {
                        dp[i][j][k]+=dp[i-1][j][0]*p[str[1]-'A'];
                        if(j>0) dp[i][j][k]+=dp[i-1][j-1][m]*p[str[1]-'A'];
                    }
                    else
                    {
                        dp[i][j][k]+=dp[i-1][j][k-1]*p[str[k]-'A'];
                    }
                }

                sum[i][j]=0;
                for (int k=0;k<m;k++)
                    sum[i][j]+=dp[i][j][k];
            }

        //printf("%.3f\n",dp[1][0][0]);
        //printf("%.3f\n",dp[1][0][1]);
        //printf("%.3f\n",dp[2][0][1]);
        int tot=0;
        double exp=0;
        for (int i=0;i<=s;i++)
        {
            double temp=dp[s+1][i][0]+dp[s+1][i][1];
            if (temp>1e-10)
                tot=max(tot,i);
            exp+=temp*i;
        }
        double ans=tot-exp;
        printf("Case #%d: %.8f\n",++ys,ans);
    }

    return 0;
}

