//Written by technolt~h
 
#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>
 
#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))
 
#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()
 
#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define ll long long
using namespace std;
 
const double PI = 2.0 * acos (0.0);
 
typedef long long LL;
typedef pair <int, int> PII;
 
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

#define maxn 55
int MAX_ROW = 3;
int m, n, b, e;
char a[maxn][maxn];

bool found;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};

int space[maxn];

bool isBomb(int x, int y) {
    if (x > MAX_ROW)
        return true;
    return y > space[x];
}

bool isEmpty(int x, int y) {
    return !isBomb(x, y);
}

bool inside(int x, int y) {
    return 1 <= x && x <= m && 1 <= y && y <= n;
}

bool canClick(int x, int y) {
    if (isBomb(x, y)) 
        return false;
    REP(k, 9) {
        int i = x + dx[k];
        int j = y + dy[k];
        if (inside(i, j) && isBomb(i,j))
            return false;
    }
    return true;
}

int open, now, click[maxn][maxn];

void doClick(int x, int y) {
    REP(k, 9) {
        int i = x + dx[k];
        int j = y + dy[k];
        if (inside(i, j) && click[i][j] != now) {
            click[i][j] = now;
            open++;
        }
    }
}

bool check() {
    if (e == 1) return true;
    now++;
    open = 0;
    FOR(i, 1, m)
        FOR(j, 1, n)
            if (canClick(i, j))
                doClick(i, j);
    
    return open == e;
}

void att(int row, int maxSpaceInRow, int maxSpace) {
    if (row > MAX_ROW || row > m) {
        
        if (maxSpace == 0 && check()) {
            found = true;
            //PR(space, 3);
        }
        return;
    }
    FORD(curentSpace, min(maxSpaceInRow, maxSpace), 0) {
        space[row] = curentSpace;
        att(row + 1, curentSpace, maxSpace - curentSpace);
        if (found)
            return;
    }
}

int deleted;

void gen() {
    m += deleted;
    FOR (i, 1, m) {
        FOR (j, 1, n) {
            if (i == 1 && j == 1)
                a[i][j] = 'c';
            else 
                a[i][j] = (i <= deleted) ? '.' : (isEmpty(i - deleted, j) ? '.' : '*');
        }
    }
}

int main() {
	freopen("a.inp","r",stdin);
	freopen("a.out","w",stdout);
	int _; cin >> _;
	FOR(test, 1, _) {
        cout << "Case #" << test << ":" << endl;
        cin >> m >> n >> b;
        
        e = m * n - b;
        
        MAX_ROW = 4;
        deleted = 0;
        
        while (e >= n * (MAX_ROW + 2)) {
            deleted += 2;
            e -= n * 2;
            m -= 2;
        }
        found = false;
        while (n * MAX_ROW < e) MAX_ROW++;
        
        att(1, n, e);
        if (e == 0) found = false;
        
        if (!found)
            cout << "Impossible" << endl;
        else { 
            gen();
            FOR(i, 1, m) {
                FOR(j, 1, n)
                    cout << a[i][j];
                cout << endl;
            }
        }
            
	}
}
	
