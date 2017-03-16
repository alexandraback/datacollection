#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	int cur = 0;
	for (int i = 0; i <= n; i++){
		if (cur < i){
			ans++;
			cur++;
		}
		cur += s[i] - '0';
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