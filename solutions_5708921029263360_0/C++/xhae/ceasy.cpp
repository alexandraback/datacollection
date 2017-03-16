#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		int jackets, pants, shirts, K;
		scanf("%d %d %d %d", &jackets, &pants, &shirts, &K);
		vector<tuple<int, int, int>> ans;
		bool isUsed[10][10][10] = {false, };
		int jpcnt[10][10] = {0, }, jscnt[10][10] = {0, }, pscnt[10][10] = {0, };
		while(true) {
			int maxValue = K;
			tuple<int, int, int> curans;
			for(int i = 0; i < jackets; i++)
				for(int j = 0; j < pants; j++) {
					if(jpcnt[i][j] >= maxValue) continue;
					for(int k = 0; k < shirts; k++) {
						if(isUsed[i][j][k]) continue;
						if(jscnt[i][k] >= maxValue) continue;
						if(pscnt[j][k] >= maxValue) continue;

						maxValue = max({jpcnt[i][j], jscnt[i][k], pscnt[j][k]});
						curans = tuple<int, int, int>{i, j, k};
					}
				}

			if(maxValue == K) break;

			int cj, cp, cs;
			tie(cj, cp, cs) = curans;
			isUsed[cj][cp][cs] = true;
			jpcnt[cj][cp]++;
			jscnt[cj][cs]++;
			pscnt[cp][cs]++;
			ans.push_back(curans);
		}

		printf("Case #%d: %d\n", kase, (int)ans.size());
		for(auto v: ans) printf("%d %d %d\n", get<0>(v) + 1, get<1>(v) + 1, get<2>(v) + 1);
	}

	return 0;
}