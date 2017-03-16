#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

string problemName = "C";
string smallFileName = problemName + "-small-1-attempt1";
string largeFileName = problemName + "-large";

//string fileName(1, tolower(problemName[0]));
string fileName = smallFileName;
//string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

bool faster_eq(ll s1, ll v1, ll s2, ll v2) {
  return s1 * v1 <= s2 * v2;
}

int solve(vector<pii> a) {
  if (sz(a) < 2) return 0;
  if (faster_eq(360 - a[0].X + 360, a[0].Y, 360 - a[1].X, a[1].Y)) return 1;
  if (faster_eq(360 - a[1].X + 360, a[1].Y, 360 - a[0].X, a[0].Y)) return 1;
  return 0;
}

int main () {
  freopen(inputFileName.data(), "r", stdin);
  if (fileName == smallFileName || fileName == largeFileName)
    {
      freopen(outputFileName.data(), "w", stdout);
    }
  int T;
  cin >> T;
  REP (test, T) {
    cout << "Case #" << (test + 1) << ": ";
    int n;
    cin >> n;
    vi d(n), h(n), m(n);
    vector<pii> a;
    REP (i, n) {
      cin >> d[i] >> h[i] >> m[i];
      REP (j, h[i])
	a.pb(pii(d[i], m[i] + j));
    }
    cout << solve(a) << endl;
  }
  return 0;
}
