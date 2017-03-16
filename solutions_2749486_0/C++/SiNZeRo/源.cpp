#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int T;

int x,y;
void output()
{
	//int speed = 1;
	if(x!=0)
	{
		if(x>0)
		{
			while(x)
			{
				printf("WE");
				--x;
			}
		}
		else
		{
			while(x)
			{
				printf("EW");
				++x;
			}
		}
	}

	if(y!=0)
	{
		if(y>0)
		{
			while(y)
			{
				printf("SN");
				y--;
			}
		}
		else
		{
			while(y)
			{
				printf("NS");
				y++;
			}
		}
	}
	printf("\n");
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for(int i = 1; i <= T; ++i)
	{
		//int x, y;
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",i);
		output();
	}
	return 0;
}