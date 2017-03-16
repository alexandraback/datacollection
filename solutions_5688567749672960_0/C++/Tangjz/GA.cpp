#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2000010, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int t, dis[maxn], p[maxn];
int main()
{
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 1;
	for(int i = 1; i <= 1000000; ++i)
	{
		if(dis[i + 1] > dis[i] + 1)
		{
			dis[i + 1] = dis[i] + 1;
			p[i + 1] = i;
		}
		int j = i, k = 0;
		while(j)
		{
			k = k * 10 + j % 10;
			j /= 10;
		}
		if(k > i && dis[k] > dis[i] + 1)
		{
			dis[k] = dis[i] + 1;
			p[k] = i;
		}
	}
	scanf("%d", &t);
	for(int Case = 1, x; Case <= t; ++Case)
	{
		scanf("%d", &x);
		printf("Case #%d: %d\n", Case, dis[x]);
	}
	return 0;
}
