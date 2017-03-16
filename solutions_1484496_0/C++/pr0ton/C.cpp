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

int a[555], n;
int sum[1<<20];

int main(int argc, char** argv) {
	
  int runs; s(runs);
  for (int C=1; C <= runs; C++) {
    s(n);
    for (int i=0; i < n; i++) s(a[i]);
    sort(a, a+n);
    for (int z=0; z < (1<<n); z++) {
      sum[z] = 0;
      for (int i=0; i < n; i++) {
        if (z & 1<<i)
          sum[z] += a[i];
      }
    }
    int x[22], y[22];
    bool found = 0;
    printf ("Case #%d:\n", C);
    for (int m=1; m+1 < (1<<n) && !found; m++) {
      int leSum = sum[m];
      int comp = m ^ ( (1<<n) - 1 );
      for (int sub=comp; sub > 0; sub = (sub-1)&comp) {
        int reSum = sum[sub];
        if (leSum == reSum) {
          bool ok = 1;          
          int xp = 0, yp = 0;
          for (int i=0; i < n; i++)
          if (m & 1<<i) x[xp++] = i;
          for (int i=0; i < n; i++)
          if (sub & 1<<i) y[yp++] = i;
          if (xp == yp) {
            ok = 0;
            for (int i=0; i < xp; i++)
            if (a[x[i]] != a[y[i]])
              ok = 1;
          }
          if (ok) {
            for (int i=0; i < xp; i++) printf("%d ", a[x[i]]); puts("");
            for (int i=0; i < yp; i++) printf("%d ", a[y[i]]); puts("");
            found = 1;
            break;
          }
        }
      }
    }
    if (!found) {
      puts("Impossible");
    }
  }
	return 0;
}
