#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int testcases;
int n;
vector<int> g;
int ans;
int ans2;

int getRing(int i) {
//	cout << "i " << i << endl;
	int j = g[i];
	for (int k = 0; k < n; k ++) {
//		cout << j << endl;
		if (j < i) return -1;
		if (j == i) {
			return k + 1;
		}
		j = g[j];
	}
	return -1;
}

int getLongest(int i, int j) {
	int ans = 0;
	vector<bool> al(n, false);
	queue<int> q;
	queue<int> qd;
	al[i] = true;
	al[j] = true;
	q.push(i);
	qd.push(0);
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		int kd = qd.front();
		qd.pop();
		if (kd > ans) ans = kd;
		for (int l = 0; l < n; l ++) {
			if (al[l]) continue;
			if (g[l] == k) {
				al[l] = true;
				q.push(l);
				qd.push(kd + 1);
			}
		}
	}
	return ans;

}

int main() {
	cin >> testcases;
	for (int testcase = 0; testcase < testcases; testcase ++) {
		cin >> n; 
		g.resize(n);
//		al.resize(n);
		for (int i = 0; i < n; i ++) {
			int tmp;
			cin >> tmp;
			g[i] = tmp - 1;
//			cout << g[i] << " ";
//			al[i] = false;
		}
//		cout << endl;
		ans = 0;
		ans2 = 0;
		for (int i = 0; i < n; i ++) {
//			if (al[i]) continue;
			int k = g[i];
			if (k < i) continue;
//			if (al[k]) continue;
//			al[i] = true;
//			cout << i << " " << k << endl;
			if (g[k] == i) {
				// ans2
//				al[k] = true;
				ans2 += 2 + getLongest(i, k) + getLongest(k, i);
			} else {
				int tmp = getRing(i);
				if (tmp > ans) ans = tmp;				
			}
		}

		if (ans2 > ans) ans = ans2;
		cout << "Case #" << testcase + 1 << ": " << ans << endl;
	}

	return 0;	
}