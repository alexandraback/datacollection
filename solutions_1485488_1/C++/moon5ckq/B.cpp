#include <cstdio>
#define oo 105
int dx[] = {1, -1, 0, 0};
int dy[] = {0,0, 1, -1};

int c[oo][oo], f[oo][oo];
double d[oo][oo];
bool mk[oo][oo];
int H, N, M;


struct Tnode {
	int x,y;
}	q[oo*oo*oo];
int head, tail;


inline void Readin() {
	scanf("%d%d%d", &H, &N ,&M);
	for (int i=1;i<=N;++i)
		for (int j=1;j<=M;++j) {
			scanf("%d", &c[i][j]);
			
			d[i][j] = 1E20;
		}
	for (int i=1;i<=N;++i)
		for (int j=1;j<=M;++j)
			scanf("%d", &f[i][j]);
}

inline double Calc(Tnode u, Tnode v, double t) {
	double res = 0;
	
	if (c[u.x][u.y] - f[v.x][v.y] < 50) return 1E20;
	if (c[v.x][v.y] - f[v.x][v.y] < 50) return 1E20;
	if (c[v.x][v.y] - f[u.x][u.y] < 50) return 1E20;
	
	double h = H - t * 10;
	if (c[v.x][v.y] - h >= 50) {
		if (t<1E-9) return 0;
		if (h+1E-9 >= f[u.x][u.y] + 20) return 1;
		return 10;
	}
	
	res = (h - (c[v.x][v.y] - 50)) / 10;
	h = c[v.x][v.y] - 50;
	
	if (h >= f[u.x][u.y] + 20) return res + 1;
	return res + 10;
}

inline void Solve() {
	q[head = 0].x=1;
	q[head = 0].y=1;
	d[1][1] = 0;
	mk[1][1] = true;
	tail = 0;
	
	while (head <=tail ){
		Tnode u = q[head++];
		
		for (int i=0; i<4; ++i) {
			Tnode v;
			v.x = u.x + dx[i];
			v.y = u.y + dy[i];
			if (v.x <1 || v.x>N || v.y < 1 || v.y > M)  continue;
			
			double t = d[u.x][u.y] + Calc(u, v, d[u.x][u.y]);
			
			//printf("%.6lf\n", t);
			
			if (t < d[v.x][v.y]) {
				d[v.x][v.y] = t;
				if (mk[v.x][v.y] == false) {
					q[++tail] = v;
					mk[v.x][v.y] = true;
				}
			}
		}
		mk[u.x][u.y] = false;
	}
	
	printf("%.6lf\n", d[N][M]);
}

int main() {
	int Test, Case =0;
	for (scanf("%d", &Test); Test--; ) {
		printf("Case #%d: ", ++Case);
		Readin();
		Solve();
	}
	
	return 0;
}
