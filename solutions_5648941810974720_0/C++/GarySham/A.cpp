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

int N,T;
char s[5000];
int dig[30];
int ans[10];

char cc[10][6] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

char tar[15] = "ZOWHRFXSGN";
int seq[10] = {
    0,2,8,6,7,3,4,5,1,9
};

int main(){
    scanf("%d",&T); gets(s);
    FOE(t,1,T){
        CLR(dig); CLR(ans);

        gets(s);
        N = strlen(s);

        FOR(x,0,10){
            int dd = seq[x];
            char tt = tar[dd];
            int len = strlen(cc[dd]);
            FOR(i,0,N){
                if (s[i] == tt){
                   ++ans[dd];
                   FOR(j,0,len) {
                       FOR(k,0,N){
                           if (s[k] == cc[dd][j]){
                               s[k] = '_';
                               break;
                           }
                       }
                   }
                }
            }
        }
        printf("Case #%d: ", t);
        FOR(i,0,10){
            FOR(j,0,ans[i]) printf("%d", i);
        }
        puts("");
    }
    return 0;
}
