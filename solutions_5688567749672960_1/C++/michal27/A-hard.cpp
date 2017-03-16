#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int,int> pii;

ll otoc(ll a) {
    vector<ll> A;
    while(a>0) {A.push_back(a%10); a/=10;}
    ll res=0;
    For(i,A.size()) {res*=10; res+=A[i];}
    return res;
}

ll sprav(ll f, ll t) {
    //printf("%lld %lld\n",f,t);
    if(f==t) return 0;
    if(t%10==0) return 1+sprav(f,t-1);
    vector<ll> F,T;
    ll x=f;
    while(x>0) {F.push_back(x%10); x/=10;}
    x=t;
    while(x>0) {T.push_back(x%10); x/=10;}
    int poc=F.size()/2;
    //reverse(F.begin(),F.end());
    reverse(T.begin(),T.end());
    For(i,poc) F[i]=T[i];
    reverse(F.begin(),F.end());
    ll pom=0;
    For(i,F.size()) {pom*=10; pom+=F[i];}
    ll res=pom-f;
    reverse(F.begin(),F.end());
    ll pom1=0;
    For(i,F.size()) {pom1*=10; pom1+=F[i];}
    if(pom!=pom1) res++;
    res+=t-pom1;
    //printf("%lld %lld: %lld\n",f,t,res);
    return res;
}

void solve(int p1) {
    ll n;
    scanf("%lld",&n);
    ll m=1;
    ll res=1;
    while(m*10<n) {res+=sprav(m,10*m); m*=10;}
    res+=sprav(m,n);
    printf("Case #%d: %lld\n",p1,res);
}

int main() {
    int t;
    scanf("%d",&t);
    For(i,t) solve(i+1);
}
