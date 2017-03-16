#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2000001;
const int POW10[9] = {
	1, 
	10, 
	100, 
	1000, 
	10000,
	100000,
	1000000,
	10000000,
	100000000
};

vector <int> v[MAXN];
bool tag[MAXN];

void init() {
	for (int i = 1; i < MAXN; i++) {
		if (tag[i]) continue;
		int len;
		char token[32];
		sprintf(token, "%d", i);
		len = strlen(token);
		sprintf(token, "%d%d", i, i);
		int MOD = POW10[len], j = i;
		for (int k = 0; k < len; k++) {
			if (token[k] != '0' && j < MAXN) {
				v[i].push_back(j);
				tag[j] = true;
			}
			j = (j * 10 + token[k + len] - '0') % MOD;
		}
		sort(v[i].begin(), v[i].end());
		v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
	}
}

int main() {
	init();
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 0; taskIdx < taskNumber; taskIdx++) {
		int A, B, res = 0;
		scanf("%d%d", &A, &B);
		for (int i = 1; i < MAXN; i++) {
			if (v[i].empty()) continue;
			int idx1 = lower_bound(v[i].begin(), v[i].end(), A) - v[i].begin();
			int idx2 = upper_bound(v[i].begin(), v[i].end(), B) - v[i].begin();
			res += (idx2 - idx1) * (idx2 - idx1 - 1) / 2;
		}
		printf("Case #%d: %d\n", taskIdx + 1, res);
	}
	return 0;
}
