#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
char s[22], s1[22], s2[22];
int T;
int a[22], b[22];
int len=0;
int lena, lenb, ansa, ansb, anss=1000, t;
void check()
{
	int x=0, y=0, de=0;
	for (int i=1;i<=len;i++)
	{
		x*=10;
		x+=a[i];
	}
	for (int i=len+1;i<=2*len;i++)
	{
		y*=10;
		y+=b[i-len];
	}
	//printf("check: %d %d %d %d\n",x, y, a[2], b[2]);
	de=abs(x-y);
	if (de<anss || (de==anss && x<ansa) || (de==anss && x==ansa &&y<ansb))
		anss=de, ansa=x, ansb=y;
}	
		
void work(int x)
{
	if (x==2*len+1)
	{
		check();
		return ;
	}
	if (x<=len)
	{
		if (s1[x-1]=='?')
		for (int i=0;i<=9;i++)
			a[x]=i, work(x+1);
		else
			a[x]=s1[x-1]-'0', work(x+1);
	}
	else
	{
		if (s2[x-len-1]=='?')
		for (int i=0;i<=9;i++)
			b[x-len]=i, work(x+1);
		else
			b[x-len]=s2[x-len-1]-'0', work(x+1);
	}
}
int main()
{
	freopen("B-small-attempt.in","r",stdin);
	freopen("B-small-attempt.out","w",stdout);
	
	scanf("%d",&T);
	for (int k=1;k<=T;k++)
	{
		ansa=0, ansb=0, anss=1000;
		
		scanf("%s",&s1);
		scanf("%s",&s2);
		len=strlen(s1);
	
		work(1);
	
		t=ansa; lena=0;
		if (t==0) lena++;
		while (t)
		{
			t/=10;
			lena++;
		}
		t=ansb; lenb=0;
		if (t==0) lenb++;
		while (t)
		{
			t/=10;
			lenb++;
		}
		printf("Case #%d: ",k);
		for (int i=1;i<=len-lena;i++)
			printf("0");
		printf("%d ",ansa);
		for (int i=1;i<=len-lenb;i++)
			printf("0");
		printf("%d\n",ansb);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}








