#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=105;

int n,m;

ll check(ll x) {
    for(ll i=2; i*i<=x; i++)
        if(x%i==0LL)return i;
    return 0;
}

int cret;

ll cal(ll mask,int b) {
    ll ret=0;
    for(int i=0; i<n; i++)
        ret=ret*b+((mask&(1LL<<i))>0LL);
    return ret;
}

ll ans[maxn];
bool f(ll mask) {
    for(int i=2; i<=10; i++) {
        ll x=cal(mask,i);
        ll dx=check(x);
        if(dx==0LL)return 0;
        ans[i]=dx;
    }
    for(int i=0; i<n; i++)printf("%d",(mask&(1LL<<i))>0LL);
    for(int i=2; i<=10; i++)printf(" %lld",ans[i]);
    printf("\n");
    return 1;
}

void dfs(ll mask,int pos) {
    if(cret==m)return;
    if(pos==n-1) {
        if(f(mask))cret++;
        return;
    }
    dfs(mask,pos+1);
    dfs(mask|(1LL<<pos),pos+1);
}

int main() {
    //freopen("in.cpp","r",stdin);
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out","w",stdout);
    int ncase=0;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        printf("Case #%d:\n",++ncase);
        dfs(1LL|(1LL<<(n-1)),1);
    }
    return 0;
}
