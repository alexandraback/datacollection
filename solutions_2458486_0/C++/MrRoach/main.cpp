#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int numKeysInit[201];
int openCase[21];
int t, n, k;
int cases[21][201];
int states[1 << 20];
vector<int> codeList[22];

int countOne(int x) {
	int count = 0;
	while (x != 0) {
		count += (x & 1);
		x >>= 1;
	}
	return count;
}

int main() {
	cin >> t;
	for (int caseNum = 0; caseNum < t; ++caseNum) {
		cin >> k >> n;
		memset(numKeysInit, 0, sizeof(numKeysInit));
		memset(openCase, 0, sizeof(openCase));
		memset(cases, 0, sizeof(cases));
		for (int i = 0; i < k; ++i) {
			int key = 0;
			cin >> key;
			numKeysInit[key - 1] ++;
		}
		for (int i = 0; i < n; ++i) {
			int keyNum, keyType;
			cin >> keyType >> keyNum;
			openCase[i] = keyType - 1;
			for (int j = 0 ; j < keyNum; ++j) {
				int key = 0;
				cin >> key;
				cases[i][key - 1] ++;
			}
		}

		for (int i = 0; i <= n; ++i) {
			codeList[i].clear();
		}
		for (int i = 0; i < (1 << n); ++i) {
			states[i] = -1;
			codeList[countOne(i)].push_back(i);
		}
		states[(1 << n) - 1] = 0;
		for (int bits = n - 1; bits >= 0; --bits) {
			for (int iter = 0; iter < codeList[bits].size(); ++iter) {
				int code = codeList[bits][iter];
				int numKeys[201];
				memcpy(numKeys, numKeysInit, sizeof(numKeysInit));
				for (int i = 0; i < n; ++i) {
					if (code & (1 << i)) {
						numKeys[openCase[i]] --;
						for (int j = 0; j < 200; ++j) {
							numKeys[j] += cases[i][j];
						}
					}
				}
				for (int i = 0; i < n; ++i) {
					if (!(code & (1 << i))
					&& (numKeys[openCase[i]] > 0)
					&& (states[code | (1 << i)] >= 0)) {
						states[code] = i;
						break;
					}
				}
			}
		}
		cout << "Case #" << caseNum + 1 << ":";
		if (states[0] < 0) {
			cout << " IMPOSSIBLE" << endl;
		} else {
			int code = 0;
			while (code != (1 << n) - 1) {
				cout << " " << states[code] + 1;
				code |= (1 << states[code]);
			}
			cout << endl;
		}
	}
	return 0;
}