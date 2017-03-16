#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>
using namespace std;

int T;
int a[20000];
int b[20000];
int N;
int inf = 2147483647;


int main( )
{
	int i,j,k;
	int res;
	bool getstar;
	int n,m;

	freopen( "B.in", "r", stdin );
	freopen( "B.out", "w", stdout );

	scanf("%d",&T);

	for(i=1;i<=T;i++)
	{
		scanf("%d",&N);
		
		for(j=0;j<N;j++)
			scanf("%d %d",&a[j], &b[j]);

		printf("Case #%d: ",i);

		res = 0;
		n = 0;
		m = 0;
		getstar = true;
		while(getstar)
		{
			getstar = false;

			for(j=0;j<N;j++)
			{
				if(n >= b[j] && a[j] < inf)
				{
					getstar = true;
					b[j] = inf;
					a[j] = inf;
					n += 2;
					res += 1;
					m ++;
				}
				else if(n >= b[j] && a[j] == inf)
				{
					getstar = true;
					b[j] = inf;
					n += 1;
					res += 1;
					m ++;
				}
			}

			if(!getstar)
			{
				for(j=0;j<N;j++)
				{
					if(n >= a[j])
					{
						getstar = true;
						a[j] = inf;
						n += 1;
						res += 1;
						break;
					}
				}
			}
		}
		
		if(m == N)
			printf("%d\n",res);
		else
			printf("Too Bad\n");
	}

	return 0;
}
