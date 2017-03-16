//By momo
#include <cstdio>
#include <algorithm>
#define N 110
using namespace std;

int tbl[N][N], clx[N], rwx[N];

int main (){
	freopen("out.txt", "w", stdout);
	int t; scanf("%d", &t);
	for(int x = 0; x < t; x++){
		printf("Case #%d: ", x+1);
		int n, m; scanf("%d%d", &n, &m);
		fill(clx, clx + n, 0);
		fill(rwx, rwx + m, 0);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scanf("%d", &tbl[i][j]);
				clx[i] = max(clx[i], tbl[i][j]);
				rwx[j] = max(rwx[j], tbl[i][j]);
			}
		}
		int fl = 1;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
			if(clx[i] > tbl[i][j] && rwx[j] > tbl[i][j]) fl = 0;
		puts(fl?"YES":"NO");
	}
}
