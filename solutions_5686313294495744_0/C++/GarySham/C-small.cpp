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

struct node{
    char x[25],y[25];

    node(){}

    void input(){
        scanf("%s%s",x,y);
    }
} a[20];

int T,N;
char ts[100];

bool fake[20];
int ans;

void gen(int n, int pos){
    if (pos >= n){
        bool ok = 1;
        int cnt = 0;
        FOR(i,0,N){
            if (!fake[i]) continue;

            ++cnt;
            bool found1 = 0, found2 = 0;
            FOR(j,0,N){
                if (!fake[j] && !strcmp(a[i].x, a[j].x)){
                    found1 = 1;
                    break;
                }
            }
            FOR(j,0,N){
                if (!fake[j] && !strcmp(a[i].y, a[j].y)){
                    found2 = 1;
                    break;
                }
            }
            if (!(found1 && found2)){
                ok = 0;
                break;
            }
        }
        if (ok) ans = max(ans, cnt);

        return;
    }

    fake[pos] = 0;
    gen(n,pos+1);
    fake[pos] = 1;
    gen(n,pos+1);
}

int main(){
    scanf("%d",&T);
    FOE(t,1,T){
        ans = 0;
        CLR(fake);

        scanf("%d",&N); gets(ts);
        FOR(i,0,N) a[i].input();
        gen(N,0);
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
