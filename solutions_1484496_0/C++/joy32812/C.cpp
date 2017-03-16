//BBB
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
typedef long long LL;
const int MAX=10000000+10;

int N;
int a[MAX];
int ans[MAX];

void gs(int x)
{
	ans[x]=0;
	for(int i=0;i<N;i++)
	{
		if(x&(1<<i)) ans[x]+=a[i];
	}
}

void out(int x)
{
	int flag=0;
	for(int i=0;i<N;i++)
	{
		if(x&(1<<i))
		{
			if(flag) printf(" ");
			else flag=1;
			printf("%d",a[i]);
		}
	}
	printf("\n");
}
void myout(int x,int y)
{
	out(x);
	out(y);
}
bool check()
{
	map<int,int> my;
	for(int i=(1<<N)-1;i>=1;i--)
	{
		if(my.find(ans[i])!=my.end())
		{
			myout(my[ans[i]],i);
			return 1;
		}
		my[ans[i]]=i;
	}
	return 0;
}
char s[]="Impossible";
int main()
{
	int CN=0;
	int T;scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++) scanf("%d",&a[i]);
		for(int i=(1<<N)-1;i>=1;i--)
		{
			gs(i);
		}
		
		printf("Case #%d:\n",++CN);
		if(!check()) puts(s);
	}
	
	return 0;
}
