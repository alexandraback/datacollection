#pragma comment (linker, "/STACK:64000000")
#include <cstdio>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <bitset>
#include <sstream>
#include <set>
#include <map>

using namespace std;
template <class T> T sqr(T a) { return a * a; }

#define maxn 1010

int n;
int a[maxn];
int b[maxn];
int level[maxn];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int testNum;
	scanf("%d", &testNum);
	for (int testCount = 0; testCount < testNum; testCount++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		memset(level, 0, sizeof(level));
		int stars = 0;
		int result = 0;
		for (; stars < 2 * n; result++)
		{
			int solved = 0;
			for (int i = 0; i < n; i++)
				if (level[i] < 2 && b[i] <= stars)
				{
					stars += 2 - level[i];
					level[i] = 2;
					solved = 1;
					break;
				}
			if (!solved)
			{
				int bi = -1;
				for (int i = 0; i < n; i++)
					if (level[i] == 0 && a[i] <= stars)
						if (bi == -1 || b[bi] < b[i])
							bi = i;
				if (bi == -1)
				{
					result = -1;
					break;
				}
				stars++;
				level[bi] = 1;
			}
		}
		if (result == -1)
			printf("Case #%d: Too Bad\n", testCount + 1);
		else
			printf("Case #%d: %d\n", testCount + 1, result);
	}
	return 0;
}