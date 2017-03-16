#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<limits.h>
#include<math.h>
#include<algorithm>
#include<string.h>
#define mod 1000000007
#define ll long long
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output3.txt","w",stdout);
	int a,b,k,cnt,y=0,t;
	scanf("%d",&t);
	while(t--)
	{
		y++;
		cnt=0;
		scanf("%d%d%d",&a,&b,&k);
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				if((i&j)<k)
				cnt++;
			}
		}
		printf("Case #%d: ",y);
		printf("%d\n",cnt);
		 
	}
	
}

