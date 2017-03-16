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

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

string problemName = "C";
string smallFileName = problemName + "-small-attempt2";
string largeFileName = problemName + "-large";

//string fileName(1, tolower(problemName[0]));
string fileName = smallFileName;
//string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

pii mult(pii q, pii w) {
  if (q.Y == 3) return pii(q.X * w.X, w.Y);
  if (w.Y == 3) return pii(q.X * w.X, q.Y);
  if (w.Y == q.Y) return pii(q.X * w.X * -1, 3);
  return pii(q.X * w.X * (w.Y == (q.Y+1)%3 ? 1 : -1), 3-q.Y-w.Y);
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
	int l;
	long long n;
	cin >> l >> n;
	// if (n > 6) {
	//   n = 6 + n % 2;
	// }
	vector<pii> a;
	string s;
	cin >> s;
	pii total_should = mult(mult(pii(1, 0), pii(1, 1)), pii(1, 2));
	//	cout << total_should.X << endl;
	pii total(1, 3);
	REP (it, n) {
	  REP (i, l) {
	    a.pb(pii(1, s[i] == 'i' ? 0 : s[i] == 'j' ? 1 : 2));
	    total = mult(total, a.back());
	  }
	}
	if (total != total_should) {
	  cout << "NO\n";
	  continue;
	}
	pii from_start(1, 3);
	int first = -1;
	REP (i, sz(a)) {
	  from_start = mult(from_start, a[i]);
	  if (from_start == pii(1, 0)) {
	    first = i;
	    break;
	  }
	}
	if (first == -1) {
	  cout << "NO\n";
	  continue;
	}
	pii from_end(1, 3);

	bool ok = false;
	for (int i = sz(a)-1; i >= 0; --i) {
	  from_end = mult(a[i], from_end);
	  if (from_end == pii(1, 2) && i && first < i-1) {
	    ok = true;
	    break;
	  }
	}
	cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
