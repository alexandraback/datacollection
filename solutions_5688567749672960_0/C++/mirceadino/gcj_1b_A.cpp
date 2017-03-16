#include<bits/stdc++.h>

using namespace std;

#define dbg(x) (cout<<#x<<" = "<<(x)<<'\n')

typedef long long int lld;
const int INF = (1LL << 30) - 1;
const lld LINF = (1LL << 62) - 1;
const int NMAX = 1000000 + 5;

int numberOfTests;
int N;
int viz[NMAX];
vector<int> V[NMAX];
deque<int> Q;

int reverse(int x) {
	int y = 0;
	while (x) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}

void bfs(int x) {
	memset(viz, 0, sizeof(viz));

	Q.clear();
	Q.push_back(x);
	viz[x] = 1;

	while (!Q.empty()) {
		x = Q.front();
		Q.pop_front();

		if (x == N)
			return;

		for (auto y : V[x])
			if (!viz[y]) {
				Q.push_back(y);
				viz[y] = viz[x] + 1;
			}
	}
}

int main() {
	cin.sync_with_stdio(false);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	scanf("%d", &numberOfTests);

	for (int i = 1; i <= NMAX - 5; i++) {
		V[i].push_back(i + 1);
		V[i].push_back(reverse(i));
	}

	for (int testcase = 1; testcase <= numberOfTests; testcase++) {
		scanf("%d", &N);

		bfs(1);

		printf("Case #%d: %d\n", testcase, viz[N]);
	}

	return 0;
}