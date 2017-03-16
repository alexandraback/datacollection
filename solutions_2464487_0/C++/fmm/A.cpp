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

long long r, t;

long long func(long long n) {
  n--;
  return (2*r + 1 + 2*n)*(n + 1);
}

int main() {
  int T;
  cin >> T;
  for(int testcase = 1; testcase <= T; testcase++) {
    cin >> r >> t;
    long long x = 0;
    for(long long add = 1<<30; add; ) {
      long long nx = x + add;
      if(func(nx) <= t) x = nx; else add >>= 1;
    }
    printf("Case #%d: ",testcase);
    cout << x << endl;
  }
  return 0;
}

