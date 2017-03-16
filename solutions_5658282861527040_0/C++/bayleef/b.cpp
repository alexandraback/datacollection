#define _USE_MATH_DEFINES
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

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int T,a,b,k,ans,i,j,ts=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&k);
		ans=0;
		for(i=0;i<a;i++)
			for(j=0;j<b;j++)
				ans+=(i&j)<k;
		printf("Case #%d: %d\n",++ts,ans);
	}
	return 0;
}