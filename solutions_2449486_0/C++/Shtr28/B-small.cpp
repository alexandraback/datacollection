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
bool boad[10][10];

void input() {
  cin >> N >> M;
  memset(boad, false, sizeof(boad));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int height; cin >> height;
      bool is_one = (height == 1);
      boad[i][j] = is_one;
    }
  }
  return;
}

bool ok_col (int jj) {
  bool ok = true;
  REP(i,N) {
    if ( not boad[i][jj] ) {
      ok = false;
    }
  }      
  return ok;
}

bool ok_row (int ii) {
  bool ok = true;
  REP(j,M) {
    if ( not boad[ii][j] ) {
      ok = false;
    }
  }      
  return ok;
}

int solve() {
  input();
  bool is_yes = true;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(not boad[i][j])
	continue;
      if ( not ok_col(j) && not ok_row(i) )
	is_yes = false;
    }
  }
  
  if (is_yes)
    return 0;

  return -1;
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
