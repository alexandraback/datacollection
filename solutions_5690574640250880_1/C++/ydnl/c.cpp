#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define eps 1e-8
#define oo 1<<29
#define LL long long

using namespace std;

int T, m, n, q, w, mi, ma, cnt, s, t, fi, cc, e, r, z, x, an, c, oldR, oldC;
char a[100][100];
int v[100][100];

bool out(int x, int y){
	if (x < 0) return true;
	if (y < 0) return true;
	if (x >= oldR) return true;
	if (y >= oldC) return true;
	return false;
}

void dfs(int x, int y){
	int cnt = 0;
	v[x][y] = 1;
	for (int i=-1; i<=1; i++)
		for (int j=-1; j<=1; j++)
			if (i != 0 || j != 0)
				if (out(x+i, y+j) || a[x+i][y+j] == '.')
					cnt++;
	if (cnt == 8){
		for (int i=-1; i<=1; i++)
			for (int j=-1; j<=1; j++)
				if (i != 0 || j != 0)
					if ((!out(x+i, y+j) && a[x+i][y+j] == '.') && v[x+i][y+j] == 0)
						dfs(x+i, y+j);
	} else 
		v[x][y] = 2;
}

int main(){
	scanf("%d", &T);
	for (int rr = 1; rr <= T; rr++){
		printf("Case #%d:\n", rr);
		scanf("%d%d%d", &r, &c, &m);
		oldR = r; oldC = c;
		memset(v, 0, sizeof(v));
		for (int i=0; i<r; i++)
			for (int j=0; j<c; j++)
				a[i][j] = '.';
		while (m != 0){
			if (m == min(r, c) - 1){
				if (r > c)
					for (int i=r-1; i>=0 && m>0; i--, m--)
						a[i][c-1] = '*';
				else if (c > r)
					for (int i=c-1; i>=0 && m>0; i--, m--)
						a[r-1][i] = '*';
				else {
					for (int i=r-1; i>=2; i--)
						a[i][c-1] = '*';
					a[r-1][c-2] = '*';
				}
				m = 0;
			}else {
				if (r > c){
					for (int i=c-1; i>=0 && m>0; i--, m--)
						a[r-1][i] = '*';
					r--;
				}
				else{
					for (int i=r-1; i>=0 && m>0; i--, m--)
						a[i][c-1] = '*';
					c--;
				}
			}
		}
		dfs(0, 0);
		/*		
					for (int i=0; i<oldR; i++){
					for (int j=0; j<oldC; j++)
					printf("%d ", v[i][j]);
					puts("");
					}
		 */
		bool ok = true;
		for (int i=0; i<oldR; i++)
			for (int j=0; j<oldC; j++)
				if (v[i][j] == 0 && a[i][j] == '.'){
					ok = false;
					break;
				}
		if (ok)
			for (int i=0; i<oldR; i++){
				for (int j=0; j<oldC; j++){
					if (i == 0 && j == 0)
						printf("c");
					else printf("%c", a[i][j]);
				}
				puts("");
			}
		else puts("Impossible");



	}
	return 0;
}
