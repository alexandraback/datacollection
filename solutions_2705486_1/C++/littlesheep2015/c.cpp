#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#include <tr1/unordered_set>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

char s[2000000];

const ll MOD = 3872478274873757ll;
const ll MUL = 37;

ll getHash(char s[], int length) {
	ll ret = 0;
	REP(i, length) {
		ret = (ret * MUL + s[i] - 'a' + 1) % MOD;
	}

	return ret;
}

tr1::unordered_set<ll> hash0;
tr1::unordered_set<ll> hash1[10];
tr1::unordered_set<ll> hash2[10][10];

int dp[5555][6];

// void dfs(int now, int aim, int last, int cost, ll hash) {
// 	if (now == aim) {
// 		if (::hash.find(hash) != ::hash.end()) {
// 			dp[now - 1][min(4, now - 1 - last)] = min(dp[now - 1][min(4, now - 1 - last)], cost);
// 		}

// 		return;
// 	}

// 	if (now - last >= 5) {
// 		REP(i, 26) {
// 			if (i + 'a' != s[now - 1]) {
// 				dfs(now + 1, aim, now, cost + 1, (hash * MUL + i + 1) % MOD);
// 			}
// 		}
// 	}

// 	dfs(now + 1, aim, last, cost, (hash * MUL + s[now - 1] - 'a' + 1) % MOD);
// }

void solve() {
	scanf("%s", s);
	// REP(i, 100) s[i] = 'a';
	// s[100] = 0;
	int length = strlen(s);
	REP(i, length + 1) REP(j, 5) dp[i][j] = 0x3f3f3f3f;
	dp[0][4] = 0;
	for (int i = 1; i <= length; ++i) {
		for (int j = max(0, i - 10); j < i; ++j) {
			REP(k, 5) {
				if (0x3f3f3f3f == dp[j][k]) continue;
				// dfs(j + 1, i + 1, j - k, dp[j][k], 0);
				int last = j - k;
				int newLength = i - j;

				char *start = s + j;

				if (hash0.find(getHash(start, newLength)) != hash0.end()) {
					dp[i][min(4, i - last)] = min(dp[i][min(4, i - last)], dp[j][k]);
				}

				for (int t = j + 1; t <= i; ++t) {
					if (t - last >= 5) {
						char tmp = s[t - 1];
						s[t - 1] = 'z' + 1;
						if (hash1[t - j - 1].find(getHash(start, newLength)) != hash1[t - j - 1].end()) {
							dp[i][min(4, i - t)] = min(dp[i][min(4, i - t)], dp[j][k] + 1);
						}
						s[t - 1] = tmp;
					}
				}

				for (int t = j + 1; t <= i; ++t) {
					char tmp = s[t - 1];
					s[t - 1] = 'z' + 1;
					if (t - last >= 5) {
						for (int r = t + 5; r <= i; ++r) {
							char tmp1 = s[r - 1];
							s[r - 1] = 'z' + 1;
							if (hash2[t - j - 1][r - j - 1].find(getHash(start, newLength)) != hash2[t - j - 1][r - j - 1].end()) {
								dp[i][min(4, i - r)] = min(dp[i][min(4, i - r)], dp[j][k] + 2);
							}
							s[r - 1] = tmp1;
						}
					}
					s[t - 1] = tmp;
				}
			}
		}
	}

	int ans = 0x3f3f3f3f;
	REP(i, 5) ans = min(ans, dp[length][i]);

	cout << ans << endl;
}

int main() {
	FILE *dict = fopen("garbled_email_dictionary.txt", "r");
	int length = 0;
	int words = 0;
	while (fscanf(dict, "%s", s) != EOF) {
		int length = strlen(s);
		hash0.insert(getHash(s, length));
		for (int i = 0; i < length; ++i) {
			char t = s[i];
			s[i] = 'z' + 1;
			hash1[i].insert(getHash(s, length));
			s[i] = t;
		}

		for (int i = 0; i < length; ++i) {
			char t = s[i];
			s[i] = 'z' + 1;
			for (int j = i + 5; j < length; ++j) {
				char q = s[j];
				s[j] = 'z' + 1;
				hash2[i][j].insert(getHash(s, length));
				s[j] = q;
			}
			s[i] = t;
		}

		// if (++words%100==0) cout << words << endl;
	}
	fclose(dict);

	int T;
	cin >> T;
	for (int nowCase = 1; nowCase <= T; ++nowCase) {
		cout << "Case #" << nowCase << ": ";
		solve();
	}
	return 0;
}