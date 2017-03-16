#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <functional>
#include <string>

#define MAXN 150005
#define trans(x) ((x)-'i'+2)
#define sgn(x) (((x) >= 0) ? 1 : -1)

using namespace std;

const long I = 2, J = 3, K = 4;
long multArr[][5] =
   {
     {0, 0, 0, 0, 0},
     {0, 1, I, J, K},
     {0, I, -1, K, -J},
     {0, J, -K, -1, I},
     {0, K, J, -I, -1}
   };

long mult(long x, long y) { return sgn(x)*sgn(y)*multArr[abs(x)][abs(y)]; } 
long inv(long x) { return (abs(x) == 1) ? x : -x; }

long n;
bool dp[MAXN][9][9];
char s[MAXN], p[MAXN], A[MAXN];

long rep(long l, long x) {
   for (long i = 0; i < l; i++)
      A[i] = trans(s[i]);
   for (long i = l; i < l*x; i++)
      A[i] = A[i-l];
   return l*x;
}

#define F(x) ((x) + 4)

bool solve() {
   p[0] = A[0];

   for (long i = 1; i < n; i++)
      p[i] = mult(p[i-1], A[i]);

   /* Initialize DP array */
   for (long x = -4; x <= 4; x++) {
      if (!x) continue;
      for (long y = -4; y <= 4; y++) {
         if (!y) continue;
         dp[n-2][F(x)][F(y)] = A[n-2] == x && A[n-1] == y;
      }
   }
   
   /* DP */
   for (long i = n-3; i >= 0; i--) {
      for (long x = -4; x <= 4; x++) {
         if (!x) continue;
         for (long y = -4; y <= 4; y++) {
            if (!y) continue;
            dp[i][F(x)][F(y)] = dp[i+1][F(mult(inv(A[i]), x))][F(y)];
            if (A[i] == x && mult(inv(p[i]), p[n-1]) == y)
               dp[i][F(x)][F(y)] = true;
         }
      }
   }

   for (long i = 0; i <= n-3; i++)
      if (p[i] == I && dp[i+1][F(J)][F(K)])
         return true;

   return false;
}

int main() {
   long T, l, x;

   scanf("%ld", &T);

   for (long t = 1; t <= T; t++) {
      scanf("%ld%ld\n%s", &l, &x, s);
      n = rep(l, min(x, 12 + x%4));
      //n = rep(l, x);
      printf("Case #%ld: %s\n", t, solve() ? "YES" : "NO");
   }
	return 0;
}
