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

int a1[10], a2[10];
int ans1[100][5], ans2[100][5];
int dig[100];

void gen(int a[], int n, int ans[][5], int &cnt, int pos, int cur){
    if (cnt >= 30) return;
    if (cur == 5){
       ++cnt;
       FOR(i,0,5) ans[cnt][i] = ans[cnt-1][i];
       return;
    }

    FOR(i,pos,n){
        ans[cnt][cur] = a[i];
        gen(a,n,ans,cnt,i+1,cur+1);

        if (cnt >= 30) return;
    }
}

int main(){
    int T; scanf("%d",&T);
    FOE(t,1,T){
        int N,J; scanf("%d%d",&N,&J);
        int ba;
        if (N == 16) ba = 7; else ba = 10;
        FOR(i,0,ba) a1[i] = i*2 + 1;
        FOR(i,0,ba) a2[i] = i*2 + 2;

        int cnt1 = 0, cnt2 = 0;
        gen(a1,ba,ans1,cnt1,0,0);
        gen(a2,ba,ans2,cnt2,0,0);

        printf("Case #%d:\n",t);

        int cc = 0;
        FOR(i,0,cnt1){
            if (cc >= J) break;
            FOR(j,0,cnt2){
                if (cc >= J) break;
                CLR(dig);
                dig[0] = dig[N-1] = 1;
                FOR(x,0,5) dig[ans1[i][x]] = dig[ans2[j][x]] = 1;
                ++cc;

                FOR(x,0,N) printf("%d",dig[x]);
                FOE(x,2,10){
                    if (x == 3 || x == 9) printf(" 2");
                    else if (x == 6) printf(" 7");
                    else printf(" 3");
                }
                puts("");
            }
        }
    }
    return 0;
}
