#include <stdio.h>
#include <assert.h>

int n;
int g[1000][1000];
int l[1000];
int visited[1000];
int begin;

bool rec (int ind) {
	if ((ind != begin && visited[ind] == 1) || (ind == begin && visited[ind] == 2)) {
		return true;
	}
	visited[ind]++;
	for (int i = 0; i < l[ind]; ++i) {
		if (rec(g[ind][i])) {
			return true;
		}
	}
	return false;
}

bool is_loop (int ind) {
	for (int i = 0; i < n; ++i) {
		visited[i] = 0;
	} // special case for ind !!!!
	begin = ind;
	return rec(ind);
}

int main (void) {
    int T;
    int scanned = scanf("%d", &T);
    for (int currentcase = 1; currentcase <= T; ++currentcase) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &l[i]);
			for (int j = 0; j < l[i]; ++j) {
				scanf("%d", &g[i][j]);
				--g[i][j];
			}
		}
		bool loop = false;
		for (int i = 0; i < n; ++i) {
			if (is_loop(i)) {
				loop = true;
				break;
			}
		}
		printf("Case #%d: %s\n", currentcase, loop ? "Yes" : "No");
    }
    return 0;
}
