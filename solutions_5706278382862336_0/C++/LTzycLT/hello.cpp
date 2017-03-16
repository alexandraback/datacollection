#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<queue>
#define MP(x,y) make_pair(x,y)
#define clr(x,y) memset(x,y,sizeof(x))
#define forn(i,n) for(int i=0;i<n;i++)
#define sqr(x) ((x)*(x))
#define MAX(a,b) if(a<b) a=b;
#define ll long long
using namespace std;

ll p,q;
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main() {
    freopen("/home/zyc/Downloads/in","r",stdin);
    freopen("/home/zyc/Downloads/out","w",stdout);
//    freopen("/home/zyc/Documents/Code/cpp/in","r",stdin);
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%lld/%lld",&p,&q);
        ll _gcd=gcd(p,q);
        q/=_gcd;
        p/=_gcd;
        int idx=0;
        while(p<q){
            p<<=1;
            idx++;
        }
        ll a=p-q,b=q;
        _gcd = gcd(a,b);
        a/=_gcd;
        b/=_gcd;
        int op = 0;
        while(b%2==0){
            b/=2;
            op++;
        }
        printf("Case #%d: ",++cas);
        if(b!=1 || idx+op>40) puts("impossible");
        else printf("%d\n",idx);
    }
    return 0;
}

