#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;
int n;
int a[1000];

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);

		int res = 1000;

		for(int eat = 1; eat <= res; eat++)
		{
			int special = 0;
			for(int i = 0; i < n; i++)
			if (a[i] > eat)
			{
				special += (a[i] - 1) / eat;
			}
			res = min(res, eat + special);		
		}
		
		printf("%d\n", res);
	}
	return 0;
}