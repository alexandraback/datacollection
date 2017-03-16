#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn = 123, mod = 1000000007;
const double eps = 1e-8;
int T, c, n, v, tot, x[maxn], ans;
int main()
{
	srand(time(NULL));
	scanf("%d", &T);
	for(int Case = 1; Case <= T; ++Case)
	{
		ans = 0;
		scanf("%d%d%d", &c, &n, &v);
		for(int i = 1; i <= n; ++i)
			scanf("%d", x + i);
		tot = n;
		if(c == 1)
		{
			for(int i = 1; i <= v; ++i)
			{
				int j = i;
				for(int k = tot; k > 0 && j; --k)
					if(x[k] <= j)
						j -= x[k];
				if(!j)
					continue;
				//printf("%d\n", i);
				x[++tot] = i;
				sort(x + 1, x + tot + 1);
			}
			ans = tot - n;
		}
		else
		{
			ans = rand() % (v - n) + 1;//orz sd0061
		}
		printf("Case #%d: %d\n", Case, ans);
	}
	return 0;
}
