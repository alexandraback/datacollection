#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <bitset>
#include <queue>
using namespace std;

//conversion
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long ll;

//container util
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)

//constant
const double EPS = 1e-10;
const int MAXI = 1234567890;

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;



void printList(vector<int>& v) {
  for (size_t i = 0; i < v.size(); i++) {
	cout << v[i] << " ";
  }
  cout << endl;
}

void printMatrix(vector< vector<int> >& v) {
  for (size_t i = 0; i < v.size(); i++) {
	printList(v[i]);
  }
  cout << endl;
}


ll f(ll r, ll n) {
  return (2 * n - 1 + 2 * r) * n;
}

ll search(ll low, ll high, ll r, ll t) {
  if (low + 1 == high) return low;

  ll mid = (low + high) / 2;
  ll temp = f(r, mid);

  if (temp <= t) {
    return search(mid, high, r, t);
  } else {
    return search(low, mid, r, t);
  }

}

ll solve(ll r, ll t) {
  for (ll i = 1; true; i *= 2) {
    ll temp = f(r, i);
    if (temp <= t) continue;
    return search(i / 2, i, r, t);
  }
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    ll r, t;
    cin >> r >> t;
    ll ans = solve(r, t);
    cout << "Case #" << i + 1 << ": " << ans << endl;
  }
  return 0;
}
