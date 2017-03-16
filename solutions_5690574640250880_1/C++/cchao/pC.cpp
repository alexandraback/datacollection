#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase) {
		int r, c, m;
		scanf("%d%d%d", &r, &c, &m);
		printf("Case #%d:\n", kase);
		bool trans = false;
		char g[60][60] = {{}};
		int cnt = 0;
		int final = r*c - m;
		if(final == 1) {
			g[0][0] = 'c';
			for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j) if(g[i][j] == 0) g[i][j] = '*';
			for(int i = 0; i < r; ++i) puts(g[i]);
			continue;
		}
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j < 2; ++j) {
				if(i < r && j < c) {
					cnt++;
					g[i][j] = '.';
				}
			}
		g[0][0] = 'c';
		if(cnt > final) { puts("Impossible"); continue ;}
		int x = 0, y = 0;
		//printf("final %d\n", final);
		while(cnt < final) {
			y++; if(y == c) { y = 0; x++; }
			if(x == r) break;
			if(x > 0 && y+1 < c && g[x-1][y+1] == 0) continue;
			int emp = 0;
			for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j)
				if(i+x < r && j+y < c && g[i+x][j+y] == 0) emp++;
			if(final - (cnt + emp) == 1 && ((x==0 && emp==2) || y == c - 2)) {
				//puts("here");
				y = c - 1;
				continue ;
			}
			//printf("fill %d %d\n", x, y);
			for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j)
				if(i+x < r && j+y < c && g[i+x][j+y] == 0) {
					g[i+x][j+y] = '.';
					cnt++;
				}
		}
		if(cnt != final) { puts("Impossible"); continue ;}
		for(int i = 0; i < r; ++i) for(int j = 0; j < c; ++j) if(g[i][j] == 0) g[i][j] = '*';
		for(int i = 0; i < r; ++i) puts(g[i]);
	}
	return 0;
}