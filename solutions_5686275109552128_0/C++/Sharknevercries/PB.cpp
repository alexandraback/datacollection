#include<bits\stdc++.h>
using namespace std;
int n;
int w[1005];
int solve(int s){
	int res = s;
	for (int i = 0; i < n; i++)
		res += ceil((double)w[i] / s) - 1;
	return res;
}
int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", w + i);
		int R = 0, ans = 1e9;
		for (int i = 0; i < n; i++)
			R = max(R, w[i]);
		for (int i = 1; i <= R; i++)
			ans = min(ans, solve(i));
		printf("Case #%d: %d\n", c++, ans);
	}
	return 0;
}