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

int d[1000001];
int i,j,x,T,n,ts;
queue<int>q;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	q.push(1);
	d[1]=1;
	while(!q.empty())
	{
		i=q.front();
		q.pop();
		if(i+1<1000000 && !d[i+1])
		{
			d[i+1]=d[i]+1;
			q.push(i+1);
		}
		j=0;
		x=d[i];
		while(i)
		{
			j=j*10+i%10;
			i/=10;
		}
		if(j<1000000 && !d[j])
		{
			d[j]=x+1;
			q.push(j);
		}
	}
	d[1000000]=d[999999]+1;

	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("Case #%d: %d\n",++ts,d[n]);
	}
	return 0;
}