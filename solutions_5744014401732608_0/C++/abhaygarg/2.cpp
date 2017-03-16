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
int w[101],a[101][101];
int check(int n)
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
vector< pii >v;
int main()
{
    freopen("2.in","r",stdin);
    freopen("2-out.txt","w",stdout);
    int t,cs=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,i,j;
        scanf("%d %d",&n,&m);
        int k=(n*(n-1))/2;
        v.clear();
        for(i=1; i<=n; i++)
            for(j=i+1; j<=n; j++)
                v.pb(mp(i,j));
        for(i=1; i<(1<<k); i++)
        {
            for(j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    a[j][k]=0;
            for(j=0;j<k;j++)
                if((i>>j)&1)
                    a[v[j].f][v[j].s]=1;
            if(check(n)==m)
                break;
        }
        if(i==(1<<k))
            printf("Case #%d: IMPOSSIBLE\n",cs);
        else
        {
            printf("Case #%d: POSSIBLE\n",cs);
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                    printf("%d",a[i][j]);
                printf("\n");
            }
        }
        cs++;
    }
    return 0;
}

