#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector < pair < int, int > > cities;

int adj[50][50];
int visit[50];
int outStack[50];
int stack[50];

int numReach(void) {
	bool is_connected[50][50];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!outStack[i] && !outStack[j])
				is_connected[i][j] = adj[i][j];
			else 
				is_connected[i][j] = 0;
		}
		is_connected[i][i] = 1;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (is_connected[i][k] && is_connected[k][j]) {
					is_connected[i][j] = 1;
				}
			}
		}
	}
	
	int flag[51];
	for (int i = 0; i < N; i++)
		flag[i] = visit[i];
	for (int i = 0; i < N; i++) {
		if (!outStack[i] && visit[i]) {
			for (int j = 0; j < N; j++) {
				if (i != j && is_connected[i][j])
					flag[j] = 1;
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < N; i++)
		ret += flag[i];

	return ret;
}

void findPath(int d, int x) {
	visit[x] = 1;
	printf("%d", cities[x].first);
	stack[d] = x;

	if (d == N - 1) {
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i])
			continue;

		if (adj[x][i]) {
			findPath(d + 1, i);
			if (outStack[x] == 1)
				return;
		} else {
			int depth_connected = -1;
			for (int j = d - 1; j >= 0; j--) {
				if (adj[stack[j]][i]) {
					depth_connected = j;
					break;
				}
			}

			for (int j = depth_connected + 1; j <= d; j++)
				outStack[stack[j]] = 1;

			if (numReach() == N)
				return;

			for (int j = depth_connected + 1; j <= d; j++)
				outStack[stack[j]] = 0;
		}
	}
	outStack[x] = 1;
}

int main(void) {
	int t;
	freopen ("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	scanf("%d", &t);

	for (int testCase = 1; testCase <= t; testCase++) {
		scanf("%d %d", &N, &M);
		cities.clear();
		for (int i = 0; i < N; i++) {
			int zip_code;
			scanf("%d", &zip_code);
			cities.push_back(make_pair(zip_code, i));
		}
		sort(cities.begin(), cities.end());

		for (int i = 0; i < N; i++) {
			visit[i] = 0;
			outStack[i] = 0;
			for (int j = 0; j < N; j++) {
				adj[i][j] = 0;
			}
		}

		for (int i = 0; i < M; i++) {
			int city1, city2;
			scanf("%d %d", &city1, &city2);
			int sorted_city1, sorted_city2;
			for (int j = 0; j < N; j++) {
				if (cities[j].second == city1 - 1)
					sorted_city1 = j;
				if (cities[j].second == city2 - 1)
					sorted_city2 = j;
			}

			adj[sorted_city1][sorted_city2] = 1;
			adj[sorted_city2][sorted_city1] = 1;
		}

		printf("Case #%d: ", testCase);
		findPath(0, 0);
		printf("\n");
	}

	fclose(stdout);
	return 0;
}
