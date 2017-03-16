#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD	1000000007

char s[128][128];
int l[128];
int o[128];

int main(int argc, char *argv[])
{
	int T, n;

	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			l[i] = strlen(s[i]);
			o[i] = i;
		}

		long long ans = 0;
		do {
			bool failed = false;
			vector<bool> v(26);
			char prev = -1;
			for (int k = 0; k < n; k++) {
				int i = o[k];
				for (int j = 0; j < l[i]; j++) {
					if (prev >= 0 && s[i][j] != prev && v[s[i][j] - 'a']) {
						failed = true;
						break;
					}
					prev = s[i][j];
					v[prev - 'a'] = true;
				}
				if (failed) break;
			}
			if (!failed) ans++;
		} while (next_permutation(o, o + n));

		printf("Case #%d: %lld\n", ti, ans);
	}

	return 0;
}
