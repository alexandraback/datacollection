#include <cstdio>
#include <cstring>
int T,cnt;
char s[5][5];
bool bo;
bool can(int x,int y,char ch) {
	return x >= 1 && x <= 4 && y >= 1 && y <= 4 && (s[x][y] == ch || (s[x][y] == 'T' && !bo));
}
bool check(char ch) {
	int cnt,xx,yy;
	for (int x = 1; x <= 4; ++x)
		for (int y = 1; y <= 4; ++y) 
			if (s[x][y] == ch || s[x][y] == 'T') {
				cnt = 1; bo = s[x][y] == 'T' ? true : false;
				xx = x; 
				while (can(xx - 1,y,ch)) --xx,++cnt,bo = s[xx][y] == 'T' ? true : false;
				xx = x;
				while (can(xx + 1,y,ch)) ++xx,++cnt,bo = s[xx][y] == 'T' ? true : false;
				if (cnt >= 4) return true;
				
				cnt = 1; bo = s[x][y] == 'T' ? true : false; 
				yy = y; 
				while (can(x,yy - 1,ch)) --yy,++cnt,bo = s[x][yy] == 'T' ? true : false;
				yy = y;
				while (can(x,yy + 1,ch)) ++yy,++cnt,bo = s[x][yy] == 'T' ? true : false;
				if (cnt >= 4) return true;
					
				if (x == 1 && y == 4) {
					cnt = 1; bo = s[x][y] == 'T' ? true : false;
					xx = x; yy = y; 
					while (can(xx + 1,yy - 1,ch)) ++xx,--yy,++cnt,bo = s[xx][yy] == 'T' ? true : false;
				}
				if (x == 1 && y == 1) {
					cnt = 1; xx = x; yy = y;
					while (can(xx + 1,yy + 1,ch)) ++xx,++yy,++cnt,bo = s[xx][yy] == 'T' ? true : false;
				}
				if (cnt >= 4) return true;
			}
	return false;
}
int main() {
	//freopen("a.in","r",stdin); freopen("a.out","w",stdout);
	scanf("%d",&T);
	for (int I = 1; I <= T; ++I) {
		scanf("\n");
		for (int i = 1; i <= 4; ++i) scanf("%s\n",s[i] + 1);
		cnt = 0;
		for (int i = 1; i <= 4; ++i) 
			for (int j = 1; j <= 4; ++j)
				if (s[i][j] != '.') ++cnt;
		if (check('X')) printf("Case #%d: X won\n",I);
		else if (check('O')) printf("Case #%d: O won\n",I);
		else if (cnt < 16) printf("Case #%d: Game has not completed\n",I);
		else printf("Case #%d: Draw\n",I);
	}
}
