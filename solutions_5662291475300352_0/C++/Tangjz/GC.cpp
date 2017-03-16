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
const int maxn = 200010, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int t, tot, sta[2], spe[2];
int main()
{
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case)
	{
		int n, d, h, m;
		tot = 0;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d%d%d", &d, &h, &m);
			for(int i = 0; i < h; ++i)
			{
				sta[tot] = d;
				spe[tot] = m + i;
				++tot;
			}
		}
		if(spe[0] < spe[1])
		{
			swap(sta[0], sta[1]);
			swap(spe[0], spe[1]);
		}
		int ans = 0x3f;
		if((long long)sta[0] * spe[0] + (long long)spe[1] * 360 >= (long long)spe[0] * 360)
			ans = 0;
		else if(sta[1] <= sta[0] && (sta[0] - sta[1] + 360LL) * spe[0] < (360LL - sta[0]) * spe[1])
			ans = 0;
		else
			ans = 1;
		printf("Case #%d: %d\n", Case, ans);
	}
	return 0;
}
