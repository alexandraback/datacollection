#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;

int maxG = 0;
int a[100];

void bt (int act, int ener, int gain,int n,int E, int R)
{
	if (act == n)
	{
		maxG = max(maxG,gain);
	}
	else
	{
		if (!ener)
			return;

		for (int i = 0; i <= ener; ++i)
		{
			int ge = ener-i+R;

			if (ge > E)
				ge = E;
			bt(act+1,ge,gain+i*a[act],n,E,R);
		}
	}
}

int main ()
{
	int T;
	scanf("%d",&T);

	for (int t = 1; t <= T; ++t)
	{
		maxG = 0;

		int e,r,n;
		scanf("%d %d %d",&e,&r,&n);

		for (int i = 0; i < n; ++i)
			scanf("%d",a+i);

		bt(0,e,0,n,e,r);

		printf("Case #%d: %d\n",t,maxG);
	}
	return 0;
}
