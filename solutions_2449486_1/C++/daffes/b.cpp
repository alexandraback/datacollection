#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <numeric>
#include <limits.h>
#include <assert.h>

using namespace std;

typedef stringstream ss;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef long long ll;

#define FOR(i,n) for(int i = 0; i < n; i++)
#define SZ(v) int(v.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define ITE(v) typeof(v.begin())
#define FORIT(it,v) for(ITE(v) it = v.begin(); it != v.end(); it++)

int tab[101][101];
int maxc[101], maxl[101];

void solve() {
  memset(maxc, 0, sizeof(maxc));
  memset(maxl, 0, sizeof(maxl));
  int n,m;
  cin >> n >> m;
  FOR(i,n) FOR(j,m) {
    cin >> tab[i][j];
    maxl[i] = max(maxl[i], tab[i][j]);
    maxc[j] = max(maxc[j], tab[i][j]);
  }
  FOR(i,n) FOR(j,m) {
    if (tab[i][j] < min(maxl[i], maxc[j])) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main(int argc, char *argv[]) {
  int ntest;
  cin >> ntest;
  FOR(kk, ntest) {
    cout << "Case #" << kk + 1<< ": ";
    solve();
  }
  return 0;
}
