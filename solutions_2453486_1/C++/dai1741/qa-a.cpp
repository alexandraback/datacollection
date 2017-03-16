#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define rep(i,n) for (int i=0; i < (n); i++)

int n = 4;
int check(VVI& map, int x, int y, int dx, int dy) {
  int ret = -1;
  for (; x < n && y < n; x += dx, y += dy) {
  	ret &= map[x][y];
  }
  return ret;
}

string solve() {
  VVI map(n, VI(n));
  bool hasEmpty = false;
  rep(i,n) rep(j,n) {
  	char c;
  	cin >> c;
  	map[i][j] = c == 'T' ? 3 : c == 'O' ? 2 : c == 'X' ? 1 : 0;
  	hasEmpty |= c == '.';
  }
  int ans = check(map, 0,0,1,1) | check(map, 0,3,1,-1);
  rep(i,n) ans |= check(map, i,0,0,1) | check(map, 0,i,1,0);
  
  return ans == 0 ? (hasEmpty ? "Game has not completed" : "Draw") : ans == 1 ? "X won" : "O won";
}

int main() {
  int t;
  cin >> t;
  rep(i, t) cout << "Case #" << i+1 << ": " << solve() << endl;
  return 0;
}