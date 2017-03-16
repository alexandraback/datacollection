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
	int t,r,c,w,ans,ans2;
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
		if(r>1)
		{
			ans2 = c/w;
			ans2 = (r-1)*ans2;
			ans = ans2+ans;
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}