#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <set>
#include <map>
#include <iomanip>

#define fr(i,n) for(i=0;i<(int)(n);i++)
#define fit(a,b) for(typeof(b.begin()) a = b.begin(); a != b.end(); a++)
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define SZ(u) ((int)u.size())
#define WT(x) cout << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int,int> p2;
typedef vector<int> vi;
typedef long double ld;

int main() {
  int tc, cn = 0;
  cin >> tc;
  while (cn++ < tc) {
    int R, C, K;
    cin >> R >> C >> K;
    int i, j, k, res = K;
    for (i = 3; i <= R; ++i) for (j = 3; j <= C; ++j) if (K <= i * j) {
      for (k = 0; k <= 4; ++k) {
        if (K <= i * j - 4 + k) {
          res = min(res, i * 2 + j * 2 - 8 + k);
        }
      }
      if (i >= 4 && j >= 4) {
        int r = min(i, j);
        int c = max(i, j);
        int have = i * j - 4;
        for (k = 1; k <= r - 3; ++k) {
          int stones = i * 2 + j * 2 - 8 - k;
          have -= (k + 1);
          if (K <= have) res = min(res, stones);
        }
      }
    }
    cout << "Case #" << cn << ": " << res << endl;
  }
  return 0;
}
