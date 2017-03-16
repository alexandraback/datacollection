#include <bits/stdc++.h>

using namespace std;

vector<int> reve[128];
vector<int> len2;
vector<long> chain2;
int nxt[128];
bool visited[128];
bool in[128];
int len[128];
long chainlen[128];

long N;

long getRevChain(long now) {
	long ans = 0;
	visited[now] = true;
	for (const auto &r : reve[now]) {
		if (visited[r]) continue;
		long cur = getRevChain(r);
		if (ans < cur) ans = cur;
	}
	return ans + 1;
}

int main(void) {
	ios::sync_with_stdio(false);
	long T;
	cin >> T;
	for (long t = 1; t <= T; ++ t) {
		cin >> N;
		memset(nxt, 0, sizeof nxt);
		memset(len, 0, sizeof len);
		memset(chainlen, 0, sizeof chainlen);
		memset(in, 0, sizeof in);
		len2.clear();
		for (long i = 1; i <= N; ++ i) {
			reve[i].clear();
		}
		for (long i = 1; i <= N; ++ i) {
			long x;
			cin >> x;
			nxt[i] = x;
			reve[x].push_back(i);
		}
		long ans = 0;
		for (long i = 1; i <= N; ++ i) {
			memset(visited, 0, sizeof visited);
			visited[i] = true;
			long cnt = 1;
			long now = i;
			for (;;) {
				now = nxt[now];
				if (now == i) {
					len[i] = cnt;
					break;
				}
				++ cnt;
				if (visited[now]) {
					len[i] = 0;
					break;
				}
				visited[now] = true;
			}
			if (len[i] == 2) {
				if (!in[nxt[i]]) {
					len2.push_back(i);
					in[i] = true;
				}
				memset(visited, 0, sizeof visited);
				visited[i] = true;
				visited[nxt[i]] = true;
				chainlen[i] = getRevChain(i);
			}
			if (ans < len[i])
				ans = len[i];
		}
		long ans2 = (long) len2.size() << 1;
		if (ans2) {
			long maxmin = 0;
			for (const auto &now : len2) {
				ans2 += max(chainlen[now], chainlen[nxt[now]]) - 1;
				maxmin = max(maxmin, min(chainlen[now], chainlen[nxt[now]]) - 1);
			}
			ans2 += maxmin;
		}
		cout << "Case #" << t << ": " << max(ans, ans2) << endl;
	}
}
