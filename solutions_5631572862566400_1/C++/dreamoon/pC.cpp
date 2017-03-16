#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e3+10;
int p[SIZE],tt,used[SIZE],pos[SIZE];
VI e[SIZE];
int f(int x,int lt){
    int v=1;
    REP(i,SZ(e[x]))
        if(e[x][i]!=lt)v=max(v,f(e[x][i],x)+1);
    return v;
}
int main(){
    CASET{
        int an=0;
        DRI(n);
        REPP(i,1,n+1)e[i].clear();
        REPP(i,1,n+1){
            RI(p[i]);
            e[p[i]].PB(i);
        }
        REPP(i,1,n+1){
            int now=i;
            tt++;
            REPP(j,1,n+5){
                if(used[now]!=tt){
                    used[now]=tt;
                    pos[now]=j;
                }
                else{
                    an=max(an,j-pos[now]);
                    break;
                }
                now=p[now];
            }
        }
        int two_case=0;
        REPP(i,1,n+1){
            if(i==p[p[i]]&&i<p[i]){
                two_case+=f(i,p[i])+f(p[i],i);
            }
        }
        an=max(an,two_case);
        printf("Case #%d: %d\n",case_n++,an);
        if(an==2){
            REPP(i,1,n+1)fprintf(stderr," %d",p[i]);
            fprintf(stderr,"\n");
            return 0;
        }
    }
    return 0;
}
