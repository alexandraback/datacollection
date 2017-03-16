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

int T,ts,n,m,i,j,u[50],mask;

bool check()
{
	u[0]=mask;
	int i;
	for(i=0;i<=m;i++)
		if(mask>>i&1)
			for(j=m-i;j>=0;j--)
				if(u[j]==mask)
					u[j+i]=mask;
	for(i=1;i<=m;i++)
		if(u[i]!=mask)
			return 0;
	return 1;
}

bool rec(int n,int last)
{
	if(!n)
		return check();
	for(last++;last<=m;last++)
		if(!(mask>>last&1))
		{
			mask^=1<<last;
			if(rec(n-1,last))return 1;
			mask^=1<<last;
		}
	return 0;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&T);
	for(ts=1;ts<=T;ts++)
	{
		mask=0;
		memset(u,0,sizeof(u));
		scanf("%d%d%d",&i,&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%d",&j);
			mask|=1<<j;
		}
		for(i=0;i<5;i++)
			if(rec(i,0))
				break;
		printf("Case #%d: %d\n",ts,i);
	}
	return 0;
}