#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<list>
using namespace std;
int b[3],a[3][35];
long long dp[35][8];
int main()
{
    freopen("B-large (1).in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    int ca=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0; i<3; ++i)
            scanf("%d",b+i);
        for (int i=32; i>=1; i--)
        {
            for(int j=0; j<3; ++j)
            {
                a[j][i]=b[j]%2;
                b[j]>>=1;
            }
        }
        dp[33][7]=1;
        for (int i=33; i>=1; i--)
        {
            for(int j=0; j<8; ++j)
            {
                int l=0;
                for(int k=0; k<3; ++k)
                    if(j&(1<<(2-k)))
                        l+=1-a[k][i-1]<<(2-k);
                dp[i-1][l]+=dp[i][j];
            }
            for(int q=0; q<2; ++q)
                for(int j=0; j<8; ++j)
                {
                    int l=0;
                    for(int k=0; k<3; ++k)
                        if(k!=q)
                        {
                            if(j&(1<<(2-k)))
                                l+=1-a[k][i-1]<<(2-k);
                        }
                        else
                        {
                            if(j&(1<<(2-k)))
                                l+=1<<(2-k);
                            else
                                l+=1-a[k][i-1]<<(2-k);
                        }
                    dp[i-1][l]+=dp[i][j];
                }
            for(int j=0; j<8; ++j)
            {
                int l=0;
                for(int k=0; k<3; ++k)
                    if(j&(1<<(2-k)))
                        l+=1<<(2-k);
                    else
                        l+=1-a[k][i-1]<<(2-k);
                dp[i-1][l]+=dp[i][j];
            }
        }
        printf("Case #%d: %I64d\n",++ca,dp[0][0]);
    }
}
