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

inline bool isPalin(long long x) {
	if (!x)
		return true;
	string res = "";
	while (x) {
		res.push_back(x % 10);
		x /= 10;
	}
	for (int i = 0, j = (int)(res.size()) - 1; i < j; i++, j--)
		if (res[i] != res[j])
			return false;
	return true;
}

void solve() {
	long long a, b;
	cin >> a >> b;
	long long l = sqrt(a * 1.0);
	while (l * l >= a)
		l--;
	while (l * l < a)
		l++;

	long long ans = 0;
	for (long long cur = l; cur * cur <= b; cur++) {
		if (!isPalin(cur))
			continue;
		if (!isPalin(cur * cur))
			continue;
//		cout << "DEBUG: " << cur * cur << endl;
		ans++;
	}
	cout << ans << endl;
}

int main() {
	freopen("C-small-attempt0.in","r", stdin);
	freopen("B_output.txt","w", stdout);
	int T;
	scanf("%d\n", &T);
	for (int i = 0; i < T; i++) {
		printf("Case #%d: ", i + 1);
		solve();
	}
}
