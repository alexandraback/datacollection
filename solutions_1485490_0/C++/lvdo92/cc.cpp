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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.141592653589793
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 111

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

int dx[] = { 1, 1, 2 };
int dy[] = { 2, 3, 3 };
int n, m;
pair<int64, int> a[M], b[M];

int64 solve() {
   int64 res = 0;
   FOR (i, 1, n) {
       int64 sum = 0;
       FOR (j, 1, m) if (b[j].B == a[i].B)
           sum += b[j].A;
       res = max(res, min(sum, a[i].A));
   }
   
   if (n >= 2) {
       REP(kk, 3) {
           int x = dx[kk], y = dy[kk];
           if (x > n || y > n) continue;
           if (a[x].B == a[y].B) {
               int64 sum = 0;
               FOR (i, 1, m) if (b[i].B == a[x].B) sum += b[i].A;
               res = max(res, min(sum, a[x].A + a[y].A));
               continue;
           }
           FOR (k, 1, m) {
               int64 s1 = 0, s2 = 0;
               FOR (i, 1, k) if (a[x].B == b[i].B) s1 += b[i].A;
               FOR (i, k + 1, m) if (a[y].B == b[i].B) s2 += b[i].A;
               s1 = min(s1, a[x].A);
               s2 = min(s2, a[y].A);
               res = max(res, s1 + s2);
           }
       }
   }
   
   if (n == 3) {
       if (a[1].B == a[2].B && a[2].B == a[3].B) {
           int64 sum = 0;
           FOR (i, 1, m) if (b[i].B == a[1].B) sum += b[i].A;
           res = max(res, min(sum, a[1].A + a[2].A + a[3].A));
       }
       else {
           FOR (x, 1, m) FOR (y, x + 1, m) {
               int64 s1 = 0, s2 = 0, s3 = 0;
               FOR (i, 1, x) if (a[1].B == b[i].B) s1 += b[i].A;
               FOR (i, x + 1, y) if (a[2].B == b[i].B) s2 += b[i].A;
               FOR (i, y + 1, m) if (a[3].B == b[i].B) s3 += b[i].A;
               s1 = min(s1, a[1].A);
               s2 = min(s2, a[2].A);
               s3 = min(s3, a[3].A);
               res = max(res, s1 + s2 + s3);
           }
       }
   }
   return res;
}

int main(){
   #ifndef ONLINE_JUDGE
   FileIn("exam"); FileOut("exam");
   #endif
   int test;
   scanf("%d ", &test);
   FOR (tt, 1, test) {
    scanf("%d %d", &n, &m);
    FOR (i, 1, n) scanf("%lld %d", &a[i].A, &a[i].B);
    FOR (i, 1, m) scanf("%lld %d", &b[i].A, &b[i].B);
    int nn = 1;
    FOR (i, 2, n)
    if (a[i].B == a[nn].B) a[nn].A += a[i].A;
    else a[++nn] = a[i];
    n = nn;
    a[0] = b[0] = make_pair(0LL, -1);
    printf("Case #%d: ", tt);
    cout << solve() << endl;
    }
}
   

