//include
//------------------------------------------
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
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <complex>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef complex<int> P;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int    INF = 100000000;

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
using namespace std;

int main()
{
  int num;
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    int a, b, ans = 0;
    scanf("%d %d", &a, &b);
    for (int p = a; p < b; p++) {
      int per = 10;
      int min = 1;
      std::map<int, int> mmap;
      while (1) {
        int ama = p % per;
        int back = p - ama;
        if (ama >= min) {
          back /= per;
          int k = 10;
          while (k <= back) {
            k*=10;
          }
          ama *= k;
          if (ama + back <= b && p < ama + back) {
            if (mmap[ama + back] != p) {
              ans++;
              mmap[ama + back] = p;
            }
          }
        }
        min *= 10;
        per *= 10;
        if (per > p) break;
      }
    }
    printf("Case #%d: %d\n", i+1, ans);
  }
  return 0;
}
