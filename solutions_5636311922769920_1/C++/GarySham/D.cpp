#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<list>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define FIT(it,x) for(typeof(x.begin()) it=x.begin(); it!=x.end(); ++it)
#define CLR(i) memset(i,0,sizeof(i))
#define eps (1e-8)
#define feq(x,y) (fabs((x)-(y))<=eps)
#define fgt(x,y) (((x)-(y)) > eps)
#define flt(x,y) (((y)-(x)) > eps)
#define fgeq(x,y) (fgt(x,y) || feq(x,y))
#define fleq(x,y) (flt(x,y) || feq(x,y))
#define ll long long

ll ans[200];

int main(){
    int T; scanf("%d",&T);
    FOE(t,1,T){
        int K,C,S; scanf("%d%d%d",&K,&C,&S);
        if (C*S < K){
            printf("Case #%d: IMPOSSIBLE\n",t);
            continue;
        }

        int tar = 0;
        FOR(i,0,S){
            ll pos = 0;
            FOR(j,0,C){
                pos = pos * (ll)K + (ll)min(tar,K-1);
                ++tar;
            }
            ans[i] = pos;
        }
        printf("Case #%d:", t);
        FOR(i,0,S) printf(" %lld", ans[i]+1);
        puts("");
    }
    return 0;
}
