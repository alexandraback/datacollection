#pragma comment(linker, "/STACK:46777216")

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <cmath>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned char byte;
typedef pair<int, int> pii;
#define forn(i,n) for (ll i = 0; i < ll(n); ++i)
#define mp make_pair

int main() {
  int T;
  cin >> T;
  forn (_, T) {
    cout << "Case #" << (_ + 1) << ": ";
    
    int n, m; cin >> n >> m;
    int data[256][256];
    int sim[256][256];
    forn (i, n) forn(j, m) {
      cin >> data[i][j];
      sim[i][j] = 100;
    }

    forn (i, n) {
      int mx = 0;
      forn (j, m) mx = std::max(mx, data[i][j]);
      forn (j, m) sim[i][j] = std::min(mx, sim[i][j]);
    }

    forn (j, m) {
      int my = 0;
      forn (i, n) my = std::max(my, data[i][j]);
      forn (i, n) sim[i][j] = std::min(my, sim[i][j]);
    }

    bool ok = true;
    forn (i, n) forn (j, m) if (data[i][j] != sim[i][j]) ok = false;

    cout << (ok ? "YES" : "NO");

    cout << endl;
  }


  return 0;
}