#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int ca = 1; ca <= T; ++ca) {
		long long ans = 0;
		int n;
		cin >> n;
		vector<string> a;
		vector<int> idx;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			a.push_back(s);
			idx.push_back(i);
		}
		do {
			string s = "";
			for (int i = 0; i < n; ++i) {
				int j = idx[i];
				s = s + a[j];
			}
			int f[26];
			bool flag = true;
			memset(f, -1, sizeof(f));
			for (int i = 0; s[i]; ++i) {
				int t = s[i] - 'a';
				if (f[t] != -1 && f[t] != i - 1) {
					flag = false;
					break;
				}
				f[t] = i;
			}
			if (flag)
				++ans;
		} while (next_permutation(idx.begin(), idx.end()));
		printf("Case #%d: %lld\n", ca, ans % 1000000007);
	}
	return 0;
}
