#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n, m;
int nt;
int a[1000];
map<int, int> was;

int main()
{
	scanf("%d", &nt);
	
	for(int tt = 1; tt <= nt; tt++)
	{	
		printf("Case #%d:\n", tt);
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		
		int all = 1 << n;
		was.clear();
		bool ok = false;
		
		for(int i = 0; i < all; i++)
		{
			int sum = 0;
			for(int j = 0; j < n; j++) if (i & (1 << j)) sum += a[j];
			
			if (!was.count(sum))
			{
				was[sum] = i;
				continue;
			}
			
			bool first = true;
			for(int j = 0; j < n; j++) if (i & (1 << j))
			{
				if (!first) printf(" ");
				first = false;
				printf("%d", a[j]);
			}
			puts("");
			
			first = true;
			for(int j = 0; j < n; j++) if (was[sum] & (1 << j))
			{
				if (!first) printf(" ");
				first = false;
				printf("%d", a[j]);
			}
			puts("");
			ok = true;
			break;
		}
		
		if (!ok) puts("Impossible");
	}
	
	return 0;
}
