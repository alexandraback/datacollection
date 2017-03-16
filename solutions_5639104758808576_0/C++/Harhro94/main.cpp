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

char st[1007];
int smax;

void solve() {

   int T;
   scanf("%d", &T);

   for (int test = 1; test <= T; ++test) {

      scanf("%d %s", &smax, st);
      int ans = 0;
      int cur = 0;
      for (int i = 0; i <= smax; ++i) {
         if (st[i] == '0') continue;
         if (cur >= i) cur += st[i] - '0';
         else {
            ans += i - cur;
            cur += i - cur;
            cur += st[i] - '0';
         }
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