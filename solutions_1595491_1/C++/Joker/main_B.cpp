#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for (int k=1; k<=T; ++k)
	{
		int n, s, p;
		scanf("%d%d%d", &n, &s, &p);
		int i, res = 0;
		for (i=0; i<n; ++i)
		{
			int sum;
			scanf("%d", &sum);
			if (sum%3 == 0)
			{
				if (sum/3 >= p) ++res;
				else if (sum/3>0 && sum/3+1>=p && s>0) 
				{
					--s;
					++res;
				}
			}
			else
			{
				if (sum/3+1 >= p) ++res;
				else if (sum%3==2 && sum/3+2>=p && s>0)
				{
					--s;
					++res;
				}
			}
		}

		printf("Case #%d: %d\n", k, res);
	}

	return 0;
}
