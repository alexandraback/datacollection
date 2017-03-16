#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
#include <cstring>
using namespace std;
int main()
{
	int t,r,c,w,ans;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&r);
		scanf("%d",&c);
		scanf("%d",&w);
		if(c%w==0)
		{
			ans = c/w;
			ans = ans + w - 1;
		}
		else
		{
			ans = c/w;
			ans = ans + w;
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}