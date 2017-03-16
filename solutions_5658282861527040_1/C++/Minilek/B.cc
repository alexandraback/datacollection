#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
using namespace std;
int d;
vector<int> A, B, K;
long long dp[40][2][2][2];
int digs(int x) {
  if (!x) return 0;
  return 1 + digs(x/2);
}
vector<int> digitize(int x, int d) {
  vector<int> v;
  for (int i = 0; i < d; ++i) {
    v.push_back(x&1);
    x >>= 1;
  }
  reverse(v.begin(), v.end());
  return v;
}
long long go(int at, int anya, int anyb, int anyk) {
  if (at == d) return 1;
  long long &ret = dp[at][anya][anyb][anyk];
  if (ret != -1)
    return ret;
  ret = 0;
  for (int x = 0; x <= 1; ++x)
    for (int y = 0; y <= 1; ++y)
      if ((anya||x<=A[at])&&(anyb||y<=B[at])&&(anyk||((x&y)<=K[at]))) {
	int na = anya | (x<A[at]);
	int nb = anyb | (y<B[at]);
	int nk = anyk | ((x&y)<K[at]);
	ret += go(at+1, na, nb, nk);
      }
  return ret;
}
int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  getchar();
  for (int rr = 1; rr <= nocases; ++rr) {
    int a, b, k;
    cin >> a >> b >> k;    
    a--, b--, k--;
    int d1 = digs(a), d2 = digs(b), d3 = digs(k);
    d = max(max(d1, d2), d3);
    if (!d) d++;
    A = digitize(a, d);
    B = digitize(b, d);
    K = digitize(k, d);
    memset(dp, -1, sizeof(dp));
    printf("Case #%d: %lld\n", rr, go(0, 0, 0, 0));
  }
  return 0;
}
