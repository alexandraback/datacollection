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

string boad[4];

enum koma {
  O_koma,
  X_koma,
  T_koma,
};

int boad2koma(char c) {
  if (c == 'O')
    return 0;
  else if (c == 'X')
    return 1;
  else if (c == 'T')
    return 2;

  return -1;
}

void input() {
  for (int i = 0; i < 4; i++) {
    cin >> boad[i];
  }
  string tmp; getline(cin,tmp);
  return;
}

int solve() {
  input();
  int col[4][3], row[4][3], dia[2][3];
  bool can_be_draw = true;
  memset(col,0,sizeof(col));
  memset(row,0,sizeof(row));
  memset(dia,0,sizeof(dia));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int koma = boad2koma(boad[i][j]);
      if ( koma < 0) {
	can_be_draw = false;
	continue;
      }

      col[j][koma]++;
      row[i][koma]++;
      if (i == j)
	dia[0][koma]++;
      if (i == 3-j)
	dia[1][koma]++;
    }
  }

  for ( int k = 0; k < 2; k++) {
    bool is_won = false;
    if (dia[0][k] == 4 || dia[1][k] == 4) is_won = true;
    else if (dia[0][k] == 3 && dia[0][T_koma] == 1) is_won = true;
    else if (dia[1][k] == 3 && dia[1][T_koma] == 1) is_won = true;
    for ( int i = 0; i < 4; i++ ) {
      if (col[i][k] == 4 || row[i][k] == 4) is_won = true;
      else if (col[i][k] == 3 && col[i][T_koma] == 1) is_won = true;
      else if (row[i][k] == 3 && row[i][T_koma] == 1) is_won = true;
    }
    if ( is_won )
      return  k;
  }

  if (can_be_draw)
    return 2;

  return 3;
}

int main() {

  int T; cin >> T;
  for (int i= 0; i < T; i++) {
    int ans = solve();
    cout << "Case #"<< i+1 << ": ";
    if (ans == 0) {
      cout << "O won"<< endl;
    } else if (ans == 1) {
      cout << "X won"<< endl;
    } else if (ans == 2) {
      cout << "Draw" << endl;
    } else if (ans == 3) {
      cout << "Game has not completed" << endl;
    }
  }
  
  
  return 0;
}
