//Author: Harhro94 [Harutyunyan Hrayr]
//#pragma comment(linker, "/STACK:667777216")
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
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
using namespace std;

#define FOR(i, n) for (int i = 0; i < (n); ++i)
typedef long long LL;
typedef long double LD;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
int rd();

const int N = 1000007;
int dist[N], Q[N];

int rev(int x) {
   int ret = 0;
   for (; x; x /= 10) {
      ret = 10 * ret + x % 10;
   }
   return ret;
}

void bfs() {
   FOR(i, N) dist[i] = N;
   int l = 0, r = 0;
   Q[r++] = 0;
   dist[0] = 0;
   while (l < r) {
      int u = Q[l++];
      FOR(i, 2) {
         int to;
         if (i == 0) to = u + 1;
         else to = rev(u);
         if (to >= N) continue;
         if (dist[to] > dist[u] + 1) {
            dist[to] = dist[u] + 1;
            Q[r++] = to;
         }
      }
   }
}

LL pw10[20];

LL greedy(LL n) {
   if (n < 10) return n;
   vector<int> dig;
   for (LL t = n; t; t /= 10) dig.pb(t % 10);
   reverse(all(dig));

   LL sum = 0;
   int len = 1;
   while (len != sz(dig)) {
      sum += pw10[(len + 1) / 2] - 1; //1...999
      if (len != 1) {
         sum += 1; // rev
         sum += pw10[len / 2] - 1;
      }
      else ++sum;
      ++len;
   }

   bool flag = true;
   for (int i = 0; i < len / 2; ++i) {
      if (i == 0 && dig[i] != 1) flag = false;
      if (i > 0 && dig[i] != 0) flag = false;
   }

   if (flag) return sum + n - pw10[len - 1];

   bool bad = true;
   for (int i = 0; i < sz(dig) / 2; ++i) {
      if (dig[sz(dig) - 1 - i] != 0) {
         bad = false;
         break;
      }
   }
   if (bad) return greedy(n - 1) + 1;

   LL t = 0;
   for (int i = len / 2 - 1; i >= 0; --i) {
      t = 10 * t + dig[i];
   }
   sum += t;

   sum += 1; // rev

   t = 0;
   for (int i = len - 1 - (len + 1) / 2 + 1; i < len; ++i) {
      t = 10 * t + dig[i];
   }
   sum += t - 1;
   return sum;
}

void solve() {

   pw10[0] = 1;
   for (int i = 1; i < 20; ++i) pw10[i] = 10 * pw10[i - 1];

   /*
   bfs();
   greedy(211);
   for (int i = 1; i < N; ++i)
      if (dist[i] != greedy(i)) {
         cerr << i << " " << dist[i] << " " << greedy(i) << endl;
         assert(false);
      }
   */
   int T;
   scanf("%d", &T);
   for (int test = 1; test <= T; ++test) {
      LL n;
      scanf("%lld", &n);
      printf("Case #%d: %lld\n", test, greedy(n));
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