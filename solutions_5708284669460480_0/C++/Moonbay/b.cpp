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
const int MAXN = 10;
char keyboards[MAXN];
char target[MAXN];
int K, L, S;
int maxb, casenum, bnanum;
char data[MAXN];

void dfs(int step) {
	if (step == S) {
		casenum++;
		int b = 0;
		for (int off = 0; off <= S - L; off++) {
			int i = 0;
			for (; i < L; i++) {
				if (target[i] != data[off + i]) {
					break;
				}
			}
			if (i == L) {
				b++;
			}
		}
		bnanum += b;
		if (b > maxb) {
			maxb = b;
		}
		return ;
	}
	for (int k = 0; k < K; k++) {
		data[step] = keyboards[k];
		dfs(step + 1);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &K, &L, &S);
		scanf(" %s %s", keyboards, target);
		casenum = bnanum = maxb = 0;
		dfs(0);
		printf("Case #%d: %.7lf\n", t, maxb - (bnanum + 0.0) / casenum);
	}
	return 0;
}


