#include <algorithm>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define SIZE(v) ((int)(v).size())

#define BEGIN(v) ((v).begin())
#define END(v) ((v).end())
#define ALL(v) BEGIN(v),END(v)
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v);(v).erase(unique(ALL(v)),END(v))

#define FOR(i,l,r) for(int i=(l);i<(r);i++)
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)

const int MAXN = 100;

int n, m, mat[MAXN][MAXN], rowMax[MAXN], columnMax[MAXN];

bool isValid() {
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			if (mat[i][j] != min(rowMax[i], columnMax[j])) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int taskNumber;
	scanf("%d", &taskNumber);
	for (int taskIdx = 1; taskIdx <= taskNumber; taskIdx++) {
		scanf("%d%d", &n, &m);
		memset(rowMax, 0, sizeof(rowMax));
		memset(columnMax, 0, sizeof(columnMax));
		FOR(i, 0, n) {
			FOR(j, 0, m) {
				scanf("%d", &mat[i][j]);
				rowMax[i] = max(rowMax[i], mat[i][j]);
				columnMax[j] = max(columnMax[j], mat[i][j]);
			}
		}
		printf("Case #%d: %s\n", taskIdx, isValid() ? "YES" : "NO");
	}
	return 0;
}
