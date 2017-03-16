#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int num_case, ans, bff[1024], n, num[20];
bool flag, use[20];

bool check(int key)
{
	//for (int i = 1; i <= key; i++) printf("%d ", num[i]); printf("\n");
	num[key + 1] = num[1];
	num[0] = num[key];
	for (int i = 1; i <= key; i++)
		if (bff[num[i]] != num[i - 1] && bff[num[i]] != num[i + 1])
			return 0;
	//printf("OK!!\n");
	return 1;
}

void search(int dep, int key)
{
	if (dep == key)
	{
		if (check(key))
			flag = 1;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!use[i])
		{
			use[i] = 1;
			num[dep + 1] = i;
			search(dep + 1, key);
			use[i] = 0;
			num[dep + 1] = 0;
			if (flag) return;
		}
	}
}

int main()
{
	freopen("C1.in", "r", stdin);
	freopen("C1.out", "w", stdout);
	scanf("%d", &num_case);
	for (int icase = 1; icase <= num_case; icase++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &bff[i]);
		flag = 0;
		for (int i = n; i >=2; i--)
		{
			search(0, i);
			if (flag)
			{
				ans = i;
				break;
			}
		}
		printf("Case #%d: ", icase);
		printf("%d\n", ans);
		ans = 0;
	}
	return 0;
}
