#include <iostream>
#include<cstdio>
#define N 101
#define LL long long
using namespace std;

LL A[N],a[N],B[N],b[N];
LL C[4][N];
int main()
{
    int t,p,i,j,k,n,m;
    LL sum;
    LL ans;
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
    scanf("%d",&t);
    for(p=1;p<=t;p++)
    {
        scanf("%d%d",&n,&m);
        ans=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a[i],&A[i]);
            if(A[i]==A[i-1])
            {
                a[i-1]+=a[i];
                i--;
                n--;
            }
        }
        for(i=1;i<=m;i++)
        {
            scanf("%lld%lld",&b[i],&B[i]);
        }
        for(i=1;i<=n;i++)
            C[i][0]=0;
        for(j=1;j<=n;j++)
        {
            for(i=1;i<=m;i++)
            {
                C[j][i]=C[j][i-1];
                if(A[j]==B[i])
                {
                    C[j][i]+=b[i];
                }
            }
        }
        printf("Case #%d: ",p);
        if(n==1)
        {
            printf("%lld\n",min(a[1],C[1][m]));
        }
        else if(n==2)
        {
            ans=min(a[1],C[1][m]);
            sum=0;
            for(i=0;i<=m;i++)
            {
                for(j=i+1;j<=m;j++)
                {
                    sum = min(a[1],C[1][i]) + min(a[2],C[2][j]-C[2][i]);
                    if(ans<sum)
                        ans=sum;
                }

            }
            printf("%lld\n",ans);
        }
        else if(n==3)
        {
            ans=min(a[1],C[1][m]);
            sum=0;
            for(i=0;i<=m;i++)
            {
                for(j=1;j<=m;j++)
                {
                    for(k=1;k<=m;k++)
                    {
                        sum=min(a[1],C[1][i]);
                        if(j>i)
                            sum+=min(a[2],C[2][j]-C[2][i]);
                        if(k>j)
                            sum+=min(a[3],C[3][k]-C[3][j]);
                        if(ans<sum)
                            ans=sum;
                    }

                }
            }
            if(A[1]==A[3])
            {
                if(ans<min(a[1]+a[3],C[1][m]))
                    ans=min(a[1]+a[3],C[1][m]);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
