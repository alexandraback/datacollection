#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int T = 0;
	int TK = 0;
	scanf("%d",&T);
	while (T--) {
		printf("Case #%d:", ++TK);

		int N = 0;
		scanf("%d",&N);

		set<int> ooxx;
		for(int i = 0;i < 2*N-1;i++) {
			for(int j = 0;j < N;j++) {
				int x = 0;
				scanf("%d",&x);
				auto it = ooxx.find(x);
				if (it == ooxx.end()) {
					ooxx.insert(x);
				} else {
					ooxx.erase(it);
				}
			}
		}

		for(auto x: ooxx) {
			printf(" %d",x);
		}
		puts("");
	}
	return 0;
}