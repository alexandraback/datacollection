#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int WORDS = 521196;
const int maxlen = 10000;
const int inf = 1000000000;
char buf[12];
char s[maxlen];
int dp[maxlen][6];
set<string> dic[11];

void solve() {
	scanf("\n%s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 5; j++) {
			dp[i + 1][j] = inf;
		}
		for(int l = 1; l <= 10; l++) if(i - l + 1 >= 0) {
			string cur = string(s + i - l + 1, s + i + 1);
			if(dic[l].count(cur)) {
				for(int j = 0; j < 5; j++) {
					for(int k = 0; k <= min(4, j + l); k++) {
						dp[i + 1][k] = min(dp[i + 1][k], dp[i - l + 1][j]);
					}
				}
			}
			for(int pos = 0; pos < l; pos++) {
				for(char v = 'a'; v <= 'z'; v++) if(v != cur[pos]) {
					char old = cur[pos];
					cur[pos] = v;
					if(dic[l].count(cur)) {
						for(int j = max(4 - pos, 0); j < 5; j++) {
							for(int k = 0; k <= min(4, l - 1 - pos); k++) {
								dp[i + 1][k] = min(dp[i + 1][k], dp[i - l + 1][j] + 1);
							}
						}
					}
					cur[pos] = old;
				}
			}
			for(int pos1 = 0; pos1 < l; pos1++) {
				for(int pos2 = pos1 + 5; pos2 < l; pos2++) {
					for(char v1 = 'a'; v1 <= 'z'; v1++) if(v1 != cur[pos1]) {
						char old1 = cur[pos1];
						cur[pos1] = v1;
						for(char v2 = 'a'; v2 <= 'z'; v2++) if(v2 != cur[pos2]) {
							char old2 = cur[pos2];
							cur[pos2] = v2;
							if(dic[l].count(cur)) {
								for(int j = max(4 - pos1, 0); j < 5; j++) {
									for(int k = 0; k <= min(4, l - 1 - pos2); k++) {
										dp[i + 1][k] = min(dp[i + 1][k], dp[i - l + 1][j] + 2);
									}
								}
							}
							cur[pos2] = old2;
						}
						cur[pos1] = old1;
					}
				}
			}
		}
	}
	int ans = n;
	for(int i = 0; i < 5; i++) {
		ans = min(ans, dp[n][i]);
	}
	printf("%d\n", ans);
}

int main(int argc, char **argv) {
	FILE* fdic = fopen("garbled_email_dictionary.txt", "r");
	for(int i = 0; i < WORDS; i++) {
		fscanf(fdic, "\n%s", buf);
		string cur = buf;
		dic[cur.size()].insert(cur);
	}
	fclose(fdic);


	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int tt;
	scanf("%d", &tt);
	for(int t = 0; t < tt; ++t) {
		printf("Case #%d: ", t + 1);
		solve();
	}

	return 0;
}
