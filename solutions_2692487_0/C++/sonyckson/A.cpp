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
vector<string> vec;

int mat[101][1010010];
int seen[101][1010010];
int val[101];
int ind = -1;
 int A, N;
int doit(int step, int sum) {
//  cout << step << "   " << sum << endl;
  if (sum > 1000000) return 0;
  int &res = mat[step][sum];
  if (seen[step][sum] == ind) return res;
  seen[step][sum] = ind;
  if (step == N) return 0;
  res = 0;
  if (sum > val[step]) {
    return res = doit(step+1, sum+val[step]);
  } else {
    // borro...
    int res1 = doit(step+1, sum)+1;
    // me agrego...
    int res2 = 10000;
    if (sum != 1) res2 = doit(step, sum+sum-1)+1;
    return res = min( res1, res2 );
  }
}
int main() {
  int i,j ,k;
  memset(seen, -1, sizeof(seen));
  int casos; cin >> casos; for (int h = 0 ; h < casos ; ++h ) {
    cin >> A >> N;
    for (i = 0; i < N; ++i) cin >> val[i];
    sort(val, val+N);
    ind ++;
    cout << "Case #" << h+1 << ": " <<  doit(0, A) << endl;
  }return 0;
  
}
