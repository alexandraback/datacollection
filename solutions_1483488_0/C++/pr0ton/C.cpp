#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>
 
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
#include<cassert>

#define oo            (int)13e7
#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;

const int mxn = 2000007;
int minrep[mxn];

int rshift(int x) {
  int a[10], n=0;
  int v = x;
  while (x > 0) {
    a[n++] = x%10;
    x /= 10;
  }
  reverse(a, a+n);
  
  for (int i=0; i < n; i++) {
    int c = 0;
    for (int j=0, k=i; j < n; j++, k++) {
      if (k >= n) k -= n;
      c = c*10 + a[k];
    }
    v = min(v, c);
  }
  return v;
}
int c[mxn];
int main(int argc, char** argv) {
  assert(rshift(3412) == 1234);
  assert(rshift(1200) == 12);
  assert(rshift(2010) == 102);
  for (int i=1; i < mxn; i++)
    minrep[i] = rshift(i);
  int runs; s(runs);
  for (int C=1; C <= runs; C++) {
    int a, b;
    s(a); s(b);
    fill(c, 0);
    for (int x=a; x <= b; x++) {
      c[ minrep[x] ]++;
    }
    ll res = 0;
    for (int i=1; i <= b; i++) {
      res += c[i] * (c[i] - 1LL) / 2;
    }
    printf("Case #%d: %lld\n", C, res);
  }
	return 0;
}
