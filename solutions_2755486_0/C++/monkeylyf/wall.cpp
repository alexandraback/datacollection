#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

struct attack {
	int day;
	int w;
	int e;
	int s;
};

struct attack attacks[1000];

int max(int x, int y) {
	return x > y ? x : y;
}

int compare (const void * a, const void * b)
{
  return (((struct attack *)a)->day - ((struct attack *)b)->day);
}

int toindex(int x) {
	return x * 2;
}
int simulate(int n) {
	int succeeds = 0;
	int wall0[10000];
	int* wall  = wall0 + 5000;
	memset(wall0, 0, sizeof(wall0));
	
	int i = 0;
	while (i < n) {
		int j = i + 1;
		while (j < n && attacks[i].day == attacks[j].day) j++;
		j--;
		// Compute attacks successes
		for(int idx = i; idx <= j; idx++) {
			for (int x = toindex(attacks[idx].w); x <= toindex(attacks[idx].e); x++) {
				if (wall[x] < attacks[idx].s) {
					succeeds++;
					break;
				}
			}
		}

		// Rebuid wall
		for(int idx = i; idx <= j; idx++) {
			for (int x = toindex(attacks[idx].w); x <= toindex(attacks[idx].e); x++) {
				wall[x] = max(wall[x], attacks[idx].s);
			}
		}
		
		i = j + 1;
	}

	return succeeds;
}

int main() {
	int problem;
	setbuf(stdout, NULL);
	
	scanf("%d\n", &problem);
	
	for(int pi=0; pi<problem; pi++) {
		int N;
		int d, n, w, e, s, dd, dp, ds;

		scanf("%d\n", &N);
		int attack_num = 0;
		for (int j=0; j<N; j++) {
			scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
			for(int i=0; i < n; i++) {
				attacks[attack_num].day = d + i * dd;
				attacks[attack_num].w = w + i * dp;
				attacks[attack_num].e = e + i * dp;
				attacks[attack_num].s = s + i * ds;
				
				attack_num++;
			}
		}
		qsort(attacks, attack_num, sizeof(struct attack), compare);
		
		printf("Case #%d: %d\n", pi+1, simulate(attack_num));

	}
	return 0;
}
