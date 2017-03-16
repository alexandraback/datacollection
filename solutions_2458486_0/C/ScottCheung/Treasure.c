#include <stdio.h>
#include <string.h>

struct chest
{
	int key[405], t, k;
}che[205];

int key[205], v[205], ans[205], finish, n;

void dfs(int x, int st)
{
	int i, j, nst;

	if (finish == 1)
		return;
	if (x > n) {
		for (i = 1; i <= n; i++)
			printf(" %d", ans[i]);
		putchar('\n');
		finish = 1;
		return;
	}
	for (i = st; i <= n; i++)
		if (!v[i] && key[che[i].t]) {
			ans[x] = i;
			v[i] = 1;
			key[che[i].t]--;
			for (j = 1; j <= che[i].k; j++)
				key[che[i].key[j]]++;
			for (nst = st; v[nst]; nst++)
				;
			dfs(nst, x + 1);
			for (j = 1; j <= che[i].k; j++)
				key[che[i].key[j]]--;
			key[che[i].t]++;
			v[i] = 0;
		}
}

int main()
{
	int i, j, k, t, ki, casen;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (casen = 1; casen <= t; casen++) {
		scanf("%d%d", &k, &n);
		memset(key, 0, sizeof(key));
		while (k--) {
			scanf("%d", &ki);
			key[ki]++;
		}
		for (i = 1; i <= n; i++) {
			scanf("%d%d", &che[i].t, &che[i].k);
			for (j = 1; j <= che[i].k; j++)
				scanf("%d", &che[i].key[j]);
		}
		printf("Case #%d:", casen);
		finish = 0;
		for (i = 1; i <= n && !finish; i++)
			if (key[che[i].t]) {
				memset(v, 0, sizeof(v));
				dfs(1, 1);
			}
		if (!finish)
			puts(" IMPOSSIBLE");
	}
	return 0;
}