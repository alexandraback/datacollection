#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 1010;
int a[N], b[N];
int flag[N];
int n, ans, have;

int f() {
	bool finish = true;
	for (int i = 0; i < n; ++i) {
		if (flag[i] != 2) {
			finish = false;
			break;
		}
	}
	if (finish) return 1;
	for (int i = 0; i < n; ++i) {
		if (flag[i] != 2 && have >= b[i]) {
			if (flag[i] == 1) have++;
			else have += 2;
			flag[i] = 2;
			ans++;
//			printf("level2 %d", i);
			return 0;
		}
	}
	int index = -1;
	for (int i = 0; i < n; ++i) {
		if (flag[i] != 0) continue;
		if (have >= a[i]) {
			if (index == -1 || b[i] > b[index]) {
				index = i;
			}
		}
	}
//	printf("level1 %d", index);
	if (index == -1) return -1;
	flag[index] = 1;
	have++;
	ans++;
	return 0;
}

void solve() {
	scanf("%d", &n);
	memset(flag, 0, sizeof(flag));
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", a + i, b + i);
	}
	ans = 0;
	have = 0;
	while (1) {
		int chk = f();
//		printf("(%d)\n", chk);
		if (chk == 1) break;
		if (chk == -1) {
			puts("Too Bad");
			return;
		}
	}
	printf("%d\n", ans);
}

int main() {
//	freopen("in","r",stdin);
//	freopen("in.txt","r",stdin);
	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; ++i) {
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
