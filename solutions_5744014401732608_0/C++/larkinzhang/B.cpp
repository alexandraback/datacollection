#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
using namespace std;

int T, B, M;
int ans[10];
int tot[10];

void print_ans() {
	for (int i = 0; i < B; i++) {
		for (int k = 0; k < B; k++) {
			putchar(((ans[i] >> (B - k - 1)) & 1) ? '1' : '0');
		}
		puts("");
	}
}

bool DFS(int step) {
	if (step == B - 1) {
		memset(tot, 0, sizeof tot);
		tot[0] = 1;

		for (int i = 0; i < B; i++) {
			for (int k = i + 1; k < B; k++) {
				if ((ans[i] >> (B - k - 1)) & 1) {
					tot[k] += tot[i];
					if (tot[B - 1] > M) return false;
				}
			}
		}

		if (tot[B - 1] == M) {
			print_ans();
			return true;
		}

		return false;
	}

	for (int i = 0; i < (1 << (B - step - 1)); i++) {
		ans[step] = i;

		if (DFS(step + 1)) return true;
	}

	return false;
}	

int main() {
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		printf("Case #%d: ", test);

		scanf("%d%d", &B, &M);
		
		memset(ans, 0, sizeof ans);
		if (M > (1 << (B - 2))) {
			puts("IMPOSSIBLE");
		} else {
			puts("POSSIBLE");
			DFS(0);
		}
	}
	return 0;
}
