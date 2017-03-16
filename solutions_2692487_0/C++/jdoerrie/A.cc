#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> & motes, int A, int idx) {
	if (A == 1) {
		return motes.size() - idx;
	}
	int changes = 0;
	while (idx < motes.size())  {
 		if (A > motes[idx]) {
 			A += motes[idx++];
		}

		else if (2 * A - 1 > motes[idx]) {
 			A += A-1;
 			A += motes[idx++];
 			changes++;
		}

		else {
			return changes + min((int) motes.size() - idx, 1 + solve(motes, 2*A - 1, idx));
		}
	}
	return changes;
}


int main(int argc, char const *argv[]) {
	int T;
	scanf("%d", &T);

	for (int cas = 0; cas < T; ++cas) {
		int A, N;
		scanf("%d %d", &A, &N);
		vector<int> motes(N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &motes[i]);
		}

		sort(motes.begin(), motes.end());

		int res = solve(motes, A, 0);

		printf("Case #%d: %d\n", cas + 1, res);
	}
	return 0;
}