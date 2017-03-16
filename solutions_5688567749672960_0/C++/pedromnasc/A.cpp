#include <bits/stdc++.h>

#define MAX 1000010

using namespace std;

typedef long long int ll;

const ll INF = 1LL<<60;

int T;
ll N;
ll pd[MAX];

ll rev(ll x){
    ll r=0;
    while(x){
        r*=10;
        ll aux=x%10;
        r+=aux;
        x/=10;
    }
    return r;
}


int main(void){
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&T);
    for(int caso=1;caso<=T;caso++){
        scanf("%lld",&N);
        pd[N]=1;
        for(int n=N-1;n>=1;n--){
            ll a=pd[n+1]+1;
            ll b=INF;
            if(rev(n)>n && rev(n)<=N) b=pd[rev(n)]+1;
            pd[n]=min(a,b);
        }
        printf("Case #%d: %lld\n",caso,pd[1]);
    }
}
