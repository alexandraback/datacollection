#include "sstream"
#include "iostream"
#include "cstdio"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "vector"
#include "map"
#include "set"
#include "queue"
#include "deque"
#include "list"
#include "string"
#include "cassert"

using namespace std;

vector<int> ans;

int uniq(vector<int> _vt) {
	return unique(_vt.begin(), _vt.end()) - _vt.begin();
}

bool dfs(int now, int N, int M, vector<int> &prod, vector<int> vt)
{
	if (vt.size() == N) {
		int p = 1;
		for (int j = 0; j < N; j++) {
			p *= vt[j];
		}
		int cnt = 0;
		for (int k = 0; k < prod.size(); k++) {
			if (p % prod[k] == 0) {
				cnt++;
			}
		}
		if (cnt == prod.size() && uniq(ans) < uniq(vt)) {
			ans = vt;
			return true;
		}
		return false;
	}
	if (now > M) {
		return false;
	}
	int r = N - vt.size();
	for (int i = 0 ; i <= r; i++) {
		dfs(now+1, N, M, prod, vt);
		vt.push_back(now);
	}
	return false;
}

int main()
{
	int T, t = 1;
	for (scanf("%d", &T); T--; ) {
		printf("Case #%d:\n", t++);
		int R, N, M, K;
		scanf("%d%d%d%d", &R, &N, &M, &K);
		for (int i = 0; i < R; i++) {
			vector<int> prod(K);
			for (int k = 0; k < K; k++) {
				scanf("%d", &prod[k]);	
			}
			ans.clear();
			dfs(2, N, M, prod, vector<int>());
			if (ans.empty()) {
				for (int j = 0; j < N; j++) {
					printf("2");
				}
			} else {
				assert(ans.size() == N);
				for (int j = 0; j < N; j++) {
					printf("%d", ans[j]);
				}
			}
			puts("");
		}
	}
	return 0;
}

