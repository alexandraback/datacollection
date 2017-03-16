#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define PI acos(-1.0)
#define MP make_pair
#define PB push_back
#define SET(a,v) memset(a, v, sizeof(a))

#define VI vector <int>
#define PII pair <int, int>
#define LL long long 

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,a,b) for (int i = a; i > b; i--)
#define FIT(it,v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define FALL(i,v) for (int i = 0; i < (v.size()); i++)

#define maxn 110

int c[maxn][maxn], f[maxn][maxn], h, n, m;
double d[maxn][maxn];
bool ok[maxn][maxn];
int cd[] = {1, -1, 0, 0}, cc[] = {0, 0, 1, -1};

int cmp(double x, double y) {
    if (fabs(x - y) <= 0.000000001) return 0;
    if (x < y) return -1;
    return 1;    
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int _;
    cin >>_;
    FOR (test, 1, _) {
        cin >> h >> m >> n;
        FOR (i, 1, m)
        FOR (j, 1, n) cin >> c[i][j];
        
        FOR (i, 1, m)
        FOR (j, 1, n) cin >> f[i][j];
        
        SET (ok, false);
        FOR (i, 1, m)
        FOR (j, 1, n) d[i][j] = 1000000;
        
        d[1][1] = 0;
        int u, v, x, y;
        while (!ok[m][n]) {
              u = v = 0;
              FOR (i, 1, m)
              FOR (j, 1, n)
                  if (!ok[i][j] && (u == 0 || cmp(d[u][v], d[i][j]) == 1)) {
                     u = i;
                     v = j;             
                  }
              
              ok[u][v] = true;
             // cout << u << " " << v << " " << d[u][v];
              FOR (hh, 0, 3) {
                  x = u + cd[hh];    
                  y = v + cc[hh];
                  
                  if (1 <= x && x <= m && 1 <= y && y <= n) 
                  if (f[u][v] + 50 <= c[x][y] && f[x][y] + 50 <= c[x][y] && f[x][y] + 50 <= c[u][v]){
                     double time = 0;
                     if (cmp(h - 10 * d[u][v] + 50, c[x][y]) == 1)
                        time = (h - 10 * d[u][v] + 50 - c[x][y]) / 10.0;          
                    // cout << h << " " << c[x][y] << endl;
                    
                     if (cmp(time + d[u][v], 0) != 0) 
                     if (cmp(h - 10 * (d[u][v] + time) - f[u][v], 20) >= 0) time += 1;
                     else time += 10;
                     
                     if (!ok[x][y] && cmp(d[x][y], d[u][v] + time) == 1) d[x][y] = d[u][v] + time;
                  }
              }
        }
        
        printf("Case #%d: %.9lf\n", test, d[m][n]);
    }
    
    return 0;   
}
