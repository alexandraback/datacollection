#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

#define INF 100000000
#define MAX 1048576

using namespace std;

int r,h,n,m;

int c[105][105], f[105][105], v[105][105];
double b[105][105];

int canMove(int y, int x, int yd, int xd) {
    if (x + xd < 0 || x + xd >= m) return false;
    if (y + yd < 0 || y + yd >= n) return false;
    
    int nx = x + xd, ny = y + yd;
    
    if (f[ny][nx] > c[ny][nx] - 50) return false;
    if (f[ny][nx] > c[y][x] - 50) return false;
    if (f[y][x] > c[ny][nx] - 50) return false;
    
    return true;
}
int main() {
    scanf("%d", &r);
    
    for (int z=0; z<r; ++z) {
	scanf("%d%d%d", &h, &n, &m);
	
	for (int i=0; i<105; ++i) for (int j=0; j<105; ++j) v[i][j] = 0, b[i][j] = -100000000;
	b[0][0] = h;
	
	for (int i=0; i<n; ++i) {
	    for (int j=0; j<m; ++j) {
		scanf("%d", &c[i][j]);
	    }
	}
	for (int i=0; i<n; ++i) {
	    for (int j=0; j<m; ++j) {
		scanf("%d", &f[i][j]);
	    }
	}
	while (true) {
	    int bx = -1, by = -1, isHigh = false;
	    for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
		    if (!v[i][j] && (bx == -1 || b[i][j] > b[bx][by])) bx = i, by = j;
		}
	    }
	    if (bx == -1 && by == -1) break;
	    if (b[bx][by] == h) isHigh = true;
	    v[bx][by] = true;
	    int rem = b[bx][by];
	    if (canMove(bx, by, -1, 0)) {
		int st = min(c[bx-1][by] - 50, rem);
		b[bx-1][by] = max((double)st + (st == h ? 0 : (st >= f[bx][by] + 20 ? -10 : -100)), b[bx-1][by]);
	    }
	    if (canMove(bx, by, 1, 0)) {
		int st = min(c[bx+1][by] - 50, rem);
		b[bx+1][by] = max((double)st + (st == h ? 0 : (st >= f[bx][by] + 20 ? -10 : -100)), b[bx+1][by]);
	    }
	    if (canMove(bx, by, 0, -1)) {
		int st = min(c[bx][by-1] - 50, rem);
		b[bx][by-1] = max((double)st + (st == h ? 0 : (st >= f[bx][by] + 20 ? -10 : -100)), b[bx][by-1]);
	    }
	    if (canMove(bx, by, 0, 1)) {
		int st = min(c[bx][by+1] - 50, rem);
		b[bx][by+1] = max((double)st + (st == h ? 0 : (st >= f[bx][by] + 20 ? -10 : -100)), b[bx][by+1]);
	    }
	}
	printf("Case #%d: %lf\n", z+1, (double)(h - b[n-1][m-1]) / 10);
    }
   
    return 0;
}