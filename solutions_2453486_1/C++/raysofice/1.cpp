#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char a[4][4];

bool judge(char c)
{
	int f;
	for(int i=0;i<4;++i)
	{
		f=0;
		for(int k=0;k<4;++k)
			if(a[i][k]!=c && a[i][k]!='T')
			{
				f=1;break;
			}
		if(f==0) return true;
		f=0;
		for(int k=0;k<4;++k)
			if(a[k][i]!=c && a[k][i]!='T')
			{
				f=1;break;
			}
		if(f==0) return true;
	}
	f=0;
	for(int k=0;k<4;++k)
	if(a[k][k]!=c && a[k][k]!='T')
	{
		f=1;break;
	}
	if(f==0) return true;
	f=0;
	for(int k=0;k<4;++k)
	if(a[k][3-k]!=c && a[k][3-k]!='T')
	{
		f=1;break;
	}
	if(f==0) return true;
	return false;
}

bool jj()
{
	for(int i=0;i<4;++i)
	{
		for(int k=0;k<4;++k)
			if(a[i][k]=='.')
				return true;
	}
	return false;
}


int main()
{
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		cas++;
		for(int i=0;i<4;++i)
			scanf("%s",a[i]);
		if(judge('X'))
		{
			printf("Case #%d: X won\n",cas);
			continue;
		}
		if(judge('O'))
		{
			printf("Case #%d: O won\n",cas);
			continue;
		}
		if(jj())
		{
			printf("Case #%d: Game has not completed\n",cas);
			continue;
		}
		printf("Case #%d: Draw\n",cas);
	}
	return 0;
}
