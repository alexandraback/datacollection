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
char pancakes[110];
bool pan[110];
int pannum;

void inline flippan(int n) {
	bool *first = pan;
	bool *last = first + n;
	while ((first != last) && (first != --last)) {
		bool tmp = !(*last);
		*last = !(*first);
		*first = tmp;
		++first;
	}
	if (n % 2 == 1) {
		pan[n / 2] = !pan[n / 2];
	}
}

int work() {
	int ans = 0;
	while (pannum > 0) {
		while (pannum > 0 && pan[pannum - 1]) {
			pannum--;
		}
		if (pannum <= 0) {
			break;
		}
		int I = 0;
		while (pan[I]) {
			I++;
		}
		if (I > 0) {
			flippan(I);
			ans++;
		}
		flippan(pannum);
		ans++;
	}
	return ans;
}

int main() {
//	freopen("b.small.in", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf(" %s", pancakes);
		pannum = strlen(pancakes);
		for (int i = 0; i < pannum; i++) {
			if (pancakes[i] == '-') {
				pan[i] = 0;
			} else {
				pan[i] = 1;
			}
		}
		printf("Case #%d: %d\n", t, work());
	}
	return 0;
}


