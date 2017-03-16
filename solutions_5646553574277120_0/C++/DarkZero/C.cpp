#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int t;
int c,d,v;

int num[10];
int done[40];
int mark[10]={0};

void DFS(int now, int rest, int sum)
{
	if(rest == 0)
	{
		if(sum <= v)
			done[sum]=1;
		return;
	}
	int i;
	for(i=1;i<=d;i++)
	{
		if(mark[i] == 0)
		{
			mark[i]=1;
			DFS(now+1, rest-1, sum+num[i]);
			mark[i]=0;
		}
	}
	return;
}

void init()
{
	memset(done, 0, sizeof(done));
}

int main()
{
	freopen("Csmall.in", "r", stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for(int files=1; files<=t; files++)
	{
		init();
		cin>>c>>d>>v;
		int i;
		for(i=1;i<=d;i++)
		{
			cin>>num[i];
		}
		for(i=1;i<=d;i++)
		{
			memset(mark,0,sizeof(mark));
			DFS(1, i, 0);
		}
		int sum=0;
		for(i=1;i<=d;i++)
			sum+=num[i];
		
		int ans=0;
		for(i=1;i<=min(sum,v);i++)
		{
			if(done[i]==0)
			{
				ans++;
				for(int j=v; j>i; j--)
				{
					if(done[j-i]==1)
						done[j]=1;
				}
				sum+=i;
				done[i]=1;
			}
		}
		while(sum < v)
		{
			ans++;
			sum += sum+1;
		}
		printf("Case #%d: %d\n", files, ans);
	}
	//system("pause");
	return 0;
}






