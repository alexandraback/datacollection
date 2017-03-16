#include <iostream>
#include <cstdio>

using namespace std;

char s[4][6];

bool check(char c)
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(s[i][j]==c || s[i][j]=='T') continue;
			break;
		}
		if(j==4) return true;
	}
	
	for(j=0;j<4;j++)
	{
		for(i=0;i<4;i++)
		{
			if(s[i][j]==c || s[i][j]=='T') continue;
			break;
		}
		if(i==4) return true;
	}
	
	i=j=0;
	while(i<4)
	{
		if(s[i][j]==c || s[i][j]=='T')
		{
			i++;
			j++;
		}
		else break;
	}
	if(i==4) return true;
	
	i=0;j=3;
	while(i<4)
	{
		if(s[i][j]==c || s[i][j]=='T')
		{
			i++;
			j--;
		}
		else break;
	}
	if(i==4) return true;
	
	return false;
}

int doit()
{
	if(check('X')) return 1;
	if(check('O')) return 2;
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	if(s[i][j]=='.') return 4;
	return 3;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int t,cas;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++)
	{
		int i;
		for(i=0;i<4;i++)
		scanf("%s",s[i]);
		i=doit();
		printf("Case #%d: ",cas);
		if(i==1) puts("X won");
		else if(i==2) puts("O won");
		else if(i==3) puts("Draw");
		else puts("Game has not completed");
	}
	return 0;
}


