#include <iostream>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

map<int, int> m;

int flip(int x) {
	int r = 0;
	while (x) {
		r = r * 10 + (x%10);
		x /= 10;
	}
	return r;
}

int q[1000002], h, t;

void run() {
	int x;
	cin >> x;
	if (x == 1) {
		cout << 1 << endl;
		return;
	}
	m.clear();
	h=0; t=1; q[0] = x; m[x] = 1;
	while (1) {
		int tmp = q[h++];
		// cout << "searching " << tmp << " = " << m[tmp] << endl;
		if (tmp == 1) {
			cout << m[tmp] << endl;
			return;
		}
		if (flip(flip(tmp)) == tmp && (flip(tmp) < tmp) && m[flip(tmp)] == 0) {
			q[t++] = flip(tmp);
			m[flip(tmp)] = m[tmp]+1;
		}
		if (m[tmp-1] == 0) {
			q[t++] = tmp-1;
			m[tmp-1] = m[tmp]+1;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cout << "Case #" << i << ": ";
		run();
	}
	return 0;
}
