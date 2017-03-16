#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

const int maxn = 110;
const long long inf = 1e17;

int n;
vector< long long > a;
pair< long long, long long> ans[maxn][2];
long long x;


pair<long long, long long> calc(pair< long long, long > startp, long long end) {
	long long start = -startp.second;
	end = -end;
	if (start <= 1) {
		return make_pair(inf, 0ll);
	}

	long long res = 0;
	while (start <= end)
	{
		res++;
		start += start - 1;
	}
	start += end;
	return make_pair(startp.first + res, -start);
}

void solve() {
	cin >> x >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < 2; j++)
			ans[i][j] = make_pair(inf, 0);

	ans[0][0] = make_pair(1ll, -x);
	ans[0][1] = calc(make_pair(0, -x), -a[0]);

	for (int i = 1; i < n; i++) {
		ans[i][0] = min(ans[i-1][1], ans[i-1][0]);
		ans[i][0].first += 1;
		ans[i][1] = min(calc(ans[i-1][1], -a[i]),
				        calc(ans[i-1][0], -a[i]));
	}

	cout <<(min(ans[n-1][0], ans[n-1][1]).first) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("A_input.txt","r", stdin);
	freopen("A_output.txt","w", stdout);
#endif
	int testnum;
	scanf("%d\n", &testnum);
	for (int i = 0; i < testnum; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}
}
