#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
void solve() {
	int R, N, M, K;
	cin >> R >> N >> M >> K;
	char buf[10];
	map<string, set<int> > hoge;
	map<string, int> cnt;
	for (int i = 2; i <= 5; ++ i) {
		for (int j = i; j <= 5; ++ j) {
			for (int k = j; k <= 5; ++ k) {
				sprintf(buf, "%d%d%d", i, j, k);
				set<int> s;
				for (int t = 0; t < 8; ++ t) {
					int p = 1;
					if (t&1) p *= i;
					if (t&2) p *= j;
					if (t&4) p *= k;
					s.insert(p);
				}
				hoge[buf] = s;
			}
		}
	}
	for (int i = 2; i <= 5; ++ i) {
		for (int j = 2; j <= 5; ++ j) {
			for (int k = 2; k <= 5; ++ k) {
				int a[3] = {i, j, k};
				sort(a, &a[3]);
				sprintf(buf, "%d%d%d", a[0], a[1], a[2]);
				++ cnt[buf];
			}
		}
	}
	for (int i = 0; i < R; ++ i) {
		int c = 0;
		string r;
		vector<int> a(K);
		for (int j = 0; j < K; ++ j) cin >> a[j];
		for (map<string, set<int> >::iterator it = hoge.begin(); it != hoge.end(); ++ it) {
			for (int j = 0; j < K; ++ j) {
				if (it->second.count(a[j]) == 0) goto next;
			}
			if (cnt[it->first] > c) {
				c = cnt[it->first];
				r = it->first;
			}
			next:;
		}
		cout << r << endl;
	}
}
int main() {
	int T;
	cin >> T;
	cout << "Case #1:" << endl;
	solve();
}
