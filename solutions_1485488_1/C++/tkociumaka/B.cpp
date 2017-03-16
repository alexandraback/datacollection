#include<algorithm>
#include<cassert>
#include<complex>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define fup FOR
#define fdo FORD
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x).size())
#define siz SIZE
#define CLR memset((x),0,sizeof (x))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SQR(a) ((a)*(a))

#define DEBUG 1
#define debug(x) {if(DEBUG) cerr << #x << " = " << x << endl;}
#define debugv(x) {if(DEBUG) {cerr << #x << " = "; FORE(it,(x)) cerr << *it << " . "; cerr  <<endl;}}

using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef VI vi;
typedef LL lli;

const int M = 110;
int F[M][M], C[M][M];
int T[M][M];

struct event{
    event(int _t, int _i, int _j): t(_t), i(_i), j(_j) {}
    int t;
    int i, j;

    bool operator < (const event& e) const {
        return t > e.t;
    }

};

const int inf = 1000000000;

int H, n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

priority_queue<event> Q;
void proc(int t, int x, int y, int xx, int yy) {
    if (F[x][y] + 50 > C[xx][yy]) return;
    if (F[xx][yy] + 50 > C[xx][yy]) return;
    if (F[xx][yy] + 50 > C[x][y]) return;
    // water level
    if (H-t + 50 > C[xx][yy]) {
        t = H-C[xx][yy]+50;
    }
    int tt = t;
    if (H-t >= 20 + F[x][y]) tt = t + 10;
    else tt = t + 100;
    if (t == 0) tt = 0;
    Q.push(event(tt, xx, yy));

}

void solve(int tca) {
    scanf("%d%d%d", &H, &n, &m);
    REP(i, n) REP(j, m) {
        scanf("%d\n", &C[i][j]);
    }
    REP(i, n) REP(j, m) {
        scanf("%d\n", &F[i][j]);
        T[i][j] = inf;
    }
    T[0][0] = inf;
    Q.push(event(0,0,0));
    while(!Q.empty()) {
        event e = Q.top();
        Q.pop();
        int x = e.i;
        int y = e.j;
        if (T[x][y] != inf) continue;
        T[x][y] = e.t;
        REP(i, 4) {
            if (x+dx[i] >= 0 && x+dx[i] < n && y+dy[i]>=0 && y+dy[i]<m) {
                proc(e.t, x, y, x+dx[i], y+dy[i]);
            }
        }

    }
/*    REP(i, n) {
        REP(j, m) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }*/

    printf("Case #%d: %.9lf\n", tca, ((double) T[n-1][m-1])/10);
}

int main() {
    int t;
    scanf("%d", &t);
    REP(i, t) solve(i+1);

    return 0;
}
