#include<stdio.h>
#include<string.h>
#include<map>
#include<iostream>
using namespace std;
bool used[2000010];
int base,num;
int change(int x)
{
	int l=x/base;
	return (x-l*base)*10+l;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	for(int cc=1;cc<=cas;cc++)
	{
		int A,B;
		scanf("%d %d",&A,&B);
		memset(used,false,sizeof(used));
		int p=A;
		base=1;
		num=0;
		while(p)
		{
			base*=10;
			p/=10;
			num++;
		}
		base/=10;
		int ans=0;
		for(int i=A;i<=B;i++)
		{
			if(used[i])
				continue;
			int tmp=0;
			int x=i;
			for(int k=0;k<num;k++)
			{
				if(A <= x && x <= B)
				{
					if(!used[x])
						tmp++;
					used[x]=true;
				}
				x=change(x);
			}
			if(tmp >= 2)
				ans+=tmp*(tmp-1)/2;
		}
		printf("Case #%d: %d\n",cc,ans);
	}
	return 0;
}

