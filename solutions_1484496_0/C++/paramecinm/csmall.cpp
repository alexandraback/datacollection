#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

#define FF(i, a, b) for (int i=a; i<=b; i++)
#define FI(i, a, b) for (int i=a; i>=b; i--)
#define MS(f, x) memset(f, x, sizeof(f))

using namespace std;

const int MAXN = 1048575;
const int MAXM = 20 * 100000;

int ans[30];
vector<int>p[MAXM + 100];
int f[MAXN + 100];
int a[30];

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);	
	int t, n;
	scanf("%d", &t);
	FF(tt, 1, t)
	{
		scanf("%d", &n);
		printf("Case #%d:\n", tt);
		bool flag;
		FF(i, 1, n)
			scanf("%d", &a[i]);
		MS(f, 0);
		FF(i, 0, MAXM)
			p[i].clear();
		FF(i, 1, MAXN)
		{
			FF(j, 1, n)
				if ((i & (1 << (j - 1))) != 0)
					f[i] += a[j];
				
			flag = 0;
			FF(j, 0, (int)p[f[i]].size() - 1)
				if ((p[f[i]][j] & i) == 0)
				{
					flag = 1;
					int q = 0;
					FF(k, 1, n)
						if ((i & (1 << (k - 1))) != 0)
							ans[++q] = a[k];
					FF(k, 1, q - 1)
						printf("%d ", ans[k]);
					printf("%d\n", ans[q]);
					
					q = 0;
					FF(k, 1, n)
						if ((p[f[i]][j] & (1 << (k - 1))) != 0)
							ans[++q] = a[k];
					FF(k, 1, q - 1)
						printf("%d ", ans[k]);
					printf("%d\n", ans[q]);
					
					break;
				}
				
			if (flag) break;
			p[f[i]].push_back(i);
		}
		
		if (!flag)
			printf("Impossible\n");
	}


	return 0;
}
