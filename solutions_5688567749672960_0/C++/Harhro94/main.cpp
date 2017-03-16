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
vector<int> G[N];
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
   Q[r++] = 1;
   dist[1] = 1;
   while (l < r) {
      int u = Q[l++];
      for (int to : G[u]) {
         if (dist[to] > dist[u] + 1) {
            dist[to] = dist[u] + 1;
            Q[r++] = to;
         }
      }
   }
}

LL pw10[20];

LL greedy(LL n) {
   if (n <= 100) return dist[(int)n];
   vector<int> dig;
   for (LL t = n; t; t /= 10) dig.pb(t % 10);
   reverse(all(dig));
   LL sum = 0;
   LL cur = 1;
   int len = 1;
   while (true) {
      sum += pw10[len] - cur;
      ++len;
      if (len == sz(dig)) break;
      sum += 9;
      cur = pw10[len - 1] + 9;

      sum += 1;
      cur = 9 * pw10[len - 1] + 1;
   }
   return 0;
}

void solve() {

   for (int i = 1; i < N - 1; ++i) {
      G[i].pb(i + 1);
      int to = rev(i);
      if (to > i && to < N) G[i].pb(to);
   }

   bfs();

   int T;
   scanf("%d", &T);
   for (int test = 1; test <= T; ++test) {
      int n;
      scanf("%d", &n);
      printf("Case #%d: %d\n", test, dist[n]);
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