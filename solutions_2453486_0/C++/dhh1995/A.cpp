#include<cstdio>
#include<cstring>
#define rep(i,n) for (int i=0;i<n;i++)
int T,Case; char s[5][5];
bool check(char ch)
{
	int flag;
	rep(i,4){
		flag=1;
		rep(j,4) if (s[i][j]!=ch && s[i][j]!='T') flag=0;
		if (flag) return 1;
		flag=1;
		rep(j,4) if (s[j][i]!=ch && s[j][i]!='T') flag=0;	
		if (flag) return 1;	
		}
	flag=1;
	rep(i,4) if (s[i][i]!=ch && s[i][i]!='T') flag=0;
	if (flag) return 1;
	flag=1;
	rep(i,4) if (s[i][3-i]!=ch && s[i][3-i]!='T') flag=0;
	return flag;
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		rep(i,4) scanf("%s",s[i]); bool blank=0; printf("Case #%d: ",++Case);
		rep(i,4) rep(j,4) blank+=s[i][j]=='.';
		if (check('X')) puts("X won");
		else if (check('O')) puts("O won");
			else if (blank) puts("Game has not completed");
				else puts("Draw");
		}
	return 0;
}
