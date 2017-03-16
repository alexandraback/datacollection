#include <cstdio>
#include <iostream>
#define MAXB 32
using namespace std;

long long dp[MAXB+5][8];
int b[3][MAXB+5];
int x[3];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int c,t,i,j,k,l,r;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        memset(dp,0,sizeof(dp));
        for(i=0;i<3;i++)
        {
            scanf("%d",&x[i]);
        }
        for(i=MAXB;i>0;i--)
        {
            for(j=0;j<3;j++)
            {
                b[j][i]=x[j]&1;
                x[j]=x[j]>>1;
            }
        }
        dp[MAXB+1][7]=1;
        for(i=MAXB+1;i>0;i--)
        {
            for(j=0;j<8;j++)
            {
                l=0;
                for(k=0;k<3;k++)
                {
                    if((j&(1<<(2-k)))!=0)
                    {
                        l=l+((b[k][i-1]^1)<<(2-k));
                    }
                }
                dp[i-1][l]=dp[i-1][l]+dp[i][j];
            }
            for(r=0;r<2;r++)
            {
                for(j=0;j<8;j++)
                {
                    l=0;
                    for(k=0;k<3;k++)
                    {
                        if(k!=r)
                        {
                            if((j&(1<<(2-k)))!=0)
                            {
                                l=l+((b[k][i-1]^1)<<(2-k));
                            }
                        }
                        else
                        {
                            if((j&(1<<(2-k)))!=0)
                            {
                                l=l+(1<<(2-k));
                            }
                            else
                            {
                                l=l+((b[k][i-1]^1)<<(2-k));
                            }
                        }
                    }
                    dp[i-1][l]=dp[i-1][l]+dp[i][j];
                }
            }
            for(j=0;j<8;j++)
            {
                l=0;
                for(k=0;k<3;k++)
                {
                    if((j&(1<<(2-k)))!=0)
                    {
                        l=l+(1<<(2-k));
                    }
                    else
                    {
                        l=l+((b[k][i-1]^1)<<(2-k));
                    }
                }
                dp[i-1][l]=dp[i-1][l]+dp[i][j];
            }
        }
        printf("Case #%d: %I64d\n",c+1,dp[0][0]);
    }
}
