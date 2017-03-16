#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int N;

void run() {
	vector<int> vec[1020];
	bool visit[1020];

	scanf("%d", &N);
	for (int i = 1;i <= N; i++) {
		int a, b;
		scanf("%d" ,&a);
		for (int j = 0; j < a; j++) {
			scanf("%d" ,&b);
			vec[i].push_back(b);
		}
	}
	bool ok = 0;
	for (int i = 1; i <= N; i++) {
		if (ok) break;
		queue<int> que;
		memset(visit, 0, sizeof(visit));
		que.push(i);
		visit[i] = 1;
		while(que.size()) {
			int k = que.front();
			que.pop();
			for (int j = 0; j < vec[k].size(); j++) {
				que.push(vec[k][j]);
				if (visit[vec[k][j]])  {
					ok = 1;
					break;
				}
				visit[vec[k][j]] = 1;
			}
			if (ok) break;
		}
	}
	if (ok) printf(" Yes\n");
	else printf(" No\n");
}

int main() {

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int cases;
	scanf("%d", &cases);

	for (int cas = 1; cas <= cases; cas++) {
		printf("Case #%d:", cas); 
		run();
	}
	return 0;
}
