#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> mem[2000010];
int ori[25];

int main ()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int n, ts = 0; scanf("%d", &n);
		int ans0 = -1, ans1;
		for (int i = 0; i < n; i++) scanf("%d", &ori[i]), ts += ori[i];
		for (int i = 0; i < ts; i++) mem[i].clear();
		for (int s = 1; s < (1 << n); s++)
		{
			int sum = 0;
			for (int i = 0; i < n; i++) if (s & (1 << i)) sum += ori[i];
			mem[sum].push_back(s);
		}
		for (int i = 0; i < ts && ans0 == -1; i++)
		{
			if (mem[i].end() - mem[i].begin() > 1)
			{
				int l = mem[i].end() - mem[i].begin();
				for (int j = 0; j < l && ans0 == -1; j++)
				{
					for (int k = j + 1; k < l && ans0 == -1; k++)
					{
						if ((mem[i][j] & mem[i][k]) == 0) ans0 = mem[i][j], ans1 = mem[i][k];
					}
				}
			}
		}
		printf("Case #%d:\n", t);
		if (ans0 == -1) printf("Impossible\n");
		else
		{
			bool pr = false;
			for (int i = 0; i < n; i++)
			{
				if (ans0 & (1 << i))
				{
					if (!pr) printf("%d", ori[i]);
					else printf(" %d", ori[i]);
					pr = true;
				}
			}
			printf("\n");
			pr = false;
			for (int i = 0; i < n; i++)
			{
				if (ans1 & (1 << i))
				{
					if (!pr) printf("%d", ori[i]);
					else printf(" %d", ori[i]);
					pr = true;
				}
			}
			printf("\n");
		}
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
