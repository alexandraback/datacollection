// run: $exec < c-large.in > c-large.out
// opt: 0
// flag: -g
#include <iostream>
#include <cstring>

int const maxn = 2000;
int head[maxn], end_point[maxn * 2], next[maxn * 2];
int alloc = 2;
bool vis[maxn];
int a[maxn];
int n;
int max;
int max_len[maxn];

void add_edge(int u, int v)
{
	end_point[alloc] = v; next[alloc] = head[u]; head[u] = alloc++;
}

void dfs(int x, int start, int l)
{
	vis[x] = true;
	if (a[x] == start) { max = std::max(max, l); return; }
	if (vis[a[x]]) return;
	dfs(a[x], start, l + 1);
}

int dfs1(int x)
{
	vis[x] = true;
	int ret = 0;
	for (int p = head[x]; p; p = next[p]) {
		int v = end_point[p];
		if (vis[v]) continue;
		ret = std::max(ret, dfs1(v) + 1);
	}
	return ret;
}

void init()
{
	alloc = 2;
	std::memset(head, 0, sizeof(head));
	std::memset(vis, 0, sizeof(vis));
	max = 0;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		std::cout << "Case #" << ti << ": ";
		init();
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			add_edge(i, a[i]);
		}
		for (int i = 1; i <= n; i++) {
			std::memset(vis, 0, sizeof(vis));
			dfs(i, i, 1);
		}

		std::memset(head, 0, sizeof(head));
		alloc = 2;

		for (int i = 1; i <= n; i++) {
			if (a[a[i]] == i) continue;
			add_edge(a[i], i);
		}

		for (int i = 1; i <= n; i++) {
			std::memset(vis, 0, sizeof(vis));
			max_len[i] = dfs1(i);
		}

		int sum = 0;
		std::memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			if (a[a[i]] == i) {
				sum += max_len[i] + max_len[a[i]] + 2;
				vis[i] = vis[a[i]] = true;
			}
		}
		std::cout << std::max(max, sum) << '\n';
	}
}

