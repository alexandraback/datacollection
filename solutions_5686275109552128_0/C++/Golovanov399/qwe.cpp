#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int ans = 1000000000;
	for (int i = 1; i < 1010; i++){
		int cur = i;
		for (int j = 0; j < n; j++)
			cur += (a[j] + i - 1) / i - 1;
		ans = min(ans, cur);
	}
	printf("%d\n", ans);
}

int main(){

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		printf("Case #%d: ", i + 1);
		solve();
		cerr << "Test #" << i + 1 << " completed\n";
	}

	return 0;
}