//Mitesh Agrawal
#include <bits/stdc++.h>
using namespace std;
 
#define gc getchar
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n)
#define pis(n) printf("%d ",n)
#define pll(n) printf("%lld",n)
#define plls(n) printf("%lld ",n)
#define plln(n) printf("%lld\n",n)
#define ps printf(" ")
#define pn printf("\n")
#define si(n) scanf("%lld",&n)
#define sii(n,m) scanf("%lld %lld",&n,&m)
#define siii(k,n,m) scanf("%d %d %d",&k,&n,&m)
#define rep(i,n) for(i=0;i<n;i++)
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>=a;i--)
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define ff first 
#define ss second
#define mod 1000000007
#define MAXN 100005 

ll arr[55][55];
ll b;

void print(ll n){
     ll i;
     fd(i,b-2,0){
          pll(n>>i & 1);
     }
     pis(0);
}

int main()
{
     freopen ("B-large (1).in","r",stdin); 
     freopen ("B-large (1).out","w",stdout); 
     ll i,j,m,q;
     si(q);
     for(ll qw=1;qw<=q;qw++){
          printf("Case #%lld: ",qw);
          sii(b,m);
          if(m<=(1ll<<(b-2)))
               printf("POSSIBLE\n");
          else{
               printf("IMPOSSIBLE\n");
               continue;
          }
          rep(i,b)
               fu(j,i+1,b-1)
                    arr[i][j]=1;

          if(m==(1ll<<(b-2))){
               rep(i,b)
                    arr[0][i]=1;
               arr[0][0]=0;
               fu(i,0,b-1){
                    rep(j,b){
                         pll(arr[i][j]);
                    }pn;
               }
          }

          else{
               print(m);
               pn;
               fu(i,1,b-1){
                    rep(j,b){
                         pll(arr[i][j]);
                    }pn;
               }
          }


     }

     return 0;
}      