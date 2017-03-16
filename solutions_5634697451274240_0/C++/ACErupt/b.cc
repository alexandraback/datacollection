// run: $exec < b-small.in > b-small.out
#include <iostream>
#include <queue>
#include <string>

int const maxn = 10000;
bool vis[maxn];
int dis[maxn];
int n;
std::string s;

int state(std::string const & s)
{
	int ret = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == '-') ret += 1 << i;
	return ret;
}

int change(int x, int l)
{
	int tmp = x % (1 << l);
	x >>= l;
	x <<= l;
	for (int i = 0; i < l; i++, tmp /= 2) {
		int t = !(tmp & 1);
		x |= t * (1 << (l - i - 1));
	}
	return x;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T; std::cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		std::cout << "Case #" << ti << ": ";
		for (int i = 0; i < maxn; i++) vis[i] = false;
		std::cin >> s;
		n = s.size();
		int start = state(s);
		dis[start] = 0;
		std::queue<int> q;
		q.push(start);
		vis[start] = true;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			if (!now) { std::cout << dis[now] << '\n'; break; }
			for (int i = 1; i <= n; i++) {
				int tmp = change(now, i);
				if (vis[tmp]) continue;
				vis[tmp] = true;
				dis[tmp] = dis[now] + 1;
				q.push(tmp);
			}
		}
	}
}

