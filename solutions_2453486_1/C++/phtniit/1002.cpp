#include<cstdio>
#include<cstring>
char s[12][12];
int tes;
bool win(char c)
{
	int a=0,b=0,aa=0,bb=0;
	for(int i=0,j,k,kk;i<4;++i)
	{
		if(s[i][i]==c)		a++;
		if(s[i][i]=='T')	b++;
		if(s[i][3-i]==c)	aa++;
		if(s[i][3-i]=='T')	bb++;
		for(j=0,k=0,kk=0;j<4;++j)
		{
			if(s[i][j]==c)	k++;
			if(s[i][j]=='T')	kk++;
		}
		if(k==4||(k==3&&kk==1))	return true;

		for(j=0,k=0,kk=0;j<4;++j)
		{
			if(s[j][i]==c)	k++;
			if(s[j][i]=='T')	kk++;
		}
		if(k==4||(k==3&&kk==1))	return true;
	}
	if(a==4||(a==3&&b==1))	return true;
	if(aa==4||(aa==3&&bb==1))	return true;
	return false;
}
bool f()
{
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)if(s[i][j]=='.')
			return false;
	return true;
}
int main()
{
	//freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);
	scanf("%d",&tes);
	for(int h=1;h<=tes;++h)
	{
		for(int i=0;i<4;++i)	scanf("%s",s[i]);
		printf("Case #%d: ",h);
		if(win('X'))
			puts("X won");
		else if(win('O'))
			puts("O won");
		else if(f())
			puts("Draw");
		else
			puts("Game has not completed");
	}
	return 0;
}