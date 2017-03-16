#include <stdio.h>
#include <algorithm>

using namespace std;

double naomi[1024];
double ken[1024];

int main() {
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n; i++) scanf("%lf",&naomi[i]);
		for(int i = 0; i < n; i++) scanf("%lf",&ken[i]);
		sort(naomi, naomi+n);
		sort(ken, ken+n);
		int scoreDeceit = 0, scoreWar = n;
		for(int i = 0, j = 0; i < n && j < n; j++){
			if (ken[i] < naomi[j]) {
				scoreDeceit++;
				i++;
			}
		}
		for(int i = 0, j = 0; i < n && j < n; i++){
			if (ken[i] > naomi[j]) {
				scoreWar--;
				j++;
			}
		}

		printf("Case #%d: %d %d\n", testcase, scoreDeceit, scoreWar);
	}
}