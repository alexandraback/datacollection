#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define REP(i, n) for(int i=0;i<int(n);i++)
#define PB push_back
#define MP(X,Y) make_pair(X,Y)
#define SZ(X) ((int)(X.size()))
typedef  long long   ll;


#define ALL(x)   (x).begin(),(x).end()
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> II;
typedef vector<II> VII;
#define foreach(it, c)  for(typeof((c).begin()) it = (c).begin();it!=(c).end();++it)
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
template<class T> inline T gcd(T a, T b){ return b?gcd(b, a%b):a;}
const double EPS = 1e-9;
const double PI = acos(-1.0);

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}


int N, X, Y;

long double dp[2000][2000];
bool visited[2000][2000];
int target, sum, MX;

long double doit(int left, int right) {
  long double &res = dp[left][right];
  if (visited[left][right]) return res;
  visited[left][right] = true;
  if (left == target) return res = 1.;
  if (left+right == sum) return res = 0.;
  if (right == MX) return res = doit(left+1, right);
  return res = 0.5 * doit(left+1, right) + 0.5 * doit(left, right+1);
}


int main() {
  int i,j ,k;
  int casos; cin >> casos;
  for (int h = 0 ;h  < casos; ++h) {
    cin >> N >> X >> Y;
    // vamos vaciando las capas... 
    long double res = -1;
    if (N == 1) {
      if (!X && !Y) res = 1.;
      else res = 0.;
    } else if ((abs(X)+abs(Y)) % 2) {
      res = 0.;         
    } else {
      int next = 0;
      N--;
      for (i = 2; N > i+i+1; i += 2) { next = i + i + 1; N -= (i+i+1); }
      next = i + i + 1;
      //cout << i << "  "  << N << "   " << next<< endl;
      // nos fijamos si es posicion de adentro...
      if (abs(X)+abs(Y) > i) {
        res = 0.;
      } else
      if (abs(X)+abs(Y) < i or next == N) {
        res = 1.;
      } else if (Y == i) {
        res = 0.;
      } else {
        memset(visited, false, sizeof(visited));
        sum = N;
        MX = i;
        target = Y+1;
//        cout << target << "  " << MX << "  " << sum <<  endl;
        res = doit(0,0);
//        cout << res << endl;
      }
    }
    printf("Case #%d: %.10Lf\n", h+1, res);
  }
  return 0;
}
