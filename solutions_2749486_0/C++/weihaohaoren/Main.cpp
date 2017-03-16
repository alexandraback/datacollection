#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
using namespace std;
typedef long long LL;
const double pi=acos(-1.0);

int x,y;

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++)
	{
		scanf("%d%d",&x,&y);		
		printf("Case #%d: ",tc);
		if(x>0)
		{
			while(x--)
			{
				printf("WE");
			}
		}
		else
		{
			x=-x;
			while(x--)
			{
				printf("EW");
			}
		}
		if(y>0)
		{
			while(y--)
			{
				printf("SN");
			}
		}
		else
		{
			y=-y;
			while(y--)
			{
				printf("NS");
			}
		}
		printf("\n");
	}
	fclose(stdout);
	return 0;
}
