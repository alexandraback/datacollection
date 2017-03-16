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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int get(char c){
    if(c=='i')return 2;
    if(c=='j')return 3;
    return 4;
}
char s[10010];
int table[4][4]={{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};
int mul(int x,int y){
    int res=1;
    if(x<0){res=-res;x=-x;}
    if(y<0){res=-res;y=-y;}
    res*=table[x-1][y-1];
    return res;
}
int main(){
    CASET{
        DRII(L,X);
        RS(s);
        int now=1;
        int it=2;
        bool suc=0;
        REP(i,X){
            REP(j,L){
                int me=get(s[j]);
                now=mul(now,me);
                if(now==it){
                    now=1;
                    it++;
                    if(it==4){
                        suc=1;
                        break;
                    }
                }
            }
            if(suc)break;
        }
        int xd=1;
        REP(i,X)REP(j,L){xd=mul(xd,get(s[j]));}
        if(xd!=-1)suc=0;
        printf("Case #%d: %s\n",case_n++,suc?"YES":"NO");
    }
    return 0;
}
