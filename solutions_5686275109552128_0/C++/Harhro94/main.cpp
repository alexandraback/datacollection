// Author: Harhro94 [Harutyunyan Hrayr]
//#pragma comment(linker, "/STACK:66777216")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); ++i)
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
int rd();

int foo(int x, int m) {
   if (x <= m) return 0;
   return (x - m + m - 1) / m;
}

void solve() {

   int T;
   scanf("%d", &T);

   for (int test = 1; test <= T; ++test) {

      int n;
      scanf("%d", &n);
      vector<int> a(n);
      FOR(i, n) scanf("%d", &a[i]);
      sort(all(a));

      int ans = a[n - 1];
      for (int m = 1; m <= a[n - 1]; ++m) {
         int cur = m;
         FOR(i, n) cur += foo(a[i], m);
         ans = min(ans, cur);
      }

      printf("Case #%d: %d\n", test, ans);
   }

}

int rd() {
   return (((LL)rand() << 16) ^ rand()) % 1000000000;
}

void testGen() {
   FILE *f = fopen("input.txt", "w");
   fclose(f);
}

int main() {
#ifdef harhro94
   //testGen();
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#else
#define task "ghosts"
   //freopen(task".in", "r", stdin);
   //freopen(task".out", "w", stdout);
#endif

   cerr << fixed;
   cerr.precision(9);

   solve();

#ifdef harhro94
   cerr << fixed << setprecision(3) << "\nExecution time = " << clock() / 1000.0 << "s\n";
#endif
   return 0;
}