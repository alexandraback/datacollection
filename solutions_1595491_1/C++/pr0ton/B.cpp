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
int N, S, p;
int t[111];
int dp[111][111];
int solve(int pos, int surprising) {
  if (surprising < 0) {
    return -(int)1e9;
  }
  if (pos == N) {
    if (surprising == 0) {
      return 0;
    }
    return -(int)1e9;
  }
  int &ret = dp[pos][surprising];
  if (~ret) {
    return ret;
  }
  ret = -(int)1e9;
  for (int s1=0; s1 <= 10; s1++)
  for (int s2=s1; s2 <= s1+2 && s2 <= 10; s2++)
  for (int s3=s2; s3 <= s1+2 && s3 <= 10; s3++) {
    if (s1 + s2 + s3 == t[pos]) {
      ret = max(ret, (s3 >= p ? 1 : 0) + solve(pos+1, surprising - (abs(s3-s1) == 2 ? 1 : 0))); 
    }
  }
  return ret;
}

int main(int argc, char** argv) {
	int runs; s(runs);
  for (int C=1; C <= runs; C++) {
    s(N); s(S); s(p);
    
    for (int i=0; i < N; i++) {
      s(t[i]);
    }
    fill(dp, -1);
    int ans = solve(0, S);
    printf("Case #%d: %d\n", C, ans);
  }
	return 0;
}
