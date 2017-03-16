#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char x[100];
char y[100];
typedef pair<int, int> P;
vector<P> v;

int main() {
	int C;
	cin >> C;
	for (int c = 0; c < C; ++c) {
		int A, B;
		cin >> A >> B;
		sprintf(x, "%d", A);
		int len = strlen(x);
		sprintf(x, "%d", B);
		assert( len == strlen( x ) );
		int cnt = 0;
		for (int n = A; n < B; ++n) {
			sprintf(x, "%d", n);
			v.clear();
			for (int i = 1; i < len; ++i) {
				strncpy(y + i, x, len - i);
				strncpy(y, x + len - i, i);
				y[len] = 0;
				int m = atoi(y);
				if (n < m && m <= B) {
					v.push_back(P(n, m));
				}
			}
			if (v.size() == 0)
				continue;
			sort(v.begin(), v.end());
			++cnt;
			for (int i = 1; i < (int) v.size(); ++i) {
				if (v[i] != v[i - 1]) {
					++cnt;
				} else {
					//cerr << "DUP: " << v[i].first << ' ' << v[i].second << endl;
				}
			}
		}
		cout << "Case #" << c + 1 << ": " << cnt << endl;
	}
	return 0;
}
