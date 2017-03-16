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
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

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

ll minl(ll a, ll b) {
  if (a < b) return a;
  else return b;
}

ll maxl(ll a, ll b) {
  if (a > b) return a;
  else return b;
}


ll solve(int a, int b, ll r_a, ll r_b, int N, int M, VI& n_a, VI& t_a, VI& n_b, VI& t_b) {
  if (a == N || b == M) return 0;

  ll ans = 0;
  if (t_a[a] == t_b[b]) {
    ans = minl(r_a, r_b);
    if (r_a == r_b) {
      ans += solve(a + 1, b + 1, n_a[a + 1], n_b[b + 1], N, M, n_a, t_a, n_b, t_b);
    } else if (r_a > r_b) {
      ans += solve(a, b + 1, r_a - r_b, n_b[b + 1],  N, M, n_a, t_a, n_b, t_b);
    } else {
      ans += solve(a + 1, b, n_a[a + 1], r_b - r_a,  N, M, n_a, t_a, n_b, t_b);
    }
  } else {
    ans = maxl(solve(a + 1, b, n_a[a + 1], r_b, N, M, n_a, t_a, n_b, t_b),
	      solve(a, b + 1, r_a, n_b[b + 1], N, M, n_a, t_a, n_b, t_b));
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int N, M;
    cin >> N >> M;
    VI n_a;
    VI t_a;
    VI n_b;
    VI t_b;
    for (int j = 0; j < N; j++) {
      ll n, t;
      cin >> n >> t;
      n_a.PB(n);
      t_a.PB(t);
    }
    for (int j = 0; j < M; j++) {
      ll n, t;
      cin >> n >> t;
      n_b.PB(n);
      t_b.PB(t);
    }
    n_a.PB(0);
    n_b.PB(0);
    ll ans = solve(0, 0, n_a[0], n_b[0], N, M, n_a, t_a, n_b, t_b);
    cout << "Case #" << i + 1 << ": " << ans << endl;
  }
  return 0;
}
