#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int tt,tc;
    scanf("%d",&tt);
    for (tc=1;tc<=tt;tc++)
	{
		int s;
		char num[1001];
		scanf("%d %s",&s,num);
		int need=0;
		int cum=0;
		for (int i=0;i<=s;i++)
		{
			int p=num[i]-'0',x=0 ;
			if (p>0 && i>cum)
			{
				x=i-cum;
				need+=x;
			}
			cum+=p+x;
		}
		printf("Case #%d: %d\n",tc,need);
	}
    return 0;
}
