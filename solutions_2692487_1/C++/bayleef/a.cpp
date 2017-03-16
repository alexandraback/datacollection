#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>

using namespace std;

int T,ts,b,n,i,a[200],ans,j,c,bb;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&bb,&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(bb==1)
		{
			printf("Case #%d: %d\n",++ts,n);
			continue;
		}
		sort(a,a+n);
		ans=1999999999;
		for(j=n;j>=0;j--)
		{
			c=0;
			b=bb;
			for(i=0;i<j;i++)
			{
				while(b<=a[i])
				{
					b+=b-1;
					c++;
				}
				b+=a[i];
			}
			if(c+n-j<ans)
				ans=c+n-j;
		}
		printf("Case #%d: %d\n",++ts,ans);
	}
	return 0;
}