#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define X first
#define Y second
#define PB push_back
#define FOR(x,y) for (int x = 0; x < int(y); ++x)
#define debug(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef vector<bool> Vb;
typedef vector<Vb> Mb;
typedef vector<char> Vc;
typedef vector<Vc> Mc;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<P> Vp;
typedef vector<Vp> Mp;
typedef vector<string> Vs;
typedef vector<Vs> Ms;

typedef queue<int> Q;
typedef priority_queue<int> PQ;
typedef stack<int> STACK;
typedef set<int> SET;
typedef SET::iterator Sit;
typedef map<int, int> MAP;
typedef MAP::iterator Mit;
typedef stringstream SS;

template <class Ta, class Tb> inline Tb cast(Ta a) { SS ss; ss << a; Tb b; ss >> b; return b; };

const double EPS = 1e-9;
const int INF = 1000000000;
const int MOD = 1000000007;
const int diri[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dirj[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int n;
    cin >> n;
    Vi v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    
    int total = 0;
    for (int i = 0; i < n; ++i) total += v[i];
    
    Vi result(total + 1, -1);
    int res1 = -1, res2 = -1;
    
    for (int m = 0; res1 == -1 and m < (1<<n); ++m) {
      int s = 0;
      for (int i = 0; i < n; ++i)
        if ((m>>i)&1) s += v[i];
      if (result[s] == -1) result[s] = m;
      else {
        res1 = result[s];
        res2 = m;
      }
    }
    
    cout << "Case #" << cas << ":" << endl;
    if (res1 == -1) cout << "Impossible" << endl;
    else {
      bool first = true;
      for (int i = 0; i < n; ++i)
        if ((res1>>i)&1) {
          if (first) first = false;
          else cout << " ";
          cout << v[i];
        }
      cout << endl;
      
      first = true;
      for (int i = 0; i < n; ++i)
        if ((res2>>i)&1) {
          if (first) first = false;
          else cout << " ";
          cout << v[i];
        }
      cout << endl;
    }
  }
}
