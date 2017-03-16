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
ll solve(ll n) {
  ll ans = n;
  return ans;
}

const int MXN = 1000009;
int dp[MXN];

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
    cout << "Case #" << c << ": " << dp[n] << endl;
  }
}
