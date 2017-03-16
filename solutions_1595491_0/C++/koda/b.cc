#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <ext/algorithm>
#include <ext/functional>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/iterator>
#include <ext/numeric>
#include <ext/rope>
#include <ext/slist>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <valarray>
#include <vector>
#include <queue>
using namespace __gnu_cxx;
using namespace std;

#include <boost/regex.hpp>
using namespace boost;
#define LL long long
#define VI vector<int>
#define VS vector<string>
#define VLL vector<long long>
#define VD vector<double>
#define VCH vector<char>
#define VB vector<bool>
#define VVI vector< vector<int> >
#define VVS vector< vector<string> >
#define VVLL vector< vector<long long> >
#define VVD vector< vector<double> >
#define VVCH vector< vector<char> >
#define VVB vector< vector<bool> >
#define HMII hash_map<int,int>
#define HMIS hash_map<int,string>
#define HMSI hash_map<string,int,stringhash>
#define HMSS hash_map<string,string,stringhash>
#define PII pair<int,int>
#define PL4 pair<long long,long long>
#define PDD pair<double,double>
#define VPII vector< pair<int,int> >
#define OSS ostringstream
#define ISS istringstream
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define forUp(i,n) for (int i=0; i<n; i++)
#define forDown(i,n) for (int i=n-1; i>=0; i--)
#define forEach(it,c) for (typeof(c.begin()) it = c.begin(); it!=c.end(); it++)
#define for2d(i,j,v) for (int i=0; i<v.size(); i++) for (int j=0; j<v[i].size(); j++)
#define fir(n) for (int i=0; i<n; i++)
#define fjr(n) for (int j=0; j<n; j++)
#define fkr(n) for (int k=0; k<n; k++)
#define firv(v) for (int i=0; i<v.size(); i++)
#define fjrv(v) for (int j=0; j<v.size(); j++)
#define fkrv(v) for (int k=0; k<v.size(); k++)
#define DB(x)
#define DBL(x)
#define DBC(c,sep)
#define INF 1000000000
#define EPS 1e-12
#define BTW(x,a,b) x>=a && x<=b
#define PI acos(-1.0L)
#define ZERO(arr) memset(arr, 0, sizeof(arr))
VI tot;
int p;
bool pre[31][11][2]; // [t][p][s] is true if can make total t with best = p and surp

int lu[101][101];
int f(int n, int s) {
  if (lu[n][s]) return lu[n][s]-1;
  if (n == tot.size())
    return s == 0 ? 0 : -INF;
  if (s < 0) return -INF;
  int mx = -INF;
  fir(11)
    fjr(2)
    if (pre[tot[n]][i][j]) {
      mx = max(mx, (i >= p ? 1 : 0) + f(n+1, s-j));
    }
  lu[n][s]=mx+1;
  return lu[n][s]-1;
}

int main() {
  ZERO(pre);
  for (int a=0;a<=10;a++)
    for (int b=a;b<=10;b++)
      for (int c=b;c<=10;c++) {
	if (c-a > 2) continue;
	int t=a+b+c;
	int s=(c-a)/2;
	pre[t][c][s]=true;
      }
  int T; cin >> T; fkr(T) {
    ZERO(lu);
    int N, S; cin >> N >> S >> p;
    tot.resize(N); fir(N) cin >> tot[i];
    cout << "Case #" << (k+1) << ": " << f(0, S) << endl;
  }
  return 0;
}
