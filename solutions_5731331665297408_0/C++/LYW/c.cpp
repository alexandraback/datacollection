#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N, M;
vector < pair < string, int > > Idx;

int adj[51][51];
int canReach[51][51];
int visit[51];
int outStack[51];
int inStack[51];

int numReach(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!outStack[i] && !outStack[j])
				canReach[i][j] = adj[i][j];
			else 
				canReach[i][j] = 0;
		}
		canReach[i][i] = 1;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				canReach[i][j] = canReach[i][j] || (canReach[i][k] &&
				canReach[k][j]);
			}
		}
	}
	
	int flag[51];
	for (int i = 0; i < N; i++)
		flag[i] = visit[i];
	for (int i = 0; i < N; i++) {
		if (!outStack[i] && visit[i]) {
			for (int j = 0; j < N; j++) {
				if (i != j && canReach[i][j])
					flag[j] = 1;
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < N; i++)
		ret += flag[i];

	return ret;
}

void getAns(int d, int x) {
	visit[x] = 1;
	inStack[d] = x;
	printf("%s", Idx[x].first.c_str());

	if (d == N - 1) {
		outStack[x] = 1;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i])
			continue;
		if (adj[x][i]) {
			getAns(d + 1, i);
			if (outStack[x] == 1)
				return;
		} else {
			int is_connected = false;
			int depth_connected;
			for (int j = d - 1; j >= 0; j--) {
				if (adj[inStack[j]][i]) {
					is_connected = true;
					depth_connected = j;
					break;
				}
			}
			if (!is_connected)
				continue;
			// Simulation
			for (int j = depth_connected + 1; j <= d; j++)
				outStack[inStack[j]] = 1;
			if (numReach() == N) {
				outStack[x] = 1;
				return;
			}
			for (int j = depth_connected + 1; j <= d; j++)
				outStack[inStack[j]] = 0;
		}
	}
	outStack[x] = 1;
}

int main(void) {
	int testNum;
	scanf("%d", &testNum);
	char str[10];
	int invert_idx[51];
	for (int testCase = 1; testCase <= testNum; testCase++) {
		scanf("%d %d", &N, &M);
		Idx.clear();
		for (int i = 0; i < N; i++) {
			scanf("%s", str);
			Idx.push_back(make_pair((string)(str), i));
		}
		sort(Idx.begin(), Idx.end());

		for (int i = 0; i < N; i++) {
			invert_idx[Idx[i].second] = i;
			visit[i] = 0;
			outStack[i] = 0;
			for (int j = 0; j < N; j++) {
				adj[i][j] = 0;
			}
		}

		for (int i = 0; i < M; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[invert_idx[a - 1]][invert_idx[b - 1]] = 1;
			adj[invert_idx[b - 1]][invert_idx[a - 1]] = 1;
		}

		printf("Case #%d: ", testCase);

		getAns(0, 0);
		printf("\n");
	}

	return 0;
}
