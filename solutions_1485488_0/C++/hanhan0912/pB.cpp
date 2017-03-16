#include <cstdio>

const double INF = 1e16;
const int qSize = 50000;
const int px[4] = {0, 0, 1, -1};
const int py[4] = {1, -1, 0, 0};

struct QQ{
	double l, h;
}map[200][200];
struct Coord{
	int x, y;
}que[qSize], u;

int fr, bk;
double dis[200][200];

void solve(){
	int n, m;
	double h, val, ht;
	scanf("%lf %d %d", &h, &n, &m);
	for (int i = 0; i < n; i++)	
		for (int j = 0; j < m; j++)
			scanf("%lf", &map[i][j].h);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%lf", &map[i][j].l);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dis[i][j] = INF;
	fr = bk = 0;
	que[bk++] = (Coord){0, 0};
	dis[0][0] = 0;
	while (fr < bk){
		u = que[fr++];
		for (int i = 0, x, y; i < 4; i++){
			x = u.x + px[i];
			y = u.y + py[i];
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (map[x][y].h - map[x][y].l < 50) continue;
			if (map[x][y].l + 50 > map[u.x][u.y].h) continue;
			if (map[x][y].h < map[u.x][u.y].l + 50) continue;
			if (dis[x][y] != INF) continue;
			if (map[x][y].h >= (map[u.x][u.y].l >? h) + 50){
				que[bk++] = (Coord){x, y};
				dis[x][y] = 0;
			}
		}
	}
//	for (int i = 0; i < bk; i++)
//		printf("%d %d\n", que[i].x, que[i].y);
//	while(1);
	fr = 0;
	while (fr != bk){
		u = que[fr++];
		if (fr >= qSize) fr -= qSize;
		for (int i = 0, x, y; i < 4; i++){
			x = u.x + px[i];
			y = u.y + py[i];
			if (x < 0 || x >= n || y < 0 || y >= m) continue;
			if (map[x][y].h < map[u.x][u.y].l + 50) continue;
			if (map[x][y].h - map[x][y].l < 50) continue;
			if (map[x][y].l + 50 > map[u.x][u.y].h) continue;
			val = 0;
			ht = h - dis[u.x][u.y] * 10.0;
			if (ht >= map[x][y].h - 50){
				val = (ht - (map[x][y].h - 50)) / 10.0;
				ht = ht - val * 10.0;
			}
			if (ht >= map[u.x][u.y].l + 20)
				val += 1.0;
			else
				val += 10.0;
			if (val < 0){
				printf("%d %d -> %d %d: %f\n", u.x, u.y, x, y, val);
				while(1);
			}
			if (dis[x][y] > dis[u.x][u.y] + val){
				dis[x][y] = dis[u.x][u.y] + val;
				que[bk++] = (Coord){x, y};
				if (bk >= qSize) bk -= qSize;
			}
		}
	}
	printf("%f\n", dis[n-1][m-1]);
}
int main(){
	int nT;
	scanf("%d", &nT);
	for (int i = 1; i <= nT; i++){
		printf("Case #%d: ", i);
		solve();
	}

	return 0;
}
