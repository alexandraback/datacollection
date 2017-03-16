#include<iostream>
#include<cstdio>
#include<cstring>

char s[10][10];

int get(int f)
{
	int i,j;
	char ch=(f?'O':'X');
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			if(s[i][j]!=ch&&s[i][j]!='T')
				break;
		if(j==4) return 1;
	}
	for(j=0;j<4;j++)
	{
		for(i=0;i<4;i++)
			if(s[i][j]!=ch&&s[i][j]!='T')
				break;
		if(i==4) return 1;
	}
	for(i=0;i<4;i++) if(s[i][i]!=ch&&s[i][i]!='T') break;
	if(i==4) return 1;
	for(i=0;i<4;i++) if(s[i][3-i]!=ch&&s[i][3-i]!='T') break;
	if(i==4) return 1;
	return 0;
}

int main()
{
	int T,tc,i,j;
	freopen("A.in","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&T);
	for(tc=1;tc<=T;tc++)
	{
		for(i=0;i<4;i++)
			scanf("%s",s[i]);
		int f=0,c=0;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++) c+=(s[i][j]=='.');
		if(get(0))
		{
			printf("Case #%d: X won\n",tc);
			continue;
		}
		if(get(1))
		{
			printf("Case #%d: O won\n",tc);
			continue;
		}
		if(c) printf("Case #%d: Game has not completed\n",tc);
		else printf("Case #%d: Draw\n",tc);
	}
	return 0;
}