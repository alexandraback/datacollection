#include <cstdio>
#include <cstring>
#include <algorithm>

#define INF (1<<30)

using namespace std;

int T, n;
pair<int,int> X[10000];
int visited[10000];

int solve() {
	int stars = 0, moves = 0;
	bool progress = true;
	
	memset(visited, 0, sizeof(visited));

	while (progress) {
		progress = false;
	
		for (int i = 0; i < n; i++) {
			if (visited[i] < 2 && X[i].first <= stars) {
				moves++;
				progress = true;
				stars += 2 - visited[i];
				
				visited[i] = 2;
			}
		}
	
		if (progress) continue;
	
		for (int i = 0; i < n; i++) {
			if (visited[i] < 1 && X[i].second <= stars) {
				moves++;
				progress = true;
				stars++;
			
				visited[i] = 1;
			
				break;
			}
		}
	}
	
	if (stars == 2 * n) {
		return moves;
	} else {
		return INF;
	}
}

int main() {
	scanf("%d\n", &T);

	for (int nCase = 1; nCase <= T; nCase++) {
		scanf("%d\n", &n);

		for (int i = 0; i < n; i++) {
			scanf("%d %d\n", &X[i].second, &X[i].first);
			visited[i] = 0;
		}

		bool possible;
		int ans = INF;
		
		sort(X, X + n);
		reverse(X, X + n);
		ans = min(ans, solve());

		if (ans != INF) {
			printf("Case #%d: %d\n", nCase, ans);
		} else {
			printf("Case #%d: Too Bad\n", nCase);
		}
		
		fflush(stdout);
	}
}
