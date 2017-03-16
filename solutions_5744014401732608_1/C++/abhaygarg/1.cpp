#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define pil pair<int,ll>
#define pli pair<ll,int>
ll p[200];
int a[200][200];
ll w[201];
ll check(int n)
{
    w[1]=1;
    int i,j;
    for(i=2;i<=n;i++)
        w[i]=0;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
            if(a[i][j])
                w[j]+=w[i];
    }
    return w[n];
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1-out-1.txt","w",stdout);
    int t,cs=1;
    p[0]=1LL;
    for(int i=1; i<=70; i++)
        p[i]=p[i-1]*2LL;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,n,ans;
        ll m;
        scanf("%d %lld",&n,&m);
        int k=(n-2);
        if(m>p[k])
            printf("Case #%d: IMPOSSIBLE\n",cs);
        else
        {
            if(m==p[k])
            {
                for(i=1;i<=n;i++)
                    for(j=1;j<=n;j++)
                        a[i][j]=0;
                for(i=1; i<=n; i++)
                    for(j=i+1; j<=n; j++)
                        a[i][j]=1;
            }
            else if(m==1)
            {
                for(i=1;i<=n;i++)
                    for(j=1;j<=n;j++)
                        a[i][j]=0;
                a[1][n]=1;
            }
            else
            {
                for(i=0; i<=n; i++)
                    for(j=0; j<=n; j++)
                        a[i][j]=0;
                for(i=0;;i++)
                    if(p[i]>m)
                        break;
                i--;
                for(j=1;j<=i+2;j++)
                {
                    for(int l=j+1;l<=i+2;l++)
                        a[j][l]=1;
                }
                j=2;
                for(int l=0;l<=i;l++,j++)
                {
                    if((m>>l)&1)
                        a[j][n]=1;
                }
            }
            printf("Case #%d: POSSIBLE\n",cs);
            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                    printf("%d",a[i][j]);
                printf("\n");
            }
            assert(check(n)==m);
        }
        cs++;
    }
    return 0;
}
