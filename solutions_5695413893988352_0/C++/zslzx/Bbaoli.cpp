#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int len;
char C[1000+10],J[1000+10];
int best,ansC,ansJ;
void dfs(int now,int pos,int val1,int val2)
{
	if(now==1&&pos==len)
	{
		if(abs(val1-val2)<best){best=abs(val1-val2);ansC=val1;ansJ=val2;}
		return;
	}
	if(now==0&&pos==len){dfs(1,0,val1,val2);return;}
	if(now==0)
	{
		if(C[pos]=='?')
		{
			for(int i=0;i<=9;i++)dfs(now,pos+1,val1*10+i,val2);
			
		}
		else dfs(now,pos+1,val1*10+C[pos]-'0',val2);
	}
	if(now==1)
	{
		if(J[pos]=='?')
		{
			for(int i=0;i<=9;i++)dfs(now,pos+1,val1,val2*10+i);
			
		}
		else dfs(now,pos+1,val1,val2*10+J[pos]-'0');
	}
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("baoli.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		scanf("%s%s",C,J);
		len=strlen(C);
		best=1000000;
		dfs(0,0,0,0);
		for(int i=0;i<len;i++)C[i]=J[i]='0';
		int tail=0;
		while(ansC)
		{
			C[tail++]=ansC%10+'0';
			ansC/=10;
		}
		tail=0;
		while(ansJ)
		{
			J[tail++]=ansJ%10+'0';
			ansJ/=10;
		}
		reverse(C,C+len);
		reverse(J,J+len);
		printf("Case #%d: %s %s\n",cas,C,J);
	}
	return 0;
}
