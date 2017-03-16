#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <string>

#ifdef _WIN32
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#define inp(x) scanf("%d",&x)
#define inpf(x) scanf("%f",&x)

using namespace std;

typedef long long int ll;
typedef long long unsigned int ull;

const ll mod = 1000000007;

ll factorial(int n) {
	if (n == 0) {
		return 1;
	} else {
		return ((factorial(n - 1) * n) % mod);
	}
}

int main() {
	int T,N;
	int numBlocks;
	string s[100];
	ll numOptions;

	bool front[26];
	bool end[26];
	bool mid[26];
	bool visited[26];
	int fullCount[26];
	int to[26];


	cin >> T;

	for (int t = 1; t <= T; t++) {
		bool zeroOptions = false;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> s[i];
		}

		for (int i = 0; i < 26; i++) {
			front[i] = false;
			end[i] = false;
			mid[i] = false;
			fullCount[i] = 0;
			to[i] = -1;
		}

		for (int i = 0; i < N; i++) {
			bool isFull = true;
			for (int j = 0; j < s[i].length(); j++) {
				if (s[i][j] != s[i][0]) {
					isFull = false;
					break;
				}
			}

			if (isFull) {
				fullCount[s[i][0] - 'a']++;
			} else {

				if (front[s[i][0] - 'a'] || mid[s[i][0] - 'a']) {
					zeroOptions = true;
					break;
				}

				if (end[s[i][s[i].length() - 1] - 'a'] || mid[s[i][s[i].length() - 1] - 'a']) {
					zeroOptions = true;
					break;
				}

				front[s[i][0] - 'a'] = true;
				end[s[i][s[i].length() - 1] - 'a'] = true;
				to[s[i][0] - 'a'] = (s[i][s[i].length() - 1] - 'a');

				// check front symbol repeating
				for (int j = 1; j < s[i].length(); j++) {
					if (s[i][j] != s[i][j - 1] && s[i][j] == s[i][0]) {
						zeroOptions = true;
						break;
					}
				}
				if (zeroOptions) break;

				// check end symbol repeating
				for (int j = s[i].length() - 2; j >= 0; j--) {
					if (s[i][j] != s[i][j + 1] && s[i][j] == s[i][s[i].length() - 1]) {
						zeroOptions = true;
						break;
					}
				}
				if (zeroOptions) break;

				// check all other symbols in the middle
				for (int j = 1; j < s[i].length() - 1; j++) {
					if (s[i][j] != s[i][j - 1] && s[i][j] != s[i][0] && s[i][j] != s[i][s[i].length() - 1]) {
						if (mid[s[i][j] - 'a']) {
							zeroOptions = true;
							break;
						} else {
							mid[s[i][j] - 'a'] = true;
						}
					}
				}
				if (zeroOptions) break;
			}
		}

		if (zeroOptions) {
			cout << "Case #" << t << ": " << 0 << endl;
		} else {

			// check for mid & something
			for (int i = 0; i < 26; i++) {
				if (mid[i] && (front[i] || end[i] || fullCount[i] > 0)) {
					zeroOptions;
					break;
				}
			}

			// check for loops
			for (int i = 0; i < 26; i++) {

				for (int j = 0; j < 26; j++) {
					visited[j] = false;
				}

				visited[i] = true;
				while (to[i] != -1) {
					if (visited[to[i]]) {
						zeroOptions = true;
						break;
					} else {
						visited[to[i]] = true;
						to[i] = to[to[i]];
					}
				}
			}

			// compute numOptions
			numBlocks = 0;
			numOptions = 1;

			for (int i = 0; i < 26; i++) {
				numOptions *= factorial(fullCount[i]);
				numOptions %= mod;

				if (!end[i] && (fullCount[i] > 0 || front[i])) {
					numBlocks++;
				}
			}

			numOptions *= factorial(numBlocks);
			numOptions %= mod;

			if (zeroOptions) {
				cout << "Case #" << t << ": " << 0 << endl;
			} else {
				cout << "Case #" << t << ": " << numOptions << endl;
			}
		}
	}

	return 0;
}
