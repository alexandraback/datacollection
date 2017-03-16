#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

typedef long long int64;
//typedef double old_double;
//#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXN = 110;


int n, m, a[MAXN][MAXN], row[MAXN], col[MAXN];


void read() {
    cin >> n >> m;
    forn(i,n)
        forn(j,m)
            scanf("%d", &a[i][j]);
}


void solve() {
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    forn(i,n) {
        forn(j,m) {
            row[i] = max(row[i], a[i][j]);
            col[j] = max(col[j], a[i][j]);
        }
    }

    bool ok = true;
    forn(i,n)
        forn(j,m)
            ok &= a[i][j] == min(row[i], col[j]);
    if (ok) {
        puts("YES");
        return;
    }

    puts("NO");
}


int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int ts;
	cin >> ts;
	forn(tt,ts) {
		read();
		if (! cin)  throw;
		printf ("Case #%d: ", tt+1);
		solve();
	}
}