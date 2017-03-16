#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
char s[1000];

int find(int x,int y)
{
	int t,i,min;
	min=0;
	t=0;
	for(i=x;i<=y;i++)
	{
		if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
		{
			if (t>min)  min=t;
			t=0;
		}
		else
		{
			t++;
			if(t>min)  min=t;
		}
	}
	return min;
}
int main()
{
	//	freopen("A.in","r",stdin);freopen("A.out","w",stdout);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
	int tt,ii,tot,k,n,i,j;
	scanf("%d",&tt);
	for(ii=1;ii<=tt;ii++)
	{
		scanf("%s",s);
		scanf("%d",&n);
		tot=0;
		for(i=0;i<strlen(s);i++)
			for(j=i+n-1;j<strlen(s);j++)
			{
				k=find(i,j);
				if (k>=n)   tot++;
			}
		printf("Case #%d: %d\n",ii,tot);
	}
	return 0;
}