#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#include<cassert>
#include<algorithm>
#include<ctime>
#include<deque>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define sz(a) (int(a.size()))
#define step(i) ((i+1)&-(i+1))
#define maxn int(1e5)+15
#define all(c)  (c).begin(),(c).end()

using namespace std;
typedef long long ll;
typedef long double ld;
const int inf=1e9;

ll next(){
    char d;
    ll x=0;
    while(1){
        d=getchar();
        if(isdigit(d)){x=d-'0';break;}
    }
    while(1){
        d=getchar();
        if(!isdigit(d)){break;}
        x=x*10ll+d-'0';
    }
    return x;
}

void solve(){
    ll p,q;
    ll N=(1ll<<40ll);
    //char d;
    //scanf("%lld %c %lld",p,d,q);//cin>>p>>q;
    //cout<<p<<' '<<q<<endl;
    p=next();q=next();
    ll g=__gcd(p,q);
    p/=g;q/=g;
    if(N%q==0){
        g=N/q;
        p*=g;q*=g;
        int c=0;
        while(p>1){
            p/=2;
            c++;
        }
        cout<<40-c<<endl;
    }
    else cout<<"impossible\n";
}

int main(){
    freopen("in.txt","r",stdin);
    //freopen("seq1.out","w",stdout);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        cout<<"Case #"<<i<<": ";solve();
    }


    return 0;
}
