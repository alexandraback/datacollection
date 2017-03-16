#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int fa[2000];
int n;
int degree[1005];
bool ans;

int d[1005][1005];
bool floyd()
{
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			if (d[i][k]<=-1&&d[k][j]<=-1&&d[i][j]<=-1) return ans=true;
            else d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int f[1005][1005];
int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int testCase;
	scanf ("%d", &testCase);
	set<int> reach[1005];

	for (int t = 1; t <= testCase; t++)
	{
		ans = false;
		scanf("%d", &n);
		memset(d, 0, sizeof(d));
		memset(f, 0, sizeof(f));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				d[i][j]=0x3f3f3f3f;

		for (int x = 0; x < n; x++)
		{
			int num;
			scanf("%d", &num);
			for (int i = 0; i < num; i++)
			{
				int y;
				scanf("%d", &y);
				d[x][y-1] = -1;
				f[x][y-1] = 1;
			}
		}

		for(int i=0;i<n;i++)
			d[i][i]=0;//pay attention to this!
		floyd();
		printf("Case #%d: ", t);
		if (ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
