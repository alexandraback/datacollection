#include <cstdio>

// r is smaller
int has_solution(int x, int r, int c)
{
	if (r > c) return has_solution(x, c, r);

	if (r * c < x) return 0;
	if (((r * c) % x) != 0) return 0;
	if (r < x && c < x) return 0;
	
	if (x >= 7) return 0; // use a hole

	if (x == 1) return 1;
	if (x == 2) return 1;
	
	if (r == 1) return 0; // for x >= 3

	if (x == 4) {
		if (r == 2) return 0; // choose a "T"
	}

	if (x == 5) {
		if (r == 2) return 0; // ledder
		if (r == 3 && c == 5) return 0;
	}

	if (x == 6) {
		if (r == 2) return 0; // ledder
		if (r == 3 && c == 4) return 0;
		
	}

	return 1;
}

int main()
{
	int t_max;
	scanf("%d", &t_max);
	for (int t = 1; t <= t_max; t++) {
		int x, r, c;
		scanf("%d %d %d", &x, &r, &c);
		printf("Case #%d: %s\n", t, has_solution(x, r, c) ? "GABRIEL" : "RICHARD");
	}
}