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
bool suc(int X,int R,int C){
    if(X==1)return 1;
    if(X==2)return R*C%2==0;
    if(X==3)return R*C%3==0&&R>1&&C>1;
    if(X==4)return R>=3&&C>=3&&R*C%4==0;
    if(X==5){
        if(R*C%5)return 0;
        if(R<3||C<3)return 0;
        if(R==3||C==3)return R*C>=30;
        return 1;
    }
    if(X==6){
        if(R*C%6)return 0;
        if(R<6&&C<6)return 0;
        if(R<4||C<4)return 0;
        return 1;
    }
    return 0;
}
int main(){
    CASET{
        DRIII(X,R,C);
        printf("Case #%d: %s\n",case_n++,suc(X,R,C)?"GABRIEL":"RICHARD");
    }
    return 0;
}
