#include <cstdio>
int t,x,r,c,f[5][5][5] = {{{0}}};
char s[2][10] = {"RICHARD","GABRIEL"};
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&t);
//1
	for (int j = 1;j <= 4;++j)
		for (int k = 1;k <= 4;++k) f[1][j][k] = 1;
//2
	for (int j = 1;j <= 4;++j)
		for (int k = 1;k <= 4;++k) if (j * k % 2 == 0) f[2][j][k] = 1;
//3
	for (int j = 1;j <= 4;++j)
		for (int k = 1;k <= 4;++k) if (j * k > 3 && j * k % 3 == 0) f[3][j][k] = 1;
//4
	for (int j = 1;j <= 4;++j)
		for (int k = 1;k <= 4;++k) if (j * k > 8 && j * k % 4 == 0) f[4][j][k] = 1;
	for (int T = 1;T <= t;++T){
		scanf("%d%d%d",&x,&r,&c);
		printf("Case #%d: %s\n",T,s[f[x][r][c]]);
	}
}
