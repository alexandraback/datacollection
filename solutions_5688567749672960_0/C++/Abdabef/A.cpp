#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int w, d, m, l, n, z;
bool vis[1000005];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;

int revers(int k) {
	w = 0;
	while (k > 0) {
		w *= 10;
		w += k % 10;
		k /= 10;
	}
	return w;
}

int counter() {
	while (true) {
		d = Q.top().first;
		m = Q.top().second;
		vis[m] = true;
		Q.pop();
		if (m == n) {
			return d;
		}
		l = revers(m);
		if (!vis[l] && l <= n) {
			vis[l] = true;
			Q.push(pair<int, int> (d + 1, l));
		}
		if (!vis[m + 1]) {
			vis[m + 1] = true;
			Q.push(pair<int, int> (d + 1, m + 1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> z;
	for (int i = 1; i <= z; i++) {
		cin >> n;
		Q.push(pair<int, int> (1, 1));
		cout << "Case #" << i << ": " << counter() << '\n';
		for (int j = 0; j <= n; j++) {
			vis[j] = false;
		}
		while (!Q.empty()) {
			Q.pop();
		}
 	}
}
