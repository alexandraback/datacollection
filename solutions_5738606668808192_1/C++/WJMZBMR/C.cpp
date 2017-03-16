#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <cstdlib>
#include <vector>
using namespace std;

const int PRIMES[] = { 2, 3, 5, 7, 11, 13, 17, 19 };
int N, J;

bool check(int bits[]) {
	for (int b = 2; b <= 10; ++b) {
		bool ok = false;
		for (int pid = 0; pid < 8; ++pid) {
			int p = PRIMES[pid];
			int x = 0;
			for (int i = N - 1; i >= 0; --i) {
				x = x * b + bits[i];
				x %= p;
			}
			if (x == 0) {
				ok = true;
				break;
			}
		}
		if (!ok)
			return false;
	}
	return true;
}

vector<int> get(int bits[]) {
	vector<int> ret;
	for (int b = 2; b <= 10; ++b) {
		for (int pid = 0; pid < 8; ++pid) {
			int p = PRIMES[pid];
			int x = 0;
			for (int i = N - 1; i >= 0; --i) {
				x = x * b + bits[i];
				x %= p;
			}
			if (x == 0) {
				ret.push_back(p);
				break;
			}
		}
	}
	return ret;
}

int main() {
	int _;
	cin >> _;
	cin >> N >> J;
	map<string, vector<int> > ans;
	while (ans.size() < J) {
		int bits[32];
		for (int i = 0; i < N; ++i) {
			bits[i] = rand() % 2;
		}
		bits[0] = bits[N - 1] = 1;
		if (check(bits)) {
			string w = "";
			for (int i = N - 1; i >= 0; --i) {
				w += char('0' + bits[i]);
			}
			ans[w] = get(bits);
		}
	}
	printf("Case #%d:\n", 1);
	for (map<string, vector<int> >::iterator e = ans.begin(); e != ans.end();
			++e) {
		cout << e->first;
		for (vector<int>::iterator it = (e->second).begin();
				it != (e->second).end(); ++it) {
			cout << " " << *it;
		}
		cout << endl;
	}
}
