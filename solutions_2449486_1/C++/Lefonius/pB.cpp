#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 105
using namespace std;

int map[N][N], n, m;
bool go(int h, int x, int y, int dx, int dy){
	//printf("now h = %d, x = %d, y = %d, dx =%d, dy = %d\n", h, x, y, dx, dy);
	if(x<0||y<0||x>=n||y>=m) return 1;
	if(map[x][y]>h) return 0;
	return go(h, x+dx, y+dy, dx, dy);
}

int main(){
	int T, time=0;
	int i, j;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
			for(j=0; j<m; j++)
				scanf("%d", &map[i][j]);
		int ok=1, tmp;
		for(i=0; i<n; i++)
			for(j=0; j<m; j++){
				tmp=0;
				tmp|=(go(map[i][j], i, j, -1, 0)&&go(map[i][j], i, j, 1, 0));
				tmp|=(go(map[i][j], i, j, 0, -1)&&go(map[i][j], i, j, 0, 1));
				ok&=tmp;
			}
		printf("Case #%d: %s\n", ++time, ok?"YES":"NO");
	}
	return 0;
}
