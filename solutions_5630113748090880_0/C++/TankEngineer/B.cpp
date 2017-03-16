#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		static int id = 0;
		printf("Case #%d: ", ++id);
		map<int, int> tr;
		scanf("%d", &n);
		for (int i = 0; i < 2 * n - 1; ++i) {
			for (int j = 0; j < n; ++j) {
				int b;
				scanf("%d", &b);
				++tr[b];
			}
		}
		int cnt = 0;
		for (map<int, int>::iterator it = tr.begin(); it != tr.end(); ++it) {
			if (it->second % 2 == 1) {
				++cnt;
				printf("%d%c", it->first, cnt == n ? '\n' : ' ');
			}
		}
	}
	return 0;
}
