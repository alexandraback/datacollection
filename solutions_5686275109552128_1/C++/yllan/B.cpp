#include <algorithm>
#include <cstdio>

#define MAX 2001

// int smallest(long *h, int bound)
// {
// 	if (bound <= 3) return bound;

// }

// int best_for(int x, int m)
// {
// 	int best = x;
// 	for (int move = 1; move < x; move++) {
// 		int cost = m * move + (x / (move + 1)) + !!(x % (move + 1));
// 		if (cost < best) best = cost;
// 	}
// 	return best;
// }

int solve(int d, int *p)
{
	// make histogram
	long h[MAX] = {0};
	int bound = 0;
	for (int i = 0; i < d; i++) {
		h[p[i]]++;
		if (p[i] > bound) bound = p[i];
	}

	int best_cost = bound; // no move
	
	for (int limit_height = bound - 1; limit_height > 0; limit_height--) {
		int cost = limit_height;
		int moves = 0;
		for (int x = limit_height + 1; x <= bound; x++) {
			moves += h[x] * (x / limit_height + !!(x % limit_height) - 1);
		}
		cost += moves;

		if (cost < best_cost) {
			// printf("limit: %d cost: %d\n", limit_height, cost);
			best_cost = cost;
		}
	}
	return best_cost;
}

int main()
{
	int t_max = 0;

	scanf("%d", &t_max);
	for (int t = 1; t <= t_max; t++) {
		int d;
		int p[MAX];
		scanf("%d", &d);
		for (int i = 0; i < d; i++) {
			scanf("%d", &p[i]);
		}
		printf("Case #%d: %d\n", t, solve(d, p));
	}
}