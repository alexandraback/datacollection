#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int T,n,a[2000],i,j,ans,ts,cur;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=1000;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=1000;i++)
		{
			cur=0;
			for(j=0;j<n;j++)
				cur+=(a[j]-1)/i;
			cur+=i;
			ans=min(cur,ans);
		}
		printf("Case #%d: %d\n",++ts,ans);
	}
	return 0;
}