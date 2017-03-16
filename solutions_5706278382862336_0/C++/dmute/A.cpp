#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

long long p,q;
char c;
typedef long long ll;
ll gcd(ll a, ll b){ return b==0?a:gcd(b,a%b);}
bool check(ll q){
     ll t = 1;
     while (t <= q)
        if (t == q) return true;
        else t *= 2ll;
     return false;
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int tst;
    scanf("%d",&tst);
    for (int t = 1; t <= tst; t ++){
        scanf("%lld%c%lld",&p,&c,&q);
        ll g = gcd(p,q);
        if (g != 0) p /= g, q /= g;
        if (!check(q)) printf("Case #%d: impossible\n", t);
        else{
                int ans = 0;
                ll mi=1;
                while (q > mi * p) mi*=2ll, ans++;
                printf("Case #%d: %d\n",t,ans);
             }
    }
  //  system("pause");
    return 0;
} 
