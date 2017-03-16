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
#include <unordered_map>
#include <unordered_set>

using namespace std;

int n,m,k,i,j,T,ts;
long long x;

int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&T);
	for(ts=1;ts<=T;ts++)
	{
		scanf("%d%d%d",&n,&m,&k);
		printf("Case #%d:",ts);
		if(m*k<n)
		{
			puts(" IMPOSSIBLE");
			continue;
		}
		for(i=0;i<n;i+=m)
		{
			x=0;
			for(j=i;j<i+m;j++)
				x=x*n+(j%n);
			printf(" %lld",x+1);
		}
		puts("");
	}
	return 0;
}