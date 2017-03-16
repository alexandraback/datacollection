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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
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
int n, m, total[N];
char s[N];
int64 ans, first, last, len, pos;
vector <ii> seg;
bool isOk(char c) {
    return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i');
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while (cases--) {
	    scanf(" %s %d ", &s, &n);
	    m = strlen(s); ans = 0; total[0] = 0;
	    first = last = -1; seg.clear();
	    for (int i = 1;i <= m;i++) {
            if ( isOk(s[i - 1]) ) {
                if (first != -1) last = i - 1;
                total[i] = 0;
            }
            else total[i] = total[i - 1] + 1;
            if (total[i] == 1) first = i;
            if (first != -1 && last != -1) {
                if (last - first + 1 >= n) seg.pb(ii(first, last));
                first = last = -1;
            }
	    }
	    if (first != -1 && !isOk(s[m - 1]) ) last = m;
	    if (first != -1 && last != -1 && last - first + 1 >= n) seg.pb(ii(first, last));
	    int k = 0;
	    first = seg[0].ff; last = seg[0].ss;
	    len = last - first + 1;
	    if ( seg.size() == 0 ) {
	        printf("Case #%d: 0\n", ++caseno);
	        continue;
	    }
	    for (int i = 1;i <= m;i++) {
	        if (last - i + 1 < n) {
	            k++;
                first = seg[k].ff; last = seg[k].ss;
	        }
	        pos = max(i + n - 1, first + n - 1);
	        if (k < seg.size()) ans += (m - pos + 1);
        }
        printf("Case #%d: %lld\n", ++caseno, ans);
	}
	return 0;
}
