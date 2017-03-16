#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

#define rep(x,n) for(int x = 0; x < n; ++x)
#define print(x) cout << x << endl
#define dbg(x) cerr << #x << " == " << x << endl
#define _ << " , " <<
#define mp make_pair
#define x first
#define y second

using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;
typedef pair<int,int> pii;

long long E;
long long R;
int N;
long long v[11111];

long long f[111][111];

long long go(int have, int i) {
  if(have>E) have=E;
  if(i>=N) return 0;
  long long &res = f[have][i];
  if(res != -1) return res;
  res = 0;
  for(int j=0;j<=have;j++) {
    res=max(res,j*v[i]+go(have-j+R,i+1));
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  for(int testcase = 1; testcase <= T; testcase++) {
    cin >> E >> R >> N;
    rep(i,N) cin >> v[i];
    memset(f,-1,sizeof f);
    printf("Case #%d: ",testcase);
    cout << go(E,0) << endl;
  }
  return 0;
}

