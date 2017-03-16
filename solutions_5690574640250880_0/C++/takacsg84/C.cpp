#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <map>
#include <queue>
#include <functional>
#include <memory>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <bitset>
#include <time.h>

#define EPS (1e-9)
#define PI (2 * acos(0.0))
#define XOR(exp1,exp2) ( ( (exp1)&&!(exp2) ) || (!(exp1) && (exp2)) )
#define REP(x,n)  for(int x=0;x<(int)(n);x++)
#define FOR(x,y,n) for(int x=(int)y;x<(int)(n);x++)
#define RREP(x,n) for(int x=(int)(n)-1;x>=0;--x)
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr)
#define ALL(X)    (X).begin(),(X).end()
#define mem0(X)    memset((X),0,sizeof(X))
#define mem1(X)    memset((X),255,sizeof(X))


using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;

const int MINE = 53937;
const int EMTPY = 63037;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int dx2[] = { -1, -1, -1, 0, 1, 1, 1, 0};
int dy2[] = { -1, 0, 1, 1, 1, 0, -1, -1};
int R, C, M;

int fnc(const VII &m, int x, int y) {
    int result = 0;
    REP(i, 8) {
        int x1 = x + dx2[i], y1 = y + dy2[i];
        if (x1 > -1 && x1 < R && y1 > -1 && y1 < C && m[x1][y1] == MINE) ++result;
    }
    return result;
}

void verify(VII &m){
    int total=R*C;
    REP(i,R)REP(j,C) if(m[i][j]!=MINE) m[i][j]=fnc(m,i,j),--total;
    if(total!=M) fprintf(stderr, "%d %d %d\nWrong number of mines!\n", R,C,M);
    int E=R*C-M;
    if(E >1 && m[0][0]!=0) {fprintf(stderr, "%d %d %d\n(0,0) should be 0!\n", R,C,M);return;}
    queue<PII> Q;
    Q.push(PII(0,0)),--E,m[0][0]=EMTPY;
    while(Q.size()){
        PII cur = Q.front();
        Q.pop();
        int x=cur.first, y=cur.second;
        REP(i, 8) {
            int x1 = x + dx2[i], y1 = y + dy2[i];
            if (x1 > -1 && x1 < R && y1 > -1 && y1 < C && m[x1][y1] != MINE && m[x1][y1] != EMTPY){
                if(m[x1][y1]==0) Q.push(PII(x1,y1));
                --E,m[x1][y1]=EMTPY;
            }
        }
    }
    if(E!=0) fprintf(stderr, "%d %d %d\nCan't DFS all the empty cells!\n", R,C,M);
}

bool makeMap(VII &m) {
    int notMines = R * C - M, x = 2, y = 2;
    if (notMines == 1) {
        m[0][0] = EMTPY; return true;
    }
    if (R == 1) {
        REP(i, notMines) m[0][i] = EMTPY; return true;
    }
    if (C == 1) {
        REP(i, notMines) m[i][0] = EMTPY; return true;
    }
    if (R == 2 || C == 2) {        
        if (notMines % 2 || notMines < 4) return false;
        if (R == 2) REP(i, notMines / 2) m[0][i] = EMTPY, m[1][i] = EMTPY;
        if (C == 2 && R != 2) REP(i, notMines / 2) m[i][0] = EMTPY, m[i][1] = EMTPY;
        return true;
    }
    if (notMines == 2 || notMines == 3 || notMines == 5 || notMines == 7) return false;
    REP(i, 2)REP(j, 2)m[i][j] = EMTPY, --notMines;    
    while (notMines) {
        if (notMines > 1 && (x < R || y < C)) {
            if ((x < R && x < y) || y == C) m[x][0] = EMTPY, m[x][1] = EMTPY, ++x, notMines -= 2;
            else m[0][y] = EMTPY, m[1][y] = EMTPY, ++y, notMines -= 2;
        }else
            for (int i = 2; i < R && notMines > 0; ++i)
                for (int j = 2; j < C && notMines > 0; ++j)
                    m[i][j] = EMTPY, --notMines;
    }
    return true;
}

void doStuff() {
    scanf("%d%d%d", &R, &C, &M);
    VII m(R);
    REP(i, R)m[i] = VI(C, MINE);

    if (!makeMap(m)) printf("Impossible\n");
    else {
        printf("c");
        REP(i, R) {
            REP(j, C) if(i!=0 || j!=0){
                if (m[i][j] == MINE) printf("*");
                else printf(".");
            }
            printf("\n");
        }
        verify(m);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    REP(t, T) printf("Case #%d:\n", t + 1), doStuff();
    return 0;
}