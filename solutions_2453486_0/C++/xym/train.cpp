#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
char gp[10][10];
int xi[4] = {0,1,1,-1};
int yi[4] = {1,0,1,1};
int check() {
	for(int i = 0;i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			for(int k = 0; k < 4; k++) {
				int a = 0,b = 0,cnt = 0;
				int x = i,y = j;
				if(gp[x][y] == '.')
					a = 1,b = 1;
				if(gp[x][y] == 'X')
					a = 1;
				if(gp[x][y] == 'O')
					b = 1;
				while(cnt < 3) {
					x += xi[k],y += yi[k];
					if(x < 0 || y < 0|| x >3 || y > 3)
						break;
					if(gp[x][y] == '.')
						a = 1,b = 1;
					if(gp[x][y] == 'X')
						a = 1;
					if(gp[x][y] == 'O')
						b = 1;
					cnt++;
				}
				if(cnt == 3 && ((a^b) == 1))
					if(a == 1)
						return 1;
					else return 2;
			}
		}
	}
	return 0;
}
int main () {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int cas = 1; cas <= T; cas++) {
		for(int i = 0; i < 4; i++) {
			scanf("%s",gp[i]);
		}
		gets(gp[5]);
		int flag = 0;
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				if(gp[i][j] == '.')
					flag = 1;
			}
		}
		printf("Case #%d: ",cas);
		int ans = check();
		if(ans) {
			printf("%s\n",ans > 1?"O won":"X won");
		}
		else  if(flag)
			puts("Game has not completed");
		else puts("Draw");
	}
	return 0;
}