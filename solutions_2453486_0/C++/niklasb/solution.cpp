#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;
using namespace std::tr1;

typedef long long llong;
typedef pair<int, int> int2;
typedef pair<llong, llong> llong2;
#define foreach(v,c) for (typeof((c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define rep(i,n) for (int i = 0; i < (n); ++i)

char game[4][10];
int xs = 0, ys = 0, ts = 0;
int check() {
  if (xs == 3 && ts == 1 || xs == 4) { cout << "X won"; return 1; }
  else if (ys == 3 && ts == 1 || ys == 4) { cout << "O won"; return 2; }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  int i, j; bool draw;
  for (int t_ = 0; t_ < T; t_++) {
    cout << "Case #" << (t_+1) << ": ";
    for (i = 0; i < 4; ++i)
      cin >> game[i];
    for (i = 0; i < 4; ++i) {
      xs=ys=ts=0;
      for (j = 0; j < 4; ++j) {
        if (game[i][j] == 'X') xs++;
        if (game[i][j] == 'O') ys++;
        if (game[i][j] == 'T') ts++;
        if (check()) goto end;
      }
      xs=ys=ts=0;
      for (j = 0; j < 4; ++j) {
        if (game[j][i] == 'X') xs++;
        if (game[j][i] == 'O') ys++;
        if (game[j][i] == 'T') ts++;
        if (check()) goto end;
      }
    }
    xs=ys=ts=0;
    for (j = 0; j < 4; ++j) {
      if (game[j][j] == 'X') xs++;
      if (game[j][j] == 'O') ys++;
      if (game[j][j] == 'T') ts++;
      if (check()) goto end;
    }
    xs=ys=ts=0;
    for (j = 0; j < 4; ++j) {
      if (game[j][3-j] == 'X') xs++;
      if (game[j][3-j] == 'O') ys++;
      if (game[j][3-j] == 'T') ts++;
      if (check()) goto end;
    }
    draw = true;
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
        if (game[i][j] == '.') draw = false;
    if (draw) cout << "Draw";
    else cout << "Game has not completed";
end:
    cout << endl;
  }
}
