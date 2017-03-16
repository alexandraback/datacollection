#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int N, J;
int ans[] = {0, 0, 3, 7, 5, 6, 31, 8, 27, 5, 77};
void print(int num[40]) {
	-- J;
	for(int i = 0; i < N; i ++) {
		printf("%d", num[i]);
	}
	for(int i = 2; i <= 10; i ++) {
		printf(" %d", ans[i]);
	}
	puts("");
}
void dfs(int pos, int num[40]) {
	if(J == 0) return;
	if(pos == 0) return;
	if(pos >= 3 && num[pos] == 0 && num[pos - 3] == 0) {
		num[pos] = num[pos - 3] = 1;
		print(num);
		dfs(pos, num);
		num[pos] = num[pos - 3] = 0;
	}
	dfs(pos - 1, num);
}
int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int T; cin>>T;
	for(int cs = 1; cs <= T; cs ++) {
		cerr << "Processing Case #" << cs <<"...\n";
		cin >> N >> J;
		int num[40];
		for(int i = 0; i < N; i ++) {
			num[i] = 0;
		}
		num[0] = num[3] = num[N - 1] = num[N - 4] = 1;
		printf("Case #%d:\n", cs);
		print(num);
		dfs(N, num);
		assert(J == 0);
	}
	return 0;
}
