#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int N;
		cin >> N;
		map<int, int> cnt;
		for (int i = 0; i < N * 2 - 1; ++i) {
			for (int j = 0; j < N; ++j) {
				int x;
				cin >> x;
				cnt[x]++;
			}
		}
		printf("Case #%d:", nc);
		for (map<int, int>::iterator e = cnt.begin(); e != cnt.end(); ++e) {
			if (e->second % 2 == 1)
				cout << " " << e->first;
		}
		cout << endl;
	}
	return 0;
}
