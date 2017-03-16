#include <iostream>
#include <vector>

using namespace std;

struct chest {
	int k;
	vector<int> a;
};

int T, K, N;
vector<int> a(200), r(200), f(200), p(200), o(200);
vector<chest> c(200);
bool found = false;

void go(int n, int m, int index)
{
	if (m == 0) {
		o = p;
		found = true;
	}
	if (found || n == 0) return;

	bool next = true;;
	for (int i = 0; i < N && next; i++) {
		int k = c[i].k;
		if (f[i] == 0 && a[k] > 0) {
			a[k]--;
			r[k]--;
			f[i] = 1;
			p[index] = i + 1;
			for (int j = 0; j < c[i].a.size(); j++) a[c[i].a[j]]++;
			if (r[k] == 0 || a[k] > 0) next = false;
			go(n - 1 + c[i].a.size(), m - 1, index + 1);
			if (found) return;
			for (int j = 0; j < c[i].a.size(); j++) a[c[i].a[j]]--;
			f[i] = 0;
			r[k]++;
			a[k]++;
		}
	}
}

int main(int argc, char *argv[])
{
	cin >> T;

	for (int t = 0; t < T; t++) {
		int k, n;
		cin >> K >> N;
		a.assign(200, 0);
		r.assign(200, 0);
		for (int i = 0; i < K; i++) {
			cin >> k;
			a[k - 1]++;
		}
		for (int i = 0; i < N; i++) {
			cin >> c[i].k >> n;
			c[i].k--;
			r[c[i].k]++;
			c[i].a.clear();
			for (int j = 0; j < n; j++) {
				cin >> k;
				c[i].a.push_back(k - 1);
			}
		}

		found = false;
		f.assign(N, 0);
		go(K, N, 0);

		cout << "Case #" << (t + 1) << ":";
		if (found) {
			for (int i = 0; i < N; i++)
				cout << " " << o[i];
		} else {
			cout << " IMPOSSIBLE";
		}
		cout << endl;
	}

	return 0;
}
