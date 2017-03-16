#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, T, p, k, cnt;
struct arr
{
	int x , y;
	bool operator<(const arr &t)const
	{
		return y < t.y || (y == t.y && x < t.x);
	}
}a[1000010];
bool t[1010], flag;
int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
		sort(a + 1, a + n + 1);
		memset(t, 0, sizeof(t));
		cnt = k = 0;
		p++;
		for (int i = 1; i <= n; i++)
		{
			while (k < a[i].y)
			{
				flag = 0;
				for (int j = n; j >= i; j--)
					if (t[j] == 0 && k >= a[j].x)
					{
						t[j] = 1;
						k++;
						cnt++;
						flag = 1;
						break;
					}
				if (flag == 0)
				{
					printf("Case #%d: Too Bad\n", p);
					goto die;
				}
			}
			if (t[i]) k++;
			else k += 2;	
		}
		printf("Case #%d: %d\n", p, cnt + n);
		die:;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
