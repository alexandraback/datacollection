#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
ll mpow(ll a, ll n,ll mod)
{ll ret=1;ll b=a;while(n) {if(n&1)
    ret=(ret*b)%mod;b=(b*b)%mod;n>>=1;}
return (ll)ret;
}
using namespace std;
#define sd(x) scanf("%d",&x)
#define pd(x) printf("%d",x)
#define mem(x,a) memset(x,a,sizeof(x))
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define N (int)5e3+5
using namespace std;
char a[8][8];
ll pow2[50];
void go(){
    pow2[0]=1;
    pow2[1]=2;
    for(int i=2;i<=49;i++){
        pow2[i]=(pow2[i-1]*(2ll));
    }
}
void solve(){
    ll n,m;
    cin>>n>>m;
    if(m>pow2[n-2]){
        printf("IMPOSSIBLE\n");
        return;
    }
    printf("POSSIBLE\n");
    mem(a,'0');
    for(int i=1;i<=n-1;i++){
        a[i][i+1]='1';
    }
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            a[i][j]='1';
        }
    }
    ll diff=(pow2[n-2])-m;
    for(ll i=0;i<=50;i++){
        if(diff&(1ll<<i)){
            for(int j=i+3;j<=n;j++){
                a[i+2][j]='0';
            }
            diff-=(1ll<<i);
            if(diff==0)
                break;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
int main(){
   freopen("input.IN","r",stdin);
   freopen("out.txt","w",stdout);
   go();
   int t=1;
   scanf("%d",&t);
   for(int i=1;i<=t;i++){
       printf("Case #%d: ",i);
       solve();
   }
   return 0;
}
