#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#define rep(i,m,n) for(int i = m; i < (int)n; i++)
#define REP(i,n) rep(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()

using namespace std;
static const double EPS = 1e-9;
int INF = 1<<28;
typedef long long ll;
typedef pair<int,int> Pii;

int N,M;
bool used[101][101];
vector<int> h2j[101];
vector<int> h2i[101];

void input() {
  cin >> N >> M;
  memset(used, false, sizeof(used));
  for (int i = 0; i < 101; i++) {
    h2j[i].clear();
    h2i[i].clear();
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int height; cin >> height;
      h2j[height].push_back(j);
      h2i[height].push_back(i);
    }
  }
  return;
}

bool ok_col (int jj) {
  REP(i,N) {
    if ( used[i][jj] ) {
      return false;
    }
  }      
  return true;
}

bool ok_row (int ii) {
  REP(j,M) {
    if ( used[ii][j] ) {
      return false;
    }
  }      
  return true;
}

int solve() {
  input();
  bool is_yes = true;
  for (int h = 100; h >= 1; h--){
    for (int k = 0; k < h2i[h].size(); k++){
      if ( not ok_col(h2j[h][k]) and not ok_row(h2i[h][k]) )
	return -1;
    }
    for (int k = 0; k < h2i[h].size(); k++) {
      used[h2i[h][k]][h2j[h][k]] = true;
    }
  }
  return 0;
}

int main() {

  int T; cin >> T;
  for (int i= 0; i < T; i++) {
    int ans = solve();
    cout << "Case #"<< i+1 << ": ";
    if (ans == 0) {
      cout << "YES"<< endl;
    } else {
      cout << "NO" << endl;
    }
  }
  
  
  return 0;
}
