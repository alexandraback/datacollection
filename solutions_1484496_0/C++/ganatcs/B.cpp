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
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;

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




void ll2vec(ll a, const VI& ss, VI& subset) {
  for (int i = 0; i < SZ(ss); i++) {
    if (((1 << i) & a) != 0) subset.PB(ss[i]);
  }
}

bool ok(ll a, ll b) {
  if ((a & b) == 0) return true;
  return false;
}

bool solve(int N, VI& ss, VI& as, VI&bs) {
  map<ll, VI> m;

  for (int i = 1; i < (2 << N); i++) {
    ll sum = 0;
    for (int j = 0; j < N; j++) {
      if (((1 << j) & i) != 0) sum += ss[j];
    }
    if (m[sum].empty()) {
      m[sum].PB(i);
    } else {
      for (int j = 0; j < SZ(m[sum]); j++) {
	if (ok(i, m[sum][j])) {
	  ll2vec(i, ss, as);
	  ll2vec(m[sum][j], ss, bs);
	  return true;
	}
      }
      m[sum].PB(i);
    }
  }
  return false;
}


int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N;
    cin >> N;
    VI ss(N, 0);
    for (int j = 0; j < N; j++) {
      cin >> ss[j];
    }
    PII p;
    VI as, bs;
    bool ans = solve(N, ss, as, bs);
    cout << "Case #" << i + 1 << ":" << endl;
    if (ans) {
      string pre = "";
      for (int j = 0; j < SZ(as); j++) {
	cout << pre << as[j];
	pre = " ";
      }
      cout << endl;
      pre = "";
      for (int j = 0; j < SZ(bs); j++) {
	cout << pre << bs[j];
	pre = " ";
      }
      cout << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }
  return 0;
}
