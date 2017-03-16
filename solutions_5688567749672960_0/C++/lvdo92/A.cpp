/***********************************************
* Author - LUONG VAN DO                        *
* Problem
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1000111
#define C 1000000
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int cases, n;
int f[N];
int rev(int x) {
      int res = 0;
      while (x) {
            res = res * 10 + (x % 10);
            x /= 10;
      }
      return res;
}
void init() {
      queue <int> q; q.push(1);
      for (int i = 1;i <= C;i++) f[i] = INF;
      f[1] = 1;
      while ( !q.empty() ) {
            int number = q.front(); q.pop();
            if (f[number + 1] > f[number] + 1) {
                  f[number + 1] = f[number] + 1;
                  q.push(number + 1);
            }
            int d = rev(number);
            if (f[d] > f[number] + 1) {
                  f[d] = f[number] + 1;
                  q.push(d);
            }
      }
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int casesno = 0;
	init();
      scanf("%d", &cases);
      while (cases--) {
            scanf("%d", &n);
            printf("Case #%d: %d\n", ++casesno, f[n]);
      }
	return 0;
}
