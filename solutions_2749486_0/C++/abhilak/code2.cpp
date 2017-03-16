#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<string>
#include<cctype>
#include<list>
#include<set>
#include<deque>
#include<queue>
#include<bitset>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iomanip>
#include<ctime>

using namespace std;

int main()
{
	int x,y,test,t;test=1;int i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);
		printf("Case #%d: ",test);
		if(x>0)
		{
			for(i=0;i<x;i++)
			{
				printf("WE");
			}
		}
		else{
			x=x*-1;
			for(i=0;i<x;i++)
			{
				printf("EW");
			}
		}

if(y>0)
		{
			for(i=0;i<y;i++)
			{
				printf("SN");
			}
		}
		else{
			y=y*-1;
			for(i=0;i<y;i++)
			{
				printf("NS");
			}
		}
			printf("\n");
test++;
}
return 0;
}			








