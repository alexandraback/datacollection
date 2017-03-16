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
main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small.out","w",stdout);
    int T,Case=0,a,b,k,ans;
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d%d%d",&a,&b,&k);
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                int tmp=i&j;
                if(tmp<k)ans++;
            }
        }
        printf("Case #%d: %d\n",++Case,ans);
    }
}
