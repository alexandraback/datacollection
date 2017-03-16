#pragma comment(linker, "/STACK:16777216")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;

int n, t;
int a[1 << 5];
int have[1 << 21];

int main()
{
	freopen("C.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	for(int I = 1; I <= t; ++I)
	{
		scanf("%d", &n);
		for(int j = 0; j < n; ++j)
			scanf("%d", &a[j]);
		memset(have, -1, sizeof(have));
		bool ok = 0;
		for(int i = 1; i < 1 << n; ++i)
		{
			int s = 0;
			for(int j = 0; j < n; ++j)
				if (i & (1 << j))
					s += a[j];
			if (have[s] != -1)
			{
				ok = 1;
				printf("Case #%d:\n", I);
				for(int j = 0; j < n; ++j)
					if (i & (1 << j))
						printf("%d ", a[j]);
				printf("\n");
				for(int j = 0; j < n; ++j)
					if (have[s] & (1 << j))
						printf("%d ", a[j]);
				printf("\n");
				break;
			}
			have[s] = i;
		}
		if (!ok)
		{
			printf("Case #%d:\n", I);
			printf("Impossible\n");
		}
	}
	return 0;
}