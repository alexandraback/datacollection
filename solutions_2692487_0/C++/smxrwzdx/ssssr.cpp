#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[2000010],sum[200010],num[2000010];
int A[1101];
#define oo 10000010
int N;
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int i,j,k;
    int a,b,s;
    int l,r;
    int st;
    int T;
    scanf("%d",&T);
    int tt=0;
    while(T--)
    {tt++;
        scanf("%d%d",&st,&N);
        for(i=0;i<N;i++)
        {
            scanf("%d",&A[i]);
        }
        sort(A,A+N);
        for(i=0;i<N;i++) if(A[i]<st) st+=A[i];
        sum[0]=0;
        num[0]=0;
        j=0;
        for(i=1;i<=A[N-1]+1;i++)
        {
            num[i]=num[i-1];
            sum[i]=sum[i-1];
            while(i>A[j]&&j<N)
            {
                sum[i]+=A[j++];
                num[i]++;
            }
        }
        st=min(st,A[N-1]+1);
        for(i=st;i<=A[N-1]+1;i++) dp[i]=oo;
        dp[st]=0;
        s=oo;
        for(i=st;i<=A[N-1];i++)
        {
            r=min(i*2-1,A[N-1]+1);l=i;
            while(sum[r]-sum[l]>0)
            {
                a=r;
                r+=sum[r]-sum[l];
                r=min(r,A[N-1]+1);
                l=a;
            }
            dp[r]=min(dp[r],dp[i]+1);
            s=min(s,dp[i]+N-num[i]);
        }
        s=min(dp[A[N-1]+1],s);
        printf("Case #%d: %d\n",tt,s);
    }
    return 0;
}
