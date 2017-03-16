#include<iostream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
#include <queue>
#include<string>
#include <sstream>
#include<list>
#include<map>
#include<cmath>
#include<algorithm>

using namespace std;


int main()
{
	
	
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	
	int T;
	scanf("%d",&T);
	for(int t = 1; t<=T; t++)
	{
		int r,c,w;
		scanf("%d %d %d",&r, &c, &w);
		int res = (c/w-1) + w;
		if(c%w) res++;
		if(r>1) 
		{
			int xx = c/w;
			res += (r-1)*(xx);
		}
		printf("Case #%d: %d\n",t,res);
	}
	
	return 0;
}
