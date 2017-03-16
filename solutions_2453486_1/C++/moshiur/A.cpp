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

char board[6][6];

bool won(char ch){
    FOR(r,4){
        int cnt=0;
        FOR(c,4)cnt += (board[r][c]==ch || board[r][c]=='T');
        if(cnt==4) return true;
    }
    FOR(c,4){
        int cnt=0;
        FOR(r,4)cnt += (board[r][c]==ch || board[r][c]=='T');
        if(cnt==4) return true;
    }
    int cnt=0;
    FOR(r,4) cnt+=(board[r][r]==ch||board[r][r]=='T');
    if(cnt==4) return true;
    cnt=0;
    FOR(r,4) cnt+=(board[r][3-r]==ch||board[r][3-r]=='T');
    if(cnt==4) return true;

    return false;
}

bool allFilled(){
    FOR(r,4)FOR(c,4)if(board[r][c]=='.')return false;
    return true;
}

int main(){
    freopen("A_large.in","r",stdin);
    freopen("A_large_output.txt","w",stdout);

    int T=INT;

    REP(t,1,T){
        FOR(r,4)scanf("%s",board[r]);

        printf("Case #%d: ",t);

        if(won('X')) puts("X won");
        else if(won('O')) puts("O won");
        else if(allFilled()) puts("Draw");
        else puts("Game has not completed");
    }

    return 0;
}
