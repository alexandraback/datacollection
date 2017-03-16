#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, a;
int ans;
int seq[111];
void dfs(int idx, int val, int mov)
{
	if (idx == n+1) {
		ans = min(ans, mov);
		return;
	}
	if (seq[idx] >= val) {
		if (val != 1)
			dfs(idx, val+val-1, mov+1);
		ans = min(ans, mov + (n-idx+1));
	} else {
		dfs(idx+1, val+seq[idx], mov);
	}
}
int main()
{
	int tests;
	cin>>tests;
	for (int test = 1; test <= tests; test++) {
		cin>>a>>n;
		for (int i = 1; i <= n; i++) cin>>seq[i];
		sort(seq+1, seq+n+1);
		ans = 1e9;
		dfs(1, a, 0);
		cout<<"Case #"<<test<<": "<<ans<<endl;
	}
	return 0;
}