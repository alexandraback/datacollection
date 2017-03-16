#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <map>
using namespace std;

int mmap[3000000];

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	int ii;
	for(ii = 1; ii <= tt; ii++)
	{
		memset(mmap, 0, sizeof(mmap));
		int n;
		cin >> n;
		int i;
		int a[25];
		for(i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		bool ok = false;
		int mask1, mask2;
		for(i = 1; i < (1 << n); i++)
		{
			int j;
			int s = 0;
			for(j = 0; j < n; j++)
			{
				if((i >> j) & 1)
				{
					s += a[j];
				}
			}
			if(mmap[s])
			{
				ok = true;
				mask1 = mmap[s];
				mask2 = i;
				break;
			}
			mmap[s] = i;
		}
		printf("Case #%d:\n", ii);
		if(ok)
		{
			for(i = 0; i < n; i++)
			{
				if((mask1 >> i) & 1)
				{
					printf("%d ", a[i]);
				}
			}	
			printf("\n");
			for(i = 0; i < n; i++)
			{
				if((mask2 >> i) & 1)
				{
					printf("%d ", a[i]);
				}
			}	
			printf("\n");
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}
