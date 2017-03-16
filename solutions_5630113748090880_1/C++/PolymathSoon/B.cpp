#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool cnt[2501];
const int MAX_H = 2500;

void solve(FILE *ifp, FILE *ofp) {
	vector<int> ans;
	int x;
	for (int i = 1; i <= MAX_H; ++i) cnt[i] = 0;
	fscanf(ifp, "%d", &N);
	for (int i = 1; i < (N << 1); ++i) {
		for (int j = 0; j < N; ++j) {
			fscanf(ifp, "%d", &x);
			cnt[x] = !cnt[x];
		}
	}
	for (int i = 1; i  <= MAX_H; ++i)
		if (cnt[i]) ans.push_back(i);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < N; ++i)
		fprintf(ofp, "%d%c", ans[i], i == N - 1 ? '\n' : ' ');
}

int main() {
	int T;
	FILE *ifp = fopen("B.in", "r");
	FILE *ofp = fopen("B.out", "w");
	fscanf(ifp, "%d", &T);
	for (int t = 1; t <= T; ++t) {
		fprintf(ofp, "Case #%d: ", t);
		solve(ifp, ofp);
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}
