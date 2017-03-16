#include <bits/stdc++.h>
using namespace std;

/*
 * You got a dream, you gotta protect it.
 */

typedef long long ll;

const int N = 4e6 + 1;
int vis[N], vs;

int BFS(int n) {
	if (n == 1)
		return 1;
	queue<int> qu;
	qu.push(1);
	vis[1] = ++vs;
	int lev = 2;
	while (!qu.empty()) {
		int siz = qu.size();
		while (siz--) {
			int v = qu.front();
			qu.pop();
			if (v + 1 < N && vis[v + 1] != vs) {
				if (v + 1 == n)
					return lev;
				vis[v + 1] = vs;
				qu.push(v + 1);
			}
			int rev = 0;
			for (; v; v /= 10)
				rev = rev * 10 + v % 10;
			if (vis[rev] != vs) {
				if (rev == n)
					return lev;
				vis[rev] = vs;
				qu.push(rev);
			}
		}
		++lev;
	}
	return -1;
}

int main(int argc, char **argv) {
//	freopen("A-small-attempt0.in", "r", stdin);
//	freopen("res.txt", "w", stdout);
	int t, k = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", k++, BFS(n));
	}
	return 0;
}