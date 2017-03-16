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
  cout.setf(ios::fixed);
  cout.precision(10);
  
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int n;
    cin >> n;
    Vi v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    
    int x = 0;
    for (int i = 0; i < n; ++i) x += v[i];
    
    cout << "Case #" << cas << ":";
    
    for (int k = 0; k < n; ++k) {
      double e = 0, d = 1;
      for (int step = 0; step < 100; ++step) {
        double m = 0.5*e + 0.5*d;
        
        double p = v[k] + x*m;
        double y = 1 - m;
        for (int i = 0; i < n; ++i) {
          if (i != k) {
            double t = max(0.0, (p - v[i])/x);
            y -= t;
          }
        }
        
        if (0 <= y) e = m;
        else d = m;
      }
      
      cout << " " << 100*d;
    }
    cout << endl;
  }
}
