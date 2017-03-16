#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int cas;
	scanf("%d",&cas);
	for(int cc=1;cc<=cas;cc++)
	{
		int n,total,p;
		scanf("%d %d %d",&n,&total,&p);
		int x,y;
		x=y=0;
		while(n--)
		{
			int s;
			scanf("%d",&s);
			if(p >= 2)
			{
				if(s >= 3*p-2)
					x++;
				else if(s >= 3*p-4)
					y++;
			}
			else if(p == 1)
			{
				if(s >= 1)
					x++;
			}
			else
				x++;
		}
		printf("Case #%d: %d\n",cc,x+min(y,total));
	}
	return 0;
}

