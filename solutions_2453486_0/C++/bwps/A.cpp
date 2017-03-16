#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int TC;
string board[4];

bool won(char c) {
  FOR(i, 0, 4) {
    bool row = true, col = true;
    FOR(j, 0, 4) {
      if (board[i][j] != c && board[i][j] != 'T') {
        row = false;
      }
      if (board[j][i] != c && board[j][i] != 'T') {
        col = false;
      }
    }
    if (row || col) return true;
  }
  bool diag = true;
  FOR(i, 0, 4) if (board[i][i] != c && board[i][i] != 'T') diag = false;
  if (diag) return true;
  FOR(i, 0, 4) if (board[i][4-i-1] != c && board[i][4-i-1] != 'T') return false;
  return true;
}

bool finished() {
  FOR(i, 0, 4) FOR(j, 0, 4) if (board[i][j] == '.') return false;
  return true;
}

int main() {
  cin >> TC;
  FOR(cs, 1, TC+1) {
    FOR(i, 0, 4) cin >> board[i];
    cout << "Case #" << cs << ": ";
    if (won('X')) {
      cout << "X won" << endl;
    } else if (won('O')) {
      cout << "O won" << endl;
    } else if (finished()) {
      cout << "Draw" << endl;
    } else {
      cout << "Game has not completed" << endl;
    }
  }
	return 0;
}
