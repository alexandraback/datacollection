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

unsigned long long r, t;

unsigned long long func(unsigned long long n) {
  n--;

  unsigned long long a = (2*r + 1 + 2*n);
  unsigned long long b = (n + 1);

  if(a > t || b > t) return 0;
  if(a > t/b + 3) return 0;
  if(b > t/a + 3) return 0;

  return a * b <= t;
}

int main() {
  int T;
  cin >> T;
  for(int testcase = 1; testcase <= T; testcase++) {
    cin >> r >> t;
    unsigned long long x = 0;
    for(unsigned long long add = 1e18; add; ) {
      unsigned long long nx = x + add;
      if(func(nx)) x = nx; else add >>= 1;
    }
    printf("Case #%d: ",testcase);
    cout << x << endl;
  }
  return 0;
}

