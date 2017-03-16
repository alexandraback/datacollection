#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 3000;

int a[N];

void work()
{
	memset(a, 0, sizeof a);
	int n;
	cin >> n;
	for(int i = 1; i < 2*n; ++i) {
		for(int u, j = 1; j <= n; ++j) {
			scanf("%d", &u);
			++a[u];
		}
	}
	vector<int> ans;
	for(int i = 1; i <= 2500; ++i) {
		if(a[i] % 2) {
			ans.push_back(i);
		}
	}
	sort(ans.begin(), ans.end());
	for(int i = 0; i < n-1; ++i) {
		printf("%d ", ans[i]);
	}
	cout << ans[n-1] << endl;
}

int main()
{
	#define LOCAL_
	#ifdef LOCAL
	freopen("0.in", "r", stdin);
	freopen("0.out", "w", stdout);
	#endif

	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cout << "Case #" << i << ": ";
		work();
	}
	return 0;
}
