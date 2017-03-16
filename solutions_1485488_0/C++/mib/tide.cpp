#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

#define REP(i, n) for(int i=0; i<n; ++i)
#define ST first
#define ND second
#define PB push_back
#define VAR(v,n) __typeof__(n) v=(n)
#define FE(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define ALL(c) (c).begin(),(c).end()

#define MAXN 110
int C[MAXN][MAXN];
int F[MAXN][MAXN];

#define visited v

vector< PII > starting;
bool v[MAXN][MAXN];

void cv(){
    REP(i, MAXN) REP(j, MAXN) v[i][j] = false;
}

int n, m, h;

bool inbounds(int a, int b){
    if ( a < 0 || b < 0 ) return false;
    if ( a >= n || b >= m ) return false;
    return true;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


bool rules(int i, int j, int a, int b){
    if (! inbounds(a, b)) return false;

    if ( C[a][b] - F[i][j] < 50 ) return false;
    if ( C[a][b] - F[a][b] < 50 ) return false;

    if ( C[i][j] - F[a][b] < 50 ) return false;
    return true;
}

bool acc(int h, int i, int j, int a, int b){
    if ( ! rules(i, j, a, b) ) return false; 
    if ( C[a][b] - h < 50 ) return false;
    return true;
}

void sdfs(int i, int j){
    starting.PB( PII(i, j) );
    v[i][j] = true;
    REP(d, 4) {
        int ni  = i + dx[d];
        int nj = j + dy[d];
       if ( acc( h, i, j, ni, nj ) && ! visited[ni][nj] ){
            sdfs(ni, nj);
       }
    }
}

typedef pair<int, PII> QE;

int dis[MAXN][MAXN];

int testcase(){
    scanf("%d%d%d", &h, &n, &m);
    REP(i, n){
        REP(j, m) scanf("%d", &C[i][j]);
    }
    REP(i, n){
        REP(j, m) scanf("%d", &F[i][j]);
    }
    //cerr << "---------------" << endl;
    cv();
    starting.clear();
    sdfs( 0, 0 );
    int INF = 1000000000;
    REP(i, n) REP(j, m) dis[i][j] = INF;
    priority_queue< QE > Q;
    REP(i, starting.size()){
        cerr << starting[i].ST << ' ' << starting[i].ND<< endl;
        Q.push(  QE( 0, starting[i] )  );
        //dis[ starting[i].ST ][ starting[i].ND ] = 0;
    }

    cv();

    while( ! Q.empty() ){
        QE e = Q.top(); Q.pop();
        int a = e.ND.ST;
        int b = e.ND.ND;
        int level = h + e.ST; 
        if ( -e.ST >= dis[a][b] ) continue;
        dis[a][b] = -e.ST;
        //cerr << "f " << a << ' ' << b << endl;
        REP( d, 4 ){
            int aa = a + dx[d];
            int bb = b + dy[d];
            if ( ! rules( a, b, aa, bb ) ) {
                //cerr << "rb " << aa << ' ' << bb << endl;
                continue;
                
            }
            // C[aa][bb] - newlevel >= 50
            int newlevel = min(level, C[aa][bb] - 50);
            int penalty = 100;
            if ( newlevel - F[a][b] >= 20 ) penalty = 10;
            int newtime = penalty + h - newlevel;
            Q.push( QE( -newtime, PII( aa, bb )) );
        }
    }
    return dis[ n-1 ][ m-1 ];
}

int main(){
int z; scanf("%d", &z);
REP(i, z) {
    printf("Case #%d: %lf\n", i+1, testcase() / 10.0);
}
return 0;
}

