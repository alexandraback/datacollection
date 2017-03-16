#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
using namespace std;

vector<double> a;
vector<vector<char> > v;

bool print(int i, int j, bool start) {
	if (i < 0) {
		return false;
	}
	if (v[i][j]) {
		return print(i - 1, j, start);
	} else {
		if (!start) {
			cout << " ";
		}
		cout << a[i];
		print(i - 1, j - a[i], false);
		return true;
	}
}

int main() {
	int num_tests;
	cin >> num_tests;
	for (int test = 1; test <= num_tests; ++test) {
		int n;
		cin >> n;
		int sum = 0;
		a.resize(n);
		v.resize(n + 1);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		for (int i = 0; i <= n; ++i) {
			v[i].resize(sum + 1, false);
			v[i][0] = true;
		}
		bool done = false;
		for (int num = 1; num <= sum && !done; ++num) {
			for (int i = 0; i < n && !done; ++i) {
				v[i + 1][num] = v[i][num];
				if (a[i] <= num && v[i][num - a[i]]) {
					if (!v[i + 1][num]) {
						v[i + 1][num] = true;
					} else {
						cout << "Case #" << test << ":" << endl;
						print(i, num, true);
						cout << endl;
						bool nonempty = print(i, num - a[i], true);
						if (nonempty) {
							cout << " ";
						}
						cout << a[i] << endl;
						done = true;
					}
				}
			}
		}
	}
}
