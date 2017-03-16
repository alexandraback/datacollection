#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <math.h>
using namespace std;

int i, j, k, kejsis, kejs, n;
int ret;
vector<int> v[1001];
int w[1001];
bool done;

void go2(int kam, int m) {
	if (w[kam] != m && w[kam] > 0) {
		done = true;
		return;
	}
	if (w[kam] > 0) return;
	w[kam] = m;
	int i;
	for (i = 0; !done && i < (int)v[kam].size(); i++) {
		go2(v[kam][i], m);
	}
}

void go(int kam) {
	w[kam] = 1;
	int i, j;
	j = 1;
	for (i = 0; !done && i < (int)v[kam].size(); i++) {
		go2(v[kam][i], j);
		j++;
	}
}

int main() {
	scanf("%d", &kejsis);
	for (int kejs = 1; kejs <= kejsis; ++kejs) {
		printf("Case #%d: ", kejs);
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			v[i].clear();
			scanf("%d", &k);
			while (k-- > 0) {
				scanf("%d", &j);
				v[i].push_back(j);
			}
		}
		for (i = 1; i <= n; i++) {
			fprintf(stderr, "%d\n", i);
			for (j = 1; j <= n; j++) w[j] = 0;
			done = false;
			go(i);
			if (done) goto end;
		}
end:
		if (done) printf("Yes\n");
		else printf("No\n");

	}
	return 0;
}
