#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int N, M;
int a[100][100];
bool ok(){
  REP(i, N) REP(j, M){
    bool ok = false;
    int max_c = a[i][j];
    REP(k, N) max_c = max(max_c, a[k][j]);
    if(max_c == a[i][j]) ok = true;
    max_c = a[i][j];
    REP(k, M) max_c = max(max_c, a[i][k]);
    if(max_c == a[i][j]) ok = true;
    if(!ok) return false;
  }
  return true;
}

int main(){
  int T;
  cin >> T;
  REP(CASE, T){
    printf("Case #%d: ", CASE + 1);
    cin >> N >> M;
    REP(i, N) REP(j, M) cin >> a[i][j];
    if(ok()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
