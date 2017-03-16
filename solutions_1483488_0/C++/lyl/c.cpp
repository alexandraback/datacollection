#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int maxn = 2000001;
vector<int> rec[maxn];
int pw[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 1000000, 10000000};


int getdig(int n) {
	int bb = 10, res = 1;
	while (n >= bb) {
		bb *= 10;
		res++;
	}
	return res;
}

void preprocess() {
	for (int i = 1; i < maxn; i++) {
		int n = getdig(i), tmp = i;
		set<int> ss;
		for (int j = 0; j < n - 1; j++) {
			int d = tmp % 10;
			tmp = (tmp / 10) + d * pw[n - 1];
			if (tmp >= pw[n - 1] && tmp < i) {
				if (ss.count(tmp) == 0) {
					ss.insert(tmp);
					rec[i].push_back(tmp);
				}
			}
		} 
		sort(rec[i].begin(), rec[i].end());
	}
}

int main() {
	preprocess();
/*
	for (int i = 900; i < 999; i++) {
		for (int j = 0; j < rec[i].size(); j++)
			cout << rec[i][j] << " ";
		cout << endl;
	}
*/
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; tt++) {
		long long res = 0;
		int a, b;
		cin >> a >> b;
		for (int i = a; i <= b; i++) {
			int tot = (int) (rec[i].end() - lower_bound(rec[i].begin(), rec[i].end(), a));
			res += tot;
		}

		printf("Case #%d: %lld\n", tt, res);
	}
}
