#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char a[105][105];
int n, m, D;
int SIZE;
int onestep(int x, int y, int &p, int &q) {
	if(x%SIZE==0 && y%SIZE==0) {
		int u = x/SIZE, v = y/SIZE;
		if(p<0) --u; if(q<0) --v;
		if(a[u][v] != '#') return 1;
		int href = (a[u+(p<0?1:-1)][v] == '#');
		int vref = (a[u][v+(q<0?1:-1)] == '#');
		if(!vref && !href) return 0;
		if(vref) p=-p;
		if(href) q=-q;
	} else if(x%SIZE==0) {
		int u = x/SIZE, v = y/SIZE;
		int vref = (a[u-(p<0)][v]=='#');
		if(vref) p=-p;
	} else if(y%SIZE==0) {
		int u = x/SIZE, v = y/SIZE;
		int href = (a[u][v-(q<0)]=='#');
		if(href) q=-q;
	}
	return 1;
}

//int uu[505][505]={}, uucs, OFFSET=200;

int go(int sx, int sy, int p, int q) {
	//if(uu[p+OFFSET][q+OFFSET] == uucs) return 0;
	//Every cell *abs(p)*abs(q)*2;
	SIZE = abs(p)*abs(q)*2;
	sx = sx*SIZE+SIZE/2;
	sy = sy*SIZE+SIZE/2;
	int T = 1LL*SIZE*SIZE*D*D / (p*p+q*q);
	int x = sx, y = sy;
	for(int t=1;t*t<=T;t++) {
		x += p; y += q;
		int r = onestep(x, y, p, q);
		if (r == 0) return 0;
		if (x == sx && y == sy) {
			//uu[-p+OFFSET][-q+OFFSET] = uucs;
			return 1;
		}
	}
	return 0;
}

void solve() {
	scanf("%d%d%d", &n, &m, &D);
	for(int i=0;i<n;i++) scanf("%s", a[i]);
	int sx=0, sy=0, ans = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i][j] == 'X')
				sx = i, sy = j;
	for(int i=sy+1;a[sx][i];i++) if(a[sx][i]=='#') { ans += (2*(i-sy-1)+1 <= D); break; }
	for(int i=sy-1;i>=0;i--) if(a[sx][i]=='#') { ans += (2*(sy-i-1)+1 <= D); break; }
	for(int i=sx+1;a[i][sy];i++) if(a[i][sy]=='#') { ans += (2*(i-sx-1)+1 <= D); break; }
	for(int i=sx-1;i>=0;i--) if(a[i][sy]=='#') { ans += (2*(sx-i-1)+1 <= D); break; }
	//++uucs;
	for(int p=1;p<=D*2;p++)
		for(int q=1;q<=D*2;q++)
			if(__gcd(p, q) == 1) {
				ans += go(sx, sy, p, q);
				ans += go(sx, sy, -p, q);
				ans += go(sx, sy, p, -q);
				ans += go(sx, sy, -p, -q);
				//printf("p=%d, q=%d, %d\n", p, q, ans);
			}
	static int cs=0;
	printf("Case #%d: %d\n", ++cs, ans);
}

int main(void) {
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}

