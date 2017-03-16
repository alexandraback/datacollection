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
#define N 111

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
int n, m, ans;
char s[N];
bool isOk(char c) {
    return (c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i');
}
bool check(int x, int y, int k) {
    int best = 0, cnt = 0;
    while (x <= y && isOk(s[x])) x++;
    if ( x <= y ) cnt = 1;
    for (int i = x + 1;i <= y;i++)
        if ( !isOk(s[i]) ) cnt++;
        else {
            best = max(best, cnt);
            cnt = 0;
        }        
    best = max(best, cnt);
    return best >= k;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while (cases--) {
	    scanf(" %s %d ", &s, &n);
	    m = strlen(s); ans = 0;
	    for (int i = 0;i < m;i++)
            for (int j = i;j < m;j++)
                if (check(i, j, n)) ans++;
        printf("Case #%d: %d\n", ++caseno, ans);
	}
	return 0;
}
