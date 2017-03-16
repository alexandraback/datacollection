#include <iostream>
using namespace std;

static int values[1010];
static int used[1010];
static int target[1010];

int ans, C, D, V;

static int check() {
	int i;
	for (i = 1; i <= V; ++i) {
		if (target[i] == 0)
			return i;
	}
	return 0;
}

static void cover(int value) {
	int i;
	if (value > V)
		return;
	target[value] = 1;

	for (i = 0; i < D; ++i) {
		if (!used[i]) {
			used[i] = 1;
			value = value + values[i];
			cover(value);
			value = value - values[i];
			used[i] = 0;
		}
	}
}

static void solve() {
	int ret;
	while (1) {
		cover(0);
		ret = check();
		if (ret == 0)
			break;
		ans++;
		values[D++] = ret;
		memset(used, 0, sizeof(used));
	}
	return;
}

int main()
{
	int T, t;
	int i;
	scanf("%d\n", &T);
	for (t = 1; t <= T; ++t) {
		ans = 0;
		memset(values, 0, sizeof(values));
		memset(used, 0, sizeof(used));
		memset(target, 0, sizeof(target));
		scanf("%d %d %d\n", &C, &D, &V);
		for (i = 0; i < D; ++i) {
			scanf("%d", &values[i]);
		}
		solve();
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}