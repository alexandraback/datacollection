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

int n;
int a[222];
int main(int argc, char** argv) {
	int runs; s(runs);
  for (int C=1; C <= runs; C++) {
    s(n); 
    for (int i=0; i < n; i++) {
      s(a[i]);
    }
    int t = 0; for (int i=0; i < n; i++) t += a[i];
    double lo = 0, hi = 1e9;
    for (int its=0; its < 100; its++) {
      double mn = (lo+hi)/2;
      double xsum = 0;
      for (int i=0; i < n; i++)
      if (a[i] < mn) {
        double x = (mn - a[i]) / t;
        xsum += x;
      }
      if (xsum > 1) {
        hi = mn;
      } else {
        lo = mn;
      }
    }
    printf("Case #%d: ", C);
    double mn = (lo+hi)/2;
    for (int i=0; i < n; i++) {
      printf("%.10lf ", 100 * max(0.0, (mn - a[i]) / t));
    }
    puts("");
  }
	return 0;
}
