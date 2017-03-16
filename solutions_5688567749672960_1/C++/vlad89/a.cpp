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
#include <queue>

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

string problemName = "A";
string smallFileName = problemName + "-small-attempt0";
string largeFileName = problemName + "-large";

//string fileName(1, tolower(problemName[0]));
//string fileName = smallFileName;
string fileName = largeFileName;

string inputFileName = fileName + ".in";
string outputFileName = fileName + ".out";

ll solve(ll from, ll to) {
  if (to < 10) return to;
  if (from == to) return 0;
  if (to % 10 == 0) {
    return solve(from, to-1)+1;
  }
  ostringstream str;
  str << to;
  string s = str.str();
  ll x = 0;
  for (int i = s.size() / 2; i < s.size(); ++i)
    x = x * 10 + s[i] - '0';
  ll ans = 0;
  ans += x;
  x = 0;
  for (int i = s.size() / 2 - 1; i >= 0; --i)
    x = x * 10 + s[i]-'0';
  ans++;
  ans += x-1;
  return min(ans, to-from);
}

ll solve(ll n) {
  ll x = n;
  ll from = 1, to = 9;
  ll res = 0;
  while (x > 9) {
    res += solve(from, to) + 1;
    from = from * 10;
    to = to * 10 + 9;
    x /= 10;
  }
  res += solve(from, n);
  return res;
}

vector<int> dp(int n) {
  vector<int> a(n+1, -1u/4);
  vector<bool> was(n+1);
  a[1] = 1;
  REP (i, n) {
    int k = -1;
    FOR (j, 1, n+1)
      if (!was[j] && (k == -1 || a[j] < a[k])) k = j;
    was[k] = true;
    if (k + 1 <= n && a[k + 1] > a[k] + 1) a[k+1] = a[k] + 1;
    ostringstream str;
    str << k;
    string s = str.str();
    reverse(all(s));
    int g;
    istringstream str2(s);
    str2 >> g;
    if (g <= n && a[g] > a[k] + 1) a[g] = a[k] + 1;
  }
  return a;
}

int main () {
  // vector<int> a = dp(100000);
  // FOR (i, 1, sz(a))
  //   if (a[i] != solve(i)) {
  //     cout << a[i] << ' ' << solve(i) << ' ' << i << endl;
  //     return 0;
  //   }
  // return 0;
    freopen(inputFileName.data(), "r", stdin);
    if (fileName == smallFileName || fileName == largeFileName)
    {
	freopen(outputFileName.data(), "w", stdout);
    }
    int T;
    cin >> T;
    REP (test, T) {
	cout << "Case #" << (test + 1) << ": ";
	ll n;
	cin >> n;
	cout << solve(n) << endl;
    }
    return 0;
}
