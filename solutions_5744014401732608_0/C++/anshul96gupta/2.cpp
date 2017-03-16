#include<stdio.h>
using namespace std;
int p[55][55];
long long power(int n,int r)
{
    if(r==0) return 1;
    if(r%2==0)
    {
        long long y=power(n,r/2);
        return y*y;
    }
    return n*power(n,r-1);
}
int main()
{
     //   freopen("inputb2.in","r",stdin);
   // freopen("outputb2.txt","w",stdout);
    long long t=0,i,j;
    scanf("%lld",&t);
    long long l=0;
    while(l<t)
    {
        l++;
        long long n,m;
        scanf("%lld%lld",&n,&m);
        if(m>power(2,n-2))
        {
            printf("Case #%lld: IMPOSSIBLE\n",l);
        }
        else
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    p[i][j]=0;
                }
            }
            printf("Case #%lld: POSSIBLE\n",l);
            long long tmp=n-2;
            p[0][n-1]=1;
            j=1;
            while(tmp--)
            {
                p[0][j]=1;
                p[j][n-1]=1;
                j++;
            }
            long long wt;
            if(m>=n)
            {
                tmp=0;
                {
                    wt=1;
                    for(i=2;i<n-1;i++)
                    {
                        for(j=i+1;j<n;j++)
                        {
                            p[i][j]=1;
                            tmp+=wt;
                            if(tmp+n-1==m) break;
                        }
                        wt*=2;
                    }
                }
            }
            for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d",p[i][j]);
            }
            printf("\n");
        }
        }

    }
    return 0;
}
