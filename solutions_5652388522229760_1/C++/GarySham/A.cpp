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

bool a[15];

int main(){
    int T; scanf("%d",&T);
    FOE(t,1,T){
        ll N; scanf("%lld",&N);
        if (N == 0ll){
            printf("Case #%d: INSOMNIA\n", t);
            continue;
        }
        CLR(a);
        int cnt = 0;
        ll N2 = N;
        while (1){
            ll x=N2;
            while (x){
                int tar = x%10;
                if (a[tar] == 0) ++cnt,a[tar]=1;
                x/=10;
            }
            if (cnt == 10) break;
            N2 += N;
        }
        printf("Case #%d: %lld\n",t,N2);
    }
    return 0;
}
