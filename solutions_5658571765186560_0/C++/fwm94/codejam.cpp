#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#define maxn 100009
#define maxm
using namespace std;
int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int tt,cot=1;
	scanf("%d",&tt);
	while(tt--)
	{
		int x,r,c;
		scanf("%d%d%d",&x,&r,&c);
		if(r*c%x)
		{
			printf("Case #%d: RICHARD\n",cot++);
		}
		else if(x>=7)
		{
			printf("Case #%d: RICHARD\n",cot++);
		}
		else if(x==1)
		{
			printf("Case #%d: GABRIEL\n",cot++);
		}	
		else if(x==2)
		{
			printf("Case #%d: GABRIEL\n",cot++);
		}
		else if(x==3)
		{
			if(max(r,c)<3||min(r,c)==1)
			{
				printf("Case #%d: RICHARD\n",cot++);
			}
			else
			{
				printf("Case #%d: GABRIEL\n",cot++);
			}
		}
		else if(x==4)
		{
			if(max(r,c)<4||min(r,c)<=2)
			{
				printf("Case #%d: RICHARD\n",cot++);
			}
			else
			{
				printf("Case #%d: GABRIEL\n",cot++);
			}
		}
		else if(x==5)
		{
			if(max(r,c)<5||min(r,c)<3)
			{
				printf("Case #%d: RICHARD\n",cot++);
			}
			else
			{
				printf("Case #%d: GABRIEL\n",cot++);
			}
		}
		else
		{
			if(max(r,c)<6||min(r,c)<=3)
			{
				printf("Case #%d: RICHARD\n",cot++);
			}
			else
			{
				printf("Case #%d: GABRIEL\n",cot++);
			}
		}
	}
	return 0;
}