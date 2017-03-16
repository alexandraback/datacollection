#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

bool val[50];
int coin[10005];
int main()
{
	int test,c,d,v;
	scanf("%d",&test);
	for(int a=1;a<=test;a++)
	{
		int ans=0;
		int b;
		memset(val,false,sizeof(val));
		val[0]=true;
		scanf("%d %d %d",&c,&d,&v);
		for(b=0;b<d;b++)
		{
			scanf("%d",&coin[b]);
		}
		int k=0;
		for(int b=0;b<d;b++)
		{
			for(int e=v;e>=coin[b];e--)
			{
				if(val[e-coin[b]]) val[e]=true;
			}
		}
		for(int e=1;e<=v;e++)
		{
			if(!val[e])
			{
				for(int b=v;b>=e;b--)
				{
					if(val[b-e]) val[b]=true;
				}
				val[e]=true;
				ans++;
			}
		}
		printf("Case #%d: %d\n",a,ans);
	}
}
