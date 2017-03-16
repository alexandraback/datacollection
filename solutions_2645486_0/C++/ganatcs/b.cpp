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




ll solve(int E, int R, int N, const VI& values) {

  int dp[N][E + 1];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= E; j++) {
      dp[i][j] = 0;
    }
  }

  for (int i = 0; i <= E; i++) {
    dp[0][min(E - i + R, E)] = values[0] * i;
  }

  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j <= E; j++) {
      for (int k = 0; k <= j; k++) {
	int rest = min(j - k + R, E);
	dp[i + 1][rest] = max(dp[i + 1][rest], dp[i][j] + k * values[i + 1]);
      }
    }
  }

  int maxv = 0;
  for (int i = 0; i <= E; i++) {
    maxv = max(maxv, dp[N - 1][i]);
  }
  return maxv;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    int E, R, N;
    cin >> E >> R >> N;
    VI values(N, 0);
    for (int j = 0; j < N; j++) {
      cin >> values[j];
    }
    ll ans = solve(E, R, N, values);
    cout << "Case #" << i + 1 << ": " << ans << endl;
  }
  return 0;
}
