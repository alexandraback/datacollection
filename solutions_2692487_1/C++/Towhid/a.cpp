#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <cstring>
#include <ctime>
#include <cfloat>

using namespace std;

int ss[105];
int req[105];

int main()
{
	//freopen("A-small-attempt0.in", "rt", stdin);
	//freopen("A-small-attempt0.out", "wt", stdout);


	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);

	int inp, kase, i, j, k, a, n;
	scanf("%d", &inp);
	for(kase = 1; kase <= inp; kase++)
	{
		scanf("%d %d", &a, &n);
		for(i = 0; i < n; i++)
		{
			scanf("%d", &ss[i]);
		}
		sort(ss, ss + n);
		printf("Case #%d: ", kase);
		if(a == 1)
		{
			printf("%d\n", n);
		}
		else
		{
			int cur = a;
			for(i = 0; i < n; i++)
			{
				if(i == 0)
					req[i] = 0;
				else
					req[i] = req[i - 1];
				while(cur <= ss[i])
				{
					cur += (cur - 1);
					req[i]++;
				}
				cur += ss[i];
			}
			int mn = n;
			for(i = 1; i <= n; i++)
			{
				int tmp = req[i - 1] + (n - i);
				if(tmp < mn)
					mn = tmp;
			}
			printf("%d\n", mn);
		}
	}

	return 0;
}

