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
  int i, A, B;
  ld p, total;
  cin >> tc;
  while (cn++ < tc) {
    cin >> A >> B;
    ld res = B + 2;
    total = 1.0;
    for (i = 1; i <= A; i++) {
      cin >> p;
      total *= p;
      res = min(res, ((B - i) + (A - i) + 1) + (B + 1) * (1 - total));
    }
    cout << "Case #" << cn << ": " << fixed << setprecision(15) << res << endl;
  }
  return 0;
}
