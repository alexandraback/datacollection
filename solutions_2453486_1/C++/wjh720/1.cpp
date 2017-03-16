#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,T;
char p[5][5];
inline bool calc(char P) {
	int i,j;
	For(i,1,4) {
		int F=1;
		For(j,1,4) F&=p[i][j]==P||p[i][j]=='T';
		if (F) return 1;
	}
	For(j,1,4) {
		int F=1;
		For(i,1,4) F&=p[i][j]==P||p[i][j]=='T';
		if (F) return 1;
	}
	int F=1;
	For(i,1,4) F&=p[i][i]==P||p[i][i]=='T';
	if (F) return 1;
	F=1;
	For(i,1,4) F&=p[i][4-i+1]==P||p[i][4-i+1]=='T';
	if (F) return 1;
	return 0;
}
int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	For(k,1,T) {
		printf("Case #%d: ",k);
		For(i,1,4) scanf("%s",p[i]+1);
		int F=0;
		For(i,1,4)For(j,1,4) if (p[i][j]=='.') F=1;
		n=calc('O'),m=calc('X');
		if (!n&&!m&&F) printf("Game has not completed\n");
		if (n&&!m) printf("O won\n");
		if (!n&&m) printf("X won\n");
		if (!n&&!m&&!F||n&&m) printf("Draw\n");
	} return 0;
}
