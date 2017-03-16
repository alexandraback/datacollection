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
#include <boost/rational.hpp>
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
long long gcdll_aux(long long a, long long b)
{
  if (a<b) return gcdll_aux(b,a);
  if (b==0) return a;
  return gcdll_aux(b,a%b);
}

long long gcdll(long long a, long long b)
{
  return gcdll_aux(a < 0 ? -a : a , b < 0 ? -b : b);
}

char arr[30][30];
typedef rational<int> rat;
typedef pair<rat,rat> pos;
pos p;
PII dir;
rat distx;
rat disty;

int toint(rat r) { return r.numerator()/r.denominator(); }
bool isint(rat r) { return r == toint(r); }

rat next_int(rat r, int v) {
  if (v == 0) return rat(INF);
  else {
    int res = toint(r);
    if (v > 0) res += 1;
    else if (r == res) res -= 1;
    return (res-r)/v;
  }
}
int nhigh(rat r) { return toint(r) + 1; }
int nlow(rat r) { return isint(r) ? toint(r) - 1 : toint(r); }
char at(int i, int j) { return arr[i][j]; }
string quad(pos p) {
  rat x = p.first;
  rat y = p.second;
  // 01
  // 32
  string s = "";
  s += at(nlow(x), nlow(y));
  s += at(nhigh(x)-1, nlow(y));
  s += at(nhigh(x)-1, nhigh(y)-1);
  s += at(nlow(x), nhigh(y)-1);
  return s;
}

bool update(pos target) {
  // new p
  rat tx = next_int(p.first, dir.first);
  rat ty = next_int(p.second, dir.second);
  rat t = min(tx, ty);
  rat xd = t*dir.first;
  rat yd = t*dir.second;
  if (p.first + xd/2 == target.first &&
      p.second + yd/2 == target.second) {
    xd /= 2;
    yd /= 2;
  }
  // new dist
  distx += abs(xd);
  disty += abs(yd);
  rat x = (p.first += xd);
  rat y = (p.second += yd);
  if (p == target) return true;
  int xi = isint(x) ? toint(x) : 0;
  int yi = isint(y) ? toint(y) : 0;
  // new dir
  string s = quad(p);
  int bl = count(ALL(s), '#');
  if (bl == 3) {
    dir.first = -dir.first;
    dir.second = -dir.second;
  } else if (bl == 2) {
    if (s[0]=='#' && s[1]=='#' ||
	s[2]=='#' && s[3]=='#')
      dir.second = -dir.second;
    else if (s[1]=='#' && s[2]=='#' ||
	     s[3]=='#' && s[0]=='#')
      dir.first = -dir.first;
  } else if (bl == 1) {
    int dx = dir.first;
    int dy = dir.second;
    if (s[0]=='#' && dx < 0 && dy < 0) return false;
    if (s[1]=='#' && dx > 0 && dy < 0) return false;
    if (s[2]=='#' && dx > 0 && dy > 0) return false;
    if (s[3]=='#' && dx < 0 && dy > 0) return false;
  }
  return true;
}

int main() {
  int T; cin >> T; fkr(T) {
    int H, W; long double D; cin >> H >> W >> D;
    //D *= 2;
    pos start;
    fir(H) fjr(W) {
      cin >> arr[i][j];
      if (arr[i][j] == 'X')
	start = MP(rat(i*2+1, 2),rat(j*2+1, 2));
    }
    set<PII > poss;
    for (int xd=-64;xd<=64;xd++)
      for (int yd=-64;yd<=64;yd++) {
	if (gcdll(xd,yd)!=1) continue;
	//if (poss.count(MP(-xd,-yd))) continue; 
	p = start;
	dir = MP(xd,yd);
	distx = 0;
	disty = 0;
	while (true) {
	  if (!update(start)) break;
	  if (distx*distx + disty*disty > D*D) break;
	  if (p == start) { poss.insert(dir); break; }
	}
      }
    cout << "Case #" << (k+1) << ": " << poss.size() << endl;
  }

  return 0;
}
