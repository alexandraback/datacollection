#include <stdio.h>
#include <limits.h>

void traverse(
		int idx,
		int start_idx,
		int length,
		int *bffs,
		int *chain_lengths,
		int *end_mutual,
		int *colors
) {
	int bff = bffs[idx];
	if (chain_lengths[idx] > length)
		return;
	if ((idx == start_idx) && (colors[idx] == start_idx)) {
		chain_lengths[idx] = length - 1;
		end_mutual[idx] = -1;
	}
	if (colors[idx] == start_idx) {
		return;
	}
	colors[idx] = start_idx;
	if (bffs[bff] == idx) {
		end_mutual[idx] = idx;
		end_mutual[bff] = bff;
		chain_lengths[idx] = 0;
		chain_lengths[bff] = 0;
	} else {
		if (chain_lengths[bff] < 0) {
			traverse(
					bff, start_idx,
					length + 1, bffs, chain_lengths,
					end_mutual, colors
			);
		}
		if (chain_lengths[bff] == 0) {
			chain_lengths[idx] = length;
			end_mutual[idx] = end_mutual[bff];
		} else {
			chain_lengths[idx] = chain_lengths[bff];
			end_mutual[idx] = end_mutual[bff];
		}
	}
}

void solve_testcase(int tc) {
	int bffs[1000];
	int chain_lengths[1000];
	int end_mutual[1000]; // -1 for cycles, -2 for not computed
	int colors[1000];
	int longest_cycle = 0;
	int n;
	int n_mutuals = 0;
	int mutuals[500];
	int total = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &(bffs[i]));
		bffs[i]--;
		chain_lengths[i] = -1;
		end_mutual[i] = -2;
		colors[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		traverse(i, i, 1, bffs, chain_lengths, end_mutual, colors);
	}
	for (int i = 0; i < n; ++i) {
		if (end_mutual[i] == -1) {
			if (longest_cycle < chain_lengths[i])
				longest_cycle = chain_lengths[i];
		}
		if (i == end_mutual[i]) {
			mutuals[n_mutuals++] = i;
		}
	}

	for (int j = 0; j < n_mutuals; ++j) {
		int len = 0;
		int col = -1;
		for (int i = 0; i < n; ++i) {
			if (end_mutual[i] != mutuals[j])
				continue;
			if (colors[i] == col)
				continue;
			if (chain_lengths[i] > len) {
				len = chain_lengths[i];
				col = colors[i];
			}
		}
		total += 1 + len;
	}

	if (total < longest_cycle)
		total = longest_cycle;

	//fprintf(stderr, "bffs:");
	//for (int i = 0; i < n; ++i) fprintf(stderr, " %d", bffs[i]);
	//fprintf(stderr, "\nchain_lengths:");
	//for (int i = 0; i < n; ++i) fprintf(stderr, " %d", chain_lengths[i]);
	//fprintf(stderr, "\nend_mutual:");
	//for (int i = 0; i < n; ++i) fprintf(stderr, " %d", end_mutual[i]);
	//fprintf(stderr, "\ntotal / longest cycle: %d / %d", total, longest_cycle);
	//fprintf(stderr, "\n");

	printf("Case #%d: %d\n", tc, total);
}

int main(void) {
	int n_cases;
	scanf("%d", &n_cases);
	for (int i = 0; i < n_cases; ++i) {
		solve_testcase(i+1);
	}
	return 0;
}
