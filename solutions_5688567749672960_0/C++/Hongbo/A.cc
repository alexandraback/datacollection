#include <iostream>
#include <queue>
using namespace std;

inline int rev_dig(int m) {
	int res = 0;
	while (m) {
		res = res * 10 + m % 10;
		m /= 10;
	}
	return res;
}

int solve2() {
	int n;
	cin >> n;
	queue <pair <int, int> > q;
	q.push(make_pair(1, 1));
	while (!q.empty()) {
		int s = q.front().first, a = q.front().second;
		q.pop();
		if (a == n) return s;
		q.push(make_pair(s + 1, a + 1));
		int r = rev_dig(a);
		if (r > a) q.push(make_pair(s + 1, r));
	}
	return -1;
}

inline int get_first(int n) {
	while (n >= 10) n /= 10;
	return n;
}

int solve() {
	int n, ans = 0;
	cin >> n;
	while (n > 10) {
		int f = get_first(n);
		int l = n % 10;
		cout << n << " " << f << " " << l << " ";
		if (f == 1) {
			n -= (l + 1);
			ans += (l + 1);
		}
		else if (f >= l) {
			n = rev_dig(n);
			n -= (f - l + 1);
			ans += (f - l + 1) + 1;
		}
		else {
			n -= (l - f + 1);
			ans += (l - f + 1);
		}
		cout << n <<" " << ans<< endl;
	}
	return ans + n;
}

#include <string.h>
int a[1000010];

void dp() {
	memset(a, 0x3f, sizeof(a));
	a[1] = 1;
	for (int i = 1; i <= 1000000; i ++) {
		a[i + 1] = min(a[i] + 1, a[i + 1]);
		int r = rev_dig(i);
		a[r] = min(a[i] + 1, a[r]);
	}
}

int get() {
	int n;
	cin >> n;
	return a[n];
}

int main() {
	int T;
	cin >> T;
	dp();
	for (int i = 1; i <= T; i ++) 
		cout << "Case #" << i << ": " << get() << endl;
	return 0;
}
