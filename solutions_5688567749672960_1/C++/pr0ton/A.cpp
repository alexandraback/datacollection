#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex> 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb(z)       push_back( z )
#define gcd           __gcd

bool isNum(char c) { return ('0' <= c && c <= '9'); }
template<typename T>
T read(T &res) {
  res = 0; char c, neg = 0;
  do { c=getchar(); } while (!isNum(c) && c != '-');
  if (c == '-') { neg = 1; c = getchar(); }
  while (isNum(c)) { res = res * 10 + c-'0'; c = getchar(); }
  return neg ? -res : res;
}

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define readInt read<int>
#define readLL read<ll>

//37ae83cb1254dc6d8f3f075ebd91cb

ll reversed(ll n) {
  char buf[20];
  sprintf(buf, "%lld", n);
  int len = strlen(buf);
  reverse(buf, buf + len);
  sscanf(buf, "%lld", &n);
  return n;
}


const int MXN = 1000009;
int dp[MXN];

void xdebug(int n) {
  
    cout << n <<  "\n";
    while (n != 1) {
      int nn = n - 1;
      int nn2 = reversed(n);
      if (nn2 < n && n%10 != 0 && dp[nn2] < dp[nn]) {
        n = nn2;
        cout << n << "\n" ;
      } else {
        n = nn;
      }
    }
    cout << endl;
}

ll solve(ll a) {
  if (a < 10) return a;
  
  if (a % 10 == 0) {
    //cout << a << " to4 " << a - 1 << endl;
    return 1 + solve(a - 1);
  }
  
  char buf[20];
  sprintf(buf, "%lld", a);
  int n = strlen(buf);
  
  for (int i = n/2; i < n; i++) {
    buf[i] = '0';
  }
  buf[n - 1] = '1';
  buf[n] = 0;
  
  ll res = a;
  ll aRev = reversed(a);
  if (aRev < a) {
    res = min(res, 1 + solve(aRev));
  }
  ll cost = 0;
  ll preRev;
  sscanf(buf, "%lld", &preRev);
  if (preRev < a) {
    
    cost += a - preRev;
    //cout << a << " to1 " << preRev << endl;
    
    ll rev = reversed(preRev);
    if (rev != preRev) {
      //cout << preRev << " to2 "  << rev << endl;
      res = min(res, cost + 1 + solve(rev));
    } else {
      //cout << preRev << " to3 "  << preRev - 1 << endl;
      res = min(res, cost + 1 + solve(preRev - 1));
    }
  } else {
    res = min(res, 1 + solve(preRev - 1));
  }
  return res;
}
int main() {
  int T;
  cin>>T;
  for (int i=1; i < MXN; i++) {
    dp[i] = i;
  }
  for (int i=1; i < MXN; i++) {
    ll irev = reversed(i);
    dp[i] = 1 + dp[i-1];
    if (irev < i && i%10 != 0)
      dp[i] = min(dp[i], 1 + dp[irev]);
  }
  
  for (int c=1; c <= T; c++) {
    ll n; cin>>n;
    //xdebug(n);
    ll a1 = solve(n);
    if (n < MXN) {
      ll a2 = dp[n];
      //cout << a1 << " " << a2 << endl;
      assert(a1 == a2);
    }
    cout << "Case #" << c << ": " << a1 << endl;
  }
}
