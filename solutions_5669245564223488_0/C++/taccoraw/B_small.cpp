#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 10
#define MAXL 100
int N;
char sets[MAXN][MAXL+1];
int ans;
unsigned int used;
unsigned int done;
char cur;
void dfs(int d) {
	if (d >= N) {
		ans++;
	} else {
		for (int i = 0; i < N; i++) {
			if (used & (1 << i))
				continue;
			unsigned int odone = done;
			char ocur = cur;
			bool ok = true;
			for (char* p = sets[i]; *p && ok; p++) {
				if (*p == cur)
					continue;
				if (done & (1 << (*p - 'a')))
					ok = false;
				else {
					done |= 1 << (cur - 'a');
					cur = *p;
				}
			}
			if (!ok) {
				done = odone;
				cur = ocur;
				continue;
			}
			used |= 1 << i;
			dfs(d+1);
			used &= ~(1 << i);
			done = odone;
			cur = ocur;
		}
	}
}
int main() {
	int T = 0;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%s", sets[i]);
		ans = 0;
		used = 0;
		done = 0;
		cur = -1;
		dfs(0);
		printf("Case #%d: ", t+1);
		printf("%d\n", ans);
	}
	return 0;
}

