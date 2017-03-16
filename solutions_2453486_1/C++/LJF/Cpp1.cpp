#include<stdio.h>
char str[5][5];
bool win(char ch)
{
	int i,j,num;

	for(num=0,i=0;i<4;i++) if(str[i][i]==ch||str[i][i]=='T') num++;
	if(num==4) return 1;

	for(num=0,i=0;i<4;i++) if(str[i][3-i]==ch||str[i][3-i]=='T') num++;
	if(num==4) return 1;

	for(i=0;i<4;i++)
	{
		for(num=0,j=0;j<4;j++)
		{
			if(str[i][j]==ch||str[i][j]=='T') num++;
		}
		if(num==4) return 1;
	}

	for(i=0;i<4;i++)
	{
		for(num=0,j=0;j<4;j++)
		{
			if(str[j][i]==ch||str[j][i]=='T') num++;
		}
		if(num==4) return 1;
	}

	return 0;
}
bool have_empty()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++) if(str[i][j]=='.') return 1;
	}return 0;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T,cas=1;
	int i;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		for(i=0;i<4;i++) scanf("%s",str[i]);
		printf("Case #%d: ",cas);
		if(win('X')) printf("X won\n");
		else if(win('O')) printf("O won\n");
		else if(have_empty()) printf("Game has not completed\n");
		else printf("Draw\n");
	}
	return 0;
}