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

inline long long getPaint(long long n, long long r) {
	return 2*(r + n-1) * n + n;
}

inline double getPaintD(double n, double r) {
	return 2*(r + n-1) * n + n;
}

void solve() {
	long long R;
	long long t;
	cin >> R >> t;

	long long l = 0;
	long long r = (long long)(10000)*(long long)(10000)*8; // 10^9
	while (r - l > 1) {
		long long m = (l+r) / 2;
		if (getPaintD(m, R) > 3 * t)
			r = m;
		else if (getPaint(m, R) > t)
			r = m;
		else
			l = m;
	}

	cout << l << endl;
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
