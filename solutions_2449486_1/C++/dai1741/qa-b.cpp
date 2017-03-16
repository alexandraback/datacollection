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

bool solve() {
  int n, m;
  cin >> n >> m;
  VVI a(n, VI(m));
  rep(i,n) rep(j,m) {
  	cin >> a[i][j];
  }
  rep(i,n) rep(j,m) {
    int numOk = 2;
    rep(i2,n) {
      if (a[i2][j] > a[i][j]) {
      	numOk--; break;
      }
    }
    rep(j2,m) {
      if (a[i][j2] > a[i][j]) {
      	numOk--; break;
      }
    }
    if (numOk == 0) return false;
  }

  return true;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) cout << "Case #" << i+1 << ": " << (solve() ? "YES" : "NO") << endl;
  return 0;
}