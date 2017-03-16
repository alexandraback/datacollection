#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

char board[10][10];
int cnt[256];

bool won(char c) {
    REP(i,4) {
        REP(j,4) if (board[i][j] != c && board[i][j] != 'T') goto faila;
        return true;
        faila:;
    }
    REP(i,4) {
        REP(j,4) if (board[j][i] != c && board[j][i] != 'T') goto failb;
        return true;
        failb:;
    }
    REP(i,4) if (board[i][i] != c && board[i][i] != 'T') goto failc;
    return true;
    failc:;
    REP(i,4) if (board[i][3-i] != c && board[i][3-i] != 'T') goto faild;
    return true;
    faild:;
    return false;
}

void scase() {    
    REP(i,4) scanf("%s",board[i]);
    REP(i,256) cnt[i] = 0;
    REP(i,4)REP(j,4) cnt[board[i][j]]++;
    if (won('X')) printf("X won\n");
    else if(won('O')) printf("O won\n");
    else if(cnt['.']) printf("Game has not completed\n");
    else printf("Draw\n");
}

int main() {
    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
}  
