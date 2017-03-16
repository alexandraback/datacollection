#include <stdio.h>
#include <string.h>
#include <math.h>
const int maxn=110;
const int inf=1<<30;
int ans[maxn];
int id;
int check(long long num)
{
	char buf[20];
	int len,sta,end;
	sprintf(buf,"%I64d",num);
	len=strlen(buf);
	sta=0;
	end=len-1;
	while(sta<end)
		if(buf[sta++]!=buf[end--])
			return 0;
	return 1;
}
void pre()
{
	int i;
	id=1;
	ans[0]=0;
	for(i=1;i<10000000;i++)
		if(check((long long)i)&&check((long long)i*i))
			ans[id++]=i;
	ans[id++]=inf;
	return;
}
int find(int flag,long long num)
{
	int i;
	long long temp;
	for(i=0;i<id;i++)
	{
		temp=(long long)ans[i]*ans[i];
		if(temp>num)
			return i-1;
		else if(temp==num)
			return i-flag;
	}
	return -1;
}
int main()
{
	int T,t;
	long long sta,end;
	pre();
	scanf("%d",&T);
	t=1;
	while(T--)
	{
		scanf("%lld %lld",&sta,&end);
		sta=find(1,sta);
		end=find(0,end);
		printf("%d\n",end-sta);
	}
	return 1;
}