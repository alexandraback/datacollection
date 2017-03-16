#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;

int r, c, m;

int GetMinN(int n){
	return (int)ceil(sqrt(n));
}
const int MaxN = 55;
int G[MaxN][MaxN], G1[MaxN][MaxN]; //0-* 1-.
const int dir8x[] = {0,0,-1,1,-1,1,-1,1};
const int dir8y[] = {-1,1,0,0,-1,1,1,-1};

int GetDigit(int x, int y){
	int cnt = 0;
	for (int k = 0; k < 8; k++){
		int nx = x + dir8x[k], ny = y + dir8y[k];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c){
			if (G[nx][ny] == 0)
				cnt++;
		}
	}
	return cnt;
}
struct point{
	int x, y;
	point(int x = 0, int y = 0):x(x),y(y){}
};

int rr, cc, mm;

bool vst[MaxN][MaxN];
queue<point> Q;

bool check(){
	int cnt = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (G[i][j] == 1)
				cnt++;
	if (cnt != mm)
		return false;
	memset(vst, 0 ,sizeof(vst));
	Q.push(point(0, 0));
	vst[0][0] = true;
	while (!Q.empty()){
		point cur = Q.front(); Q.pop();

		if (GetDigit(cur.x, cur.y) == 0){
			for (int k = 0; k < 8; k++){
				int nx = cur.x + dir8x[k], ny = cur.y + dir8y[k];
				if (nx >= 0 && nx < r && ny >=0 && ny < c && !vst[nx][ny]){
					vst[nx][ny] = true;
					Q.push(point(nx, ny));
				}
			}
		}
	}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (G[i][j] && !vst[i][j])
				return false;
	return true;
}

void printG(){
	if (!check()){
		//printf("%d %d %d\n", rr,cc,mm);
		puts("Impossible");
		return ;
	}
	G[0][0] = 2;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++)
			if (G[i][j] == 0)
				printf("*");
			else if (G[i][j] == 2)
				printf("c");
			else
				printf(".");
		puts("");
	}
}

int main(){
	freopen("CC.in", "r", stdin);
	freopen("CC.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		scanf("%d%d%d", &r, &c, &m);  rr = r, cc = c, mm = m;
		printf("Case #%d:\n", cas);
		m = r * c - m;mm = m;
		if (r == 1){
			printf("c");
			for (int i = 1; i < m; i++)
				printf(".");
			for (int i = m; i < c; i++)
				printf("*");
			puts("");
			continue;
		}
		if (c == 1){
			puts("c");
			for (int i = 1; i < m; i++)
				puts(".");
			for (int i = m; i < r; i++)
				puts("*");
			continue;
		}
		if (m == 1){
			printf("c");
			for (int i = 0; i < r; i++){
				for (int j = (i==0)?(1):(0); j < c; j++)
					printf("*");
				puts("");
			}
			continue;
		}


		// r * c
		if (m == 2 || m == 3){
			//printf("%d %d %d  \n", rr,cc,mm);
			puts("Impossible");
			continue;
		}

		int z = GetMinN(m);

		memset(G, 0 , sizeof(G));
	//	printf("z = %d, min(r,c) = %d\n", z, min(r, c));
		if (z <= min(r, c)){
			for (int i = 0; i < z - 2; i++)
				for (int j = 0; j < z; j++)
					G[i][j] = 1;
			m -= z * (z - 2);
			if (m <= z)
				for (int i = 0; i < m; i++)
					G[z - 2][i] = 1;
			else {
				for (int i = 0; i < z; i++)
					G[z - 2][i] = 1;
				m -= z;
				if (m == 1){
					G[z - 2][z - 1] = 0;
					G[z - 1][0] = G[z - 1][1] = 1;
				} else {
					for (int i = 0; i < m; i++)
						G[z - 1][i] = 1;
				}
			}
		} else {
			bool flip = false;
			int k = min(r, c);
			if (r == k){
				swap(r,c);
				flip = true;
			}
			int cnt = 0;
			while (z > c){
				m -= c; 
				z = GetMinN(m);
				cnt++;
			}
		//	printf("z1 = %d, m1 = %d\n", z, m);
			if (m == 1){
				//printf("%d %d %d\n", rr,cc,mm);
				puts("Impossible");
				continue;
			}
			if (m == 3 && k == 2){
				//printf("%d %d %d\n", rr,cc,mm);
				puts("Impossible");
				continue;
			}
			for (int i = 0; i < cnt; i++)
				for (int j = 0; j < c; j++)
					G[i][j] = 1;
			
			// normal 
			for (int i = 0; i < z - 2; i++)
				for (int j = 0; j < z; j++)
					G[i + cnt][j] = 1;
			m -= z * (z - 2);
			if (m <= z)
				for (int i = 0; i < m; i++)
					G[z - 2 + cnt][i] = 1;
			else {
				for (int i = 0; i < z; i++)
					G[z - 2 + cnt][i] = 1;
				m -= z;
				if (m == 1){
					G[z - 2 + cnt][z - 1] = 0;
					G[z - 1 + cnt][0] = G[z - 1 + cnt][1] = 1;
				} else {
					for (int i = 0; i < m; i++)
						G[z - 1 + cnt][i] = 1;
				}
			}

			// flip
			if (flip){
				for (int i = 0; i < r; i++)
					for (int j = 0; j < c; j++)
						G1[j][i] = G[i][j];
				for (int i = 0; i < c; i++)
					for (int j = 0; j < r; j++)
						G[i][j] = G1[i][j];
				swap(r,c);
			}

		}

		printG();

	}
}
