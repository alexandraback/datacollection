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

const int N = 10007;

const int ID[4][4] = {
   { 0, 1, 2, 3 },
   { 1, 0, 3, 2 },
   { 2, 3, 0, 1 },
   { 3, 2, 1, 0 }
};

const bool S[4][4] = {
   { 0, 0, 0, 0 },
   { 0, 1, 0, 1 },
   { 0, 1, 1, 0 },
   { 0, 0, 1, 1 }
};

struct num {
   int id;
   bool s;
   num(int id = 0, bool s = 0) : id(id), s(s) { }

   bool operator == (const num &o) const {
      return id == o.id && s == o.s;
   }

   num operator * (const num &o) const {
      num ret;
      ret.id = ID[id][o.id];
      ret.s = S[id][o.id];
      ret.s ^= s;
      ret.s ^= o.s;
      return ret;
   }
} pref[12 * N];
char st[N], ext[12 * N];
int n;
LL x;

num fromString(string str) {
   num ret;
   char c;
   if (str[0] == '-') {
      ret.s = 1;
      c = str[1];
   }
   else c = str[0];

   if (c == '1') ret.id = 0;
   if (c == 'i') ret.id = 1;
   if (c == 'j') ret.id = 2;
   if (c == 'k') ret.id = 3;

   return ret;
}

string toString(num x) {
   string ret = "";
   if (x.s) ret += '-';
   if (x.id == 0) ret += '1';
   if (x.id == 1) ret += 'i';
   if (x.id == 2) ret += 'j';
   if (x.id == 3) ret += 'k';
   return ret;
}

num power(num a, LL b) {
   if (b == 0) return num();
   if (b & 1) return a * power(a, b - 1);
   num r = power(a, b >> 1);
   return r * r;
}

num divide(num a, num b) {
   FOR(i, 4) {
      FOR(s, 2) {
         if (b * num(i, s) == a) return num(i, s);
      }
   }
   assert(false);
   return num();
}

void solve() {

   int T;
   scanf("%d", &T);

   /*
   FOR(i, 4) {
   FOR(j, 4) {
   num a(i), b(j);
   cerr << toString(a * b) << " ";
   }
   cerr << endl;
   }
   */

   for (int test = 1; test <= T; ++test) {
      cerr << "Solving test " << test << " ... " << endl;

      string ans;
      scanf("%d%lld", &n, &x);
      if (x >= 12) x = 12 + x % 4;

      scanf("%s", st);

      FOR(iter, x) {
         FOR(i, n) ext[n * iter + i] = st[i];
      }
      n *= (int)x;

      pref[0] = num();
      for (int i = 0; i < n; ++i) {
         pref[i + 1] = pref[i] * fromString(string() + ext[i]);
      }

      num total = pref[n];

      if (toString(total) != "-1") ans = "NO";
      else {
         int minPref = n + 1;
         for (int i = 1; i <= n; ++i) {
            if (pref[i].id == 1 && !pref[i].s) {
               minPref = i;
               break;
            }
         }
         int maxSuff = n + 1;
         for (int i = n - 1; i >= 0; --i) {
            num suff = divide(total, pref[i]);
            if (suff.id == 3 && !suff.s) {
               maxSuff = n - i;
               break;
            }
         }
         if (minPref + maxSuff < n) ans = "YES";
         else ans = "NO";
      }

      printf("Case #%d: %s\n", test, ans.c_str());
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