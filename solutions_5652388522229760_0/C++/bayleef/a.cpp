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

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int i,j,u,x,T,ts;
	scanf("%d",&T);
	for(ts=1;ts<=T;ts++)
	{
		scanf("%d",&i);
		if(!i)
		{
			printf("Case #%d: INSOMNIA\n",ts);
			continue;
		}
		u=0;
		for(j=1;u!=1023;j++)
		{
			x=i*j;
			while(x)
			{
				u|=1<<x%10;
				x/=10;
			}
		}
		printf("Case #%d: %d\n",ts,i*(j-1));
	}
	return 0;
}