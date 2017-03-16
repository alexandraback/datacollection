#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f first
#define s second
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define CLR(x)  memset(x,0,sizeof(x))
#define RESET(x,a) memset(x,a,sizeof(x))
#define pi pair<int,int>
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<">value ("<<#x<<") : "<<x<<endl;

int mat[60][60];

int main()
{
    freopen("2.in","r",stdin);
    freopen("B-out.txt","w",stdout);
    int tt,t,j,n,i;
    ll m;
    si(tt);
    for(t=1;t<=tt;t++)
    {
        si(n);
        sl(m);
        printf("Case #%d: ",t);
        CLR(mat);
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n-1;j++)
                mat[i][j]=1;
        }
        ll lim=(1LL<<(ll)(n-2));
        if(lim<m)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(i=n-2;i>0;i--)
        {
            ll tmp=(1LL<<(ll)(i-1));
            if(m&tmp)
            {
                m-=tmp;
                mat[i][n-1]=1;
            }
        }
        if(m==1)
            mat[0][n-1]=1;
        printf("POSSIBLE\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%d",mat[i][j]);
            printf("\n");
        }
    }
    return 0;
}


