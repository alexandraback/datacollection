#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

int N;
vector<int> A[101];
int cnt[2501];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	for (int Tc = 1; Tc <= T; ++Tc) {
		cerr << "Case " << Tc << endl;
		cin >> N;
		for (int i = 1; i <= 2500; ++i) cnt[i] = 0;
		for (int i = 1; i < 2 * N; ++i) for (int j = 1; j <= N; ++j) {
			int in; cin >> in; cnt[in] ^= 1;
		}
		vector<int> ans(1);
		for (int i = 1; i <= 2500; ++i) if (cnt[i]) ans.push_back(i);
		printf("Case #%d: ", Tc);
		for (int i = 1; i <= N; ++i) printf("%d ", ans[i]); printf("\n");
	}
}