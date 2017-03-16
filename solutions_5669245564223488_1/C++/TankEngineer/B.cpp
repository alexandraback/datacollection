#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100, L = 105, MOD = 1000000007, C = 26;
char car[N][L];

int head[C], tail[C], mid[C], all[C], fac[N + 1], ll[N];

bool used[C], appear[C];

int go(int i) {
	used[i] = true;
	int ret = fac[all[i]];
	if (tail[i] == -1) {
		return ret;
	} else {
		return (long long)ret * go(car[tail[i]][ll[tail[i]] - 1] - 'a') % MOD;
	}
}

int main() {
	fac[0] = 1;
	for (int i = 1; i <= 100; ++i) {
		fac[i] = (long long)fac[i - 1] * i % MOD;
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		static int id = 0;
		printf("Case #%d: ", ++id);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s", car[i]);
			ll[i] = strlen(car[i]);
		}
		bool error = false;
		for (int i = 0; i < 26 && !error; ++i) {
			appear[i] = false;
			char ch = 'a' + i;
			head[i] = -1, tail[i] = -1, mid[i] = -1, all[i] = 0;
			for (int j = 0; j < n; ++j) {
				int l = ll[j];;
				vector<int> pos;
				for (int k = 0; k < l; ++k) {
					if (car[j][k] == ch) {
						pos.push_back(k);
					}
				}
				if (pos.size() == 0) {
					continue;
				}
				appear[i] = true;
				if ((pos.back() - pos.front()) + 1 != pos.size()) {
					error = true;
				} else {
					if (pos.size() == l) {
						++all[i];
					} else {
						if (pos[0] == 0) {
							if (tail[i] != -1) {
								error = true;
							}
							tail[i] = j;
						} else if (pos.back() == l - 1) {
							if (head[i] != -1) {
								error = true;
							}
							head[i] = j;
						} else {
							if (mid[i] != -1) {
								error = true;
							}
							mid[i] = j;
						}
					}
				}
			}
			if (mid[i] != -1 && (all[i] > 0 || head[i] != -1 || tail[i] != -1)) {
				error = true;
			}
		}
		if (error) {
			printf("0\n");
			continue;
		}
		int ans = 1, cnt = 0;
		memset(used, 0, sizeof(used));
		for (int i = 0; i < 26; ++i) {
			if (appear[i] && head[i] == -1 && mid[i] == -1) {
				++cnt;	
				ans = (long long)ans * go(i) % MOD;
			}
		}
		ans = (long long)ans * fac[cnt] % MOD;
		for (int i = 0; i < 26; ++i) {
			if (appear[i] && !used[i] && mid[i] == -1) {
				ans = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
