#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		string t;
		cin >> t;
		int ans = 0;
		for (int i = 0; i + 1 < t.size(); ++i) {
			if (t[i] != t[i + 1])
				++ans;
		}
		if (t[t.size() - 1] == '-')
			++ans;
		printf("Case #%d: %d\n", nc, ans);
	}
}
