#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
#include <ext/algorithm>
#include <ext/functional>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/iterator>
#include <ext/numeric>
#include <ext/rope>
#include <ext/slist>
using namespace __gnu_cxx;
#include <boost/rational.hpp>
#include <boost/regex.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
using namespace boost;
#define LL long long
#define VI vector<int>
#define VS vector<string>
#define VLL vector<long long>
#define VD vector<double>
#define VVI vector< vector<int> >
#define VVS vector< vector<string> >
#define VVLL vector< vector<long long> >
#define VVD vector< vector<double> >
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
#define forEach(it,c) for (typeof(c.begin()) it = c.begin(); it!=c.end(); ++it)
#define for2d(i,j,v) for (int i=0; i<v.size(); i++) for (int j=0; j<v[i].size(); j++)
#define fir(n) for (int i=0; i<n; i++)
#define fjr(n) for (int j=0; j<n; j++)
#define fkr(n) for (int k=0; k<n; k++)
#define firv(v) for (int i=0; i<v.size(); i++)
#define fjrv(v) for (int j=0; j<v.size(); j++)
#define fkrv(v) for (int k=0; k<v.size(); k++)
#define INF 1000000000
#define EPS 1e-12
#define PI acos(-1.0L)
#define ZERO(arr) memset(arr, 0, sizeof(arr))
string d2s(double d) {
  ostringstream oss; oss << setprecision(12) << d; return oss.str();
}


struct RunnerBase { bool indone() { return false; } };

//######################################################################

#line 2

struct Runner : RunnerBase {
  void run(istream &cin, ostream &cout) {
    int A,B; cin >> A >> B;
    vector<long double> p(A);
    vector<long double> cum(A+1);
    cum[0]=1;
    firv(p) {cin >> p[i]; cum[i+1]=cum[i]*p[i];}
    if (indone()) return;
    long double opt = B + 2;
    for (int i=0;i<=A;i++) {
      int succ = i + (B-A+i) + 1;
      int fail = succ + B + 1;
      opt = min(opt, fail + cum[A-i]*(succ - fail));
    }
    cout << d2s(opt) << endl;
  }
};

//######################################################################

Runner r;

int main(int argc, const char **argv) {
  ifstream fin(argc > 1 ? argv[1] : "/dev/stdin");
  ofstream fout(argc > 1 ? (argv[1] + string(".out")).c_str() : "/dev/stdout");
  int T; fin >> T; string dummy; getline(fin, dummy); assert(dummy.empty());
  fir(T) { fout << "Case #" << (i+1) << ": "; r.run(fin, fout); }
  return 0;
}
