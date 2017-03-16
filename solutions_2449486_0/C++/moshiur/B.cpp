#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//#define DEBUG_MODE

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

#ifdef DEBUG_MODE
#define DBG(X) X
#else
#define DBG(X)
#endif

inline int ___INT(){int ret; scanf("%d",&ret); return ret;}
#define INT ___INT()

typedef long long LL;
typedef pair<int,int> pii;

int R,C;
int A[105][105];

bool can(){
    for(int i=1;i<=100;++i){
        bool R_all_i[105], C_all_i[105];
        CLR(R_all_i,0); CLR(C_all_i,0);
        FOR(r,R){
            R_all_i[r]=true;
            FOR(c,C)if(A[r][c]!=i)R_all_i[r]=false;
        }
        FOR(c,C){
            C_all_i[c]=true;
            FOR(r,R)if(A[r][c]!=i)C_all_i[c]=false;
        }
        FOR(r,R)FOR(c,C){
            if(A[r][c]==i){
                if(!R_all_i[r] && !C_all_i[c]) return false;
                A[r][c]=i+1;
            }
        }
    }
    return true;
}

int main(){
    freopen("B_small.in","r",stdin);
    freopen("B_small_output.txt","w",stdout);

    int T=INT;

    REP(t,1,T){
        R=INT;C=INT;
        FOR(r,R)FOR(c,C){
            A[r][c]=INT;
        }

        printf("Case #%d: ",t);
        if(can()) puts("YES"); else puts("NO");
    }

    return 0;
}
