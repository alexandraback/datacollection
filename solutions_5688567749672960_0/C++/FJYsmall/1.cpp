#include <bits/stdc++.h>

using namespace std;

const int SIZE = 10000000;

int w[SIZE];

int get(int x) {
	int res = 0;
	while (x) {
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}

int main()
{
	queue<int> Q;
	Q.push(1);
	w[1] = 1;
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		int x = u + 1;
		if (!w[x] && x < SIZE) {
			w[x] = w[u] + 1;
			Q.push(x);
		}
		int y = get(u);
		if (!w[y] && y < SIZE) {
			w[y] = w[u] + 1;
			Q.push(y);
		}
	}
	/*
	for (int i = 1; i < SIZE; i++) {
		printf("%d %d\n", i, w[i]);
	}
	*/
	int T, n;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d", &n);
		printf("Case #%d: %d\n", cas, w[n]);
	}
	return 0;
}
