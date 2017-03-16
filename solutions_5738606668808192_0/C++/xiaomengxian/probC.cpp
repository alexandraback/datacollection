#include <iostream>
#include <vector>
using namespace std;
int n, m;
int cnt = 0;
vector<int> v;

long long convert(vector<int> & v, int b) {
	long long ans = 0;
	long long now = 1;
	for (int i = 0; i < v.size(); i ++) {
		if (v[i] == 1) 
			ans = ans + now;
		now *= b;
	}
	return ans;
}

bool prime(long long c, long long & d) {
	d = 0;
	if (c % 2 == 0) d = 2;
	if (c % 3 == 0) d = 3;
	if (c % 5 == 0) d = 5;
	if (c % 7 == 0) d = 7;
	if (c % 11 == 0) d = 11;
	if (c % 13 == 0) d = 13;
	if (c % 17 == 0) d = 17;
	if (c % 19 == 0) d = 19;
	return d == 0;
}

void search(int index) {
	if (index == n - 1) {
		bool ok = true;
		vector<long long> ans;
		for (int i = 2; i <= 10; i ++) {
			long long c = convert(v, i);
			long long d;
			if (prime(c, d)) {
				ok = false;
				break;
			}
			ans.push_back(d);
		}
		if (ok) {
			cnt ++;
			if (cnt <= m) {
				for (int i = v.size() - 1; i >= 0; i --) {
					cout << v[i];
				}
				for (int i = 0; i < ans.size(); i ++) {
					cout << " " << ans[i];
				}
				cout << endl;
			}
		}

		return ;
	}
	v[index] = 0;
	search(index + 1);
	v[index] = 1;
	search(index + 1);
}

int main() {
	int tmp;
	cin >> tmp;
	cin >> n >> m;

	v.resize(n);
	v[0] = 1;
	v[n - 1] = 1;

	cout << "Case #1:" << endl;

	search(1);

	return 0;
}