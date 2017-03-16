#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>
#include <set> 

#include <algorithm>
#include <cmath>

#include <ctime>
#include <cstdlib>

using namespace std;

#define PATH "C:\\Users\\Malkav\\Desktop\\"
#define debug(x) cerr << fixed << setprecision(3) << "DEBUG: " << #x << " = " << x << endl
#define forn (i, n) for (int i = 0; i < n; ++i)
#define sz(x) ((int)(x.size()))
#define mp make_pair
#define pb push_back

const int N = 20;

long long st[N];

long long a, b;

long long ans;

long long tmp[N];

inline bool is_pal(long long x) {
  int i = 0;
  while (x != 0) {
    tmp[i++] = x % 10;
    x /= 10;
  }
  
  for (int j = 0; j < i; ++j) {
    if (tmp[j] != tmp[i - 1 - j]) {
      return false;
    }
  }
  
  return true;
}

inline void check(const int len) {
  long long num = 0;
  for (int i = 0; i < len; ++i) {
    num *= 10;
    num += st[i];
  }
  num *= num;
  if (a <= num && num <= b && is_pal(num)) {
    ans++;
  }  
}

inline void check1(const int len) {
  for (int i = 0; i < len; ++i) {
    st[2 * len - 1 - i] = st[i];
  }
  check(2 * len);
}

inline void check2(const int len) {
  for (int i = 0; i < len - 1; ++i) {
    st[2 * len - 2 - i] = st[i];
  }
  check(2 * len - 1);
}

inline void gen(const int d) {

  if (d > 0) {
    check1(d);
    check2(d);
  }
  
  if (d < 4) {
    for (int i = (d == 0) ? 1 : 0; i < 10; ++i) {
      st[d] = i;
      gen(d + 1);
    }
  }
}

void solve() {
  ans = 0;
  cin >> a >> b;
  gen(0);
  cout << ans;
}

int main() {
  freopen(PATH"in.txt", "r", stdin);
  freopen(PATH"out.txt", "w", stdout);
  //ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case  #" << i + 1 << ": ";
    solve();
    cout << endl;
  }
  return 0;   
}