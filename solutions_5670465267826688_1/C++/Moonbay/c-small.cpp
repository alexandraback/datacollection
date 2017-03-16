/*
 * Author    : ben
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
typedef long long LL;

/**
 * ËÄÔª³Ë·¨
 */
int tmpdata[256][256];
void init() {
	int i = (int)'i', j = (int)'j', k = (int)'k';
	tmpdata[1][1] = 1;
	tmpdata[1][i] = i;
	tmpdata[1][j] = j;
	tmpdata[1][k] = k;
	tmpdata[i][i] = -1;
	tmpdata[i][j] = k;
	tmpdata[i][k] = -j;
	tmpdata[j][j] = -1;
	tmpdata[j][k] = i;
	tmpdata[k][k] = -1;
	tmpdata[i][1] = -i;
	tmpdata[j][1] = -j;
	tmpdata[k][1] = -k;
	tmpdata[j][i] = -k;
	tmpdata[k][i] = j;
	tmpdata[k][j] = -i;	
}
inline int mymult(int c1, int c2) {
	int ret = tmpdata[abs(c1)][abs(c2)];
	ret *= c1 / abs(c1) * c2 / abs(c2);
	return ret;
}

const int MAXC = 10010;
int result[MAXC][MAXC];
char str[MAXC];
int len;

bool work() {
	for (int s = 0; s < len; s++) {
		result[s][s] = str[s];
		for (int e = s + 1; e < len; e++) {
			result[s][e] = mymult(result[s][e - 1], str[e]);
		}
	}
	for (int i = 0; i < len - 2; i++) {
		if (result[0][i] != 'i') {
			continue;
		}
		for (int j = i + 1; j < len - 1; j++) {
			if (result[i + 1][j] == 'j' && result[j + 1][len - 1] == 'k') {
				return true;
			}
		}
	}
	return false;
}

int main() {
	//freopen("data.in", "r", stdin);
	init();
	int T, L, X;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d %d %s", &L, &X, str);
		for (int i = 1; i < X; i++) {
			memcpy(str + i * L, str, L);
		}
		len = L * X;
		printf("Case #%d: %s\n", t, work() ? "YES" : "NO");
	}
	return 0;
}

