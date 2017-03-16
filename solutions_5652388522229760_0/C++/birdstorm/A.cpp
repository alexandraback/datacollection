#include <bits/stdc++.h>
using namespace std;
long long check(int x) {
	int cnt[10];
	for(int i = 0; i <= 9; i ++) cnt[i] = 0;
	long long num = 10, c = 0, ret = 0;
	while(num > 0) {
		c += x;
		int v = c;
		assert(v > 0);
		while(v > 0) {
			if(!cnt[v % 10]) {
				cnt[v % 10] = 1;
				-- num;
			}
			v /= 10;
		}
	}
	return c;
}
long long ans[1000005];
void init(int N) {
	for(int i = 1; i <= N; i ++) {
		ans[i] = check(i);
	}
}
int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	init(1000000);
	int T; cin>>T;
	for(int cs = 1; cs <= T; cs ++) {
		cerr << "Processing Case #" << cs <<"...\n";
		int n; cin >> n;
		printf("Case #%d: ", cs);
		if(n == 0) puts("INSOMNIA");
		else printf("%d\n", ans[n]);
	}
	return 0;
}
