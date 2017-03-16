#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 24, aa[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
class Q{
public:
	int x, y;
}now[N];
int T, x, r, c, cnt;
char a[N][N], rl[N][N];
bool succ;
void bl(int x, int y){
	++cnt;
	rl[x][y] = 1;
	for (int i = 0; i < 4; ++i){
		int nx = x + aa[i][0], ny = y + aa[i][1];
		if (nx > 0 && ny > 0 && nx <= r && ny <= c && rl[nx][ny] == 0) bl(nx, ny);
	}
}
void tr(int t){
	if (t > x){
		bool ok = false;
		//for (int i = 1; i <= x; ++i) printf("now%d %d\n", now[i].x, now[i].y);
		//printf("\n");
		for (int i = 1; i <= r; ++i){
			for (int j = 1; j <= c; ++j){
				memset(rl, 0, sizeof(rl));
				bool bo = true;
				for (int k = 1; k <= x; ++k){
					int nx = now[k].x - 6 + i, ny = now[k].y - 6 + j;
					if (nx > 0 && ny > 0 && nx <= r && ny <= c){
						rl[nx][ny] = 1;
						//printf("pos %d %d\n", nx, ny);
					}
					else{
						bo = false;
						break;
					}
				}
				//printf("rl[2][2] = %d\n", rl[2][2]);
				if (bo){
					/*for (int ii = 1; ii <= r; ++ii){
						for (int jj = 1; jj <= c; ++jj){
							printf("asd %d ", rl[ii][jj]);
						}
						printf("\n");
					}
					printf("\n");*/
					for (int ii = 1; ii <= r; ++ii){
						for (int jj = 1; jj <= c; ++jj){
							if (rl[ii][jj] == 0){
								cnt = 0;
								bl(ii, jj);
								//printf("cnt = %d ", cnt);
								if (cnt % x != 0){
									//printf("ERR\n");
									bo = false;
									break;
								}
							}
							//printf("%d ", rl[ii][jj]);
						}
						if (!bo) break;
						//printf("\n");
					}
					//printf("\n");
					//printf("bo = %d\n", bo);
					if (bo){
						ok = true;
						//printf("ok = %d\n", ok);
						break;
					}
				}
				//printf("\n");
			}
			if (ok) break;
		}
		for (int i = 1; i <= x; ++i) swap(now[i].x, now[i].y);
		for (int i = 1; i <= r; ++i){
			for (int j = 1; j <= c; ++j){
				memset(rl, 0, sizeof(rl));
				bool bo = true;
				for (int k = 1; k <= x; ++k){
					int nx = now[k].x - 6 + i, ny = now[k].y - 6 + j;
					if (nx > 0 && ny > 0 && nx <= r && ny <= c){
						rl[nx][ny] = 1;
						//printf("pos %d %d\n", nx, ny);
					}
					else{
						bo = false;
						break;
					}
				}
				//printf("rl[2][2] = %d\n", rl[2][2]);
				if (bo){
					/*for (int ii = 1; ii <= r; ++ii){
						for (int jj = 1; jj <= c; ++jj){
							printf("asd %d ", rl[ii][jj]);
						}
						printf("\n");
					}
					printf("\n");*/
					for (int ii = 1; ii <= r; ++ii){
						for (int jj = 1; jj <= c; ++jj){
							if (rl[ii][jj] == 0){
								cnt = 0;
								bl(ii, jj);
								//printf("cnt = %d ", cnt);
								if (cnt % x != 0){
									//printf("ERR\n");
									bo = false;
									break;
								}
							}
							//printf("%d ", rl[ii][jj]);
						}
						if (!bo) break;
						//printf("\n");
					}
					//printf("\n");
					//printf("bo = %d\n", bo);
					if (bo){
						ok = true;
						//printf("ok = %d\n", ok);
						break;
					}
				}
				//printf("\n");
			}
			if (ok) break;
		}
		for (int i = 1; i <= x; ++i) swap(now[i].x, now[i].y);
		//printf("ok = %d\n", ok);
		if (!ok){
			succ = false;
		}
		return;
	}
	Q can[N];
	bool b[N][N];
	memset(b, 0, sizeof(b));
	int tot = 0;
	for (int i = 1; i < t; ++i)
		for (int j = 0; j < 3; ++j){
			int nx = now[i].x + aa[j][0], ny = now[i].y + aa[j][1];
			if (nx > 0 && ny > 0 && nx <= 12 && ny <= 12 && a[nx][ny] == 0 && b[nx][ny] == 0){
				b[nx][ny] = 1;
				can[++tot].x = nx, can[tot].y = ny;
			}
		}
	for (int i = 1; i <= tot; ++i){
		a[can[i].x][can[i].y] = 1;
		now[t].x = can[i].x, now[t].y = can[i].y;
		tr(t + 1);
		if (!succ) return;
		a[can[i].x][can[i].y] = 0;
	}
}
int main(){
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti){
		scanf("%d%d%d", &x, &r, &c);
		if (x >= 7 || x > max(r, c) || (x + 1) / 2 > min(r, c) || r * c % x != 0){
			printf("Case #%d: RICHARD\n", Ti);
			continue;
		}
		memset(a, 0, sizeof(a));
		succ = true;
		now[1].x = 6, now[1].y = 6;
		a[6][6] = 1;
		tr(2);
		if (succ) printf("Case #%d: GABRIEL\n", Ti);
		else printf("Case #%d: RICHARD\n", Ti);
	}
	return 0;
}
