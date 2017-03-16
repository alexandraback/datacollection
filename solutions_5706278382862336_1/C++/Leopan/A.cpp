#include <bits/stdc++.h>
#define mpr std::make_pair
#define lg std::__lg
#define X first
#define Y second
#define mst(x) memset(x,0,sizeof(x))
#define mst1(x) memset(x,-1,sizeof(x))
#define RI(n) scanf("%d",&n);
#define RI2(a,b) scanf("%d%d",&a,&b);
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
typedef long long LL;
typedef double LD;
template<class T>inline void maz(T &a,T b){if(a<b)a=b;}
template<class T>inline void miz(T &a,T b){if(a>b)a=b;}
template<class T>inline T abs(T a){return a>0?a:-a;}
using namespace std;
LL gcd(LL a,LL b){
    LL c;
    if(b==0)return a;
    while(a%b){
        c=a%b;
        a=b;
        b=c;
    }
    return b;
}
bool check(LL a){
    while(a%2==0){
        a/=2;
    }
    if(a==1)return 1;
    return 0;
}
main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,Case=0;
    long long p,q;
    int ans;
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%lld/%lld",&p,&q);
        LL g=gcd(p,q);
        p/=g,q/=g;
        printf("Case #%d: ",++Case);
        if(!check(q))puts("impossible");
        else{
            while(q%2==0){
                ans++;
                q/=2;
            if(p>=q)break;
            }
            printf("%d\n",ans);
        }
    }
}
