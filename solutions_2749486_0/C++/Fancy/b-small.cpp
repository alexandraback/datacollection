#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 250;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char* DIR = "NESW";


struct sta {
	int x, y, c, d;
	sta(int x, int y, int c, int d) : x(x), y(y), c(c), d(d) {}
};

int d[505][505][505];
bool vst[505][505][505];

void init() {
	queue<sta> q;
	vst[0][0+N][0+N] = true;
	q.push(sta(0, 0, 0, -1));
	while(!q.empty()) {
		sta s = q.front(); q.pop();
		for(int i=0; i<4; ++i) {
			int nx = s.x + (s.c+1)*dx[i];
			int ny = s.y + (s.c+1)*dy[i];
			if(abs(nx)>N || abs(ny)>N || vst[s.c+1][nx+N][ny+N]) continue;
			d[s.c+1][nx+N][ny+N] = i;
			vst[s.c+1][nx+N][ny+N] = true;
			if(s.c+1 < 500) q.push(sta(nx, ny, s.c+1, i));
		}
	}
}

void print(int n, int x, int y) {
//	printf("%d %d %d\n", n, x, y);
	if(!x && !y) return ;
	int dir = d[n][x+N][y+N];
	int px = x - n*dx[dir];
	int py = y - n*dy[dir];
	print(n-1, px, py);
	putchar(DIR[dir]);
}

void gao() {
	int x, y;
	scanf("%d%d", &x, &y);
	for(int i=0; i<abs(x); ++i) {
		if(x > 0) printf("WE");
		else printf("EW");
	}
	for(int i=0; i<abs(y); ++i) {
		if(y > 0) printf("SN");
		else printf("NS");
	}
	puts("");
}

int main() {
	int T; scanf("%d", &T);
	for(int cas=1; cas<=T; ++cas) {
		printf("Case #%d: ", cas); gao();
	}
}
