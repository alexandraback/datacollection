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
const int LIM = 2000001;
int arr[LIM * 8];
int p10[10];
int cyc(int n, int d) {
  int numd=1; while (n>=p10[numd]) ++numd;
  if (numd == 1 || numd <= d || d < 1) return 0;
  else {
    int p = p10[d];
    return (n % p) * p10[numd-d] + n/p;
  }
}
int main() {
  ZERO(arr);
  p10[0]=1; fir(9) p10[i+1]=10*p10[i];
  set<int> seen;
  for(int n=0, p=0;n<=LIM;n++) {
    seen.clear();
    for (int d=1;d<10;d++) {
      int c = cyc(n, d);
      if (c > n && c <= LIM && seen.count(c)==0) {
	arr[p++] = c;
	seen.insert(c);
      }
      if (c==0) break;
    }
    arr[p++] = 0;
  }

  int T; cin >> T; fkr(T) {
    int A,B; cin >> A >> B;
    int res=0;
    int i=0, p=0;
    while (i<=B) {
      for (;arr[p];p++)
	if (A <= i && arr[p] <= B)
	  {res++;
	    //cerr << i << " " << arr[p] << endl;
	  }
      i++;
      p++;
    }
    cout << "Case #" << (k+1) << ": " << res << endl;
  }
  return 0;
}
