#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

void precalc () {

}

void solve () {
  int x, y;
  cin >> x >> y;

  int cx = 0, cy = 0;
  
  string ans;
  while (cx > x) {
    ans += "EW";
    cx--;
  }
  while (cx < x) {
    ans += "WE";
    cx++;
  }
  while (cy > y) {
    ans += "NS";
    cy--;
  }
  while (cy < y) {
    ans += "SN";
    cy++;
  }
  cout << ans << endl;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

  precalc();

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
    cerr << "Case #" << test << endl;
    solve();
	}
	return 0;
}
