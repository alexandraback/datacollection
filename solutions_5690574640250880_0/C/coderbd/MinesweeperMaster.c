#include <stdio.h>

char grid[64][64];

int try_fill_row(int r, int c, int n) {
	int i, j, cnt = 0;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			grid[i][j] = '*';

	for (j = 0; j < c; j++)
		for (i = 0; i < r; i++) {
			if (cnt < n) {
				grid[i][j] = '.';
				cnt++;
			}
			if (cnt == n) {
				if (i == 0) {
					if (j > 2) {
						grid[1][j] = '.';
						grid[r-1][j-1] = '*';
						grid[0][0] = 'c';
						return 1;
					}
					else if (j == 2) {
						grid[1][j] = '.';
						grid[2][j] = '.';
						grid[r-1][0] = '*';
						grid[r-1][1] = '*';
						grid[0][0] = 'c';
						return 1;
					}
				}
				else {
					grid[0][0] = 'c';
					return 1;
				}
			}
		}
	
	return 0;
}

int try_fill_column(int r, int c, int n) {
	int i, j, cnt = 0;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			grid[i][j] = '*';

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++) {
			if (cnt < n) {
				grid[i][j] = '.';
				cnt++;
			}
			if (cnt == n) {
				if (j == 0) {
					if (i > 2) {
						grid[i][1] = '.';
						grid[i-1][c-1] = '*';
						grid[0][0] = 'c';
						return 1;
					}
					else if (i == 2) {
						grid[i][1] = '.';
						grid[i][2] = '.';
						grid[0][c-1] = '*';
						grid[1][c-1] = '*';
						grid[0][0] = 'c';
						return 1;
					}
				}
				else {
					grid[0][0] = 'c';
					return 1;
				}
			}
		}
	
	return 0;
}

int solve(int r, int c, int m) {
	int i, j, n, half_n, half_m, cnt;

	n = r * c - m;

	if (m == 0) {
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				grid[i][j] = '.';
		grid[0][0] = 'c';
		return 1;
	}

	if (m + 1 == r * c) {
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				grid[i][j] = '*';
		grid[0][0] = 'c';
		return 1;
	}

	if (r == 1) {
		for (j = 0; j < m; j++)
			grid[0][j] = '*';
		for (j = m; j < c; j++)
			grid[0][j] = '.';
		grid[0][c-1] = 'c';
		return 1;
	}

	if (c == 1) {
		for (i = 0; i < m; i++)
			grid[i][0] = '*';
		for (i = m; i < r; i++)
			grid[i][0] = '.';
		grid[r-1][0] = 'c';
		return 1;
	}

	if (r == 2) {
		if ((m & 1) || (r * c - m == 2))
			return 0;
		half_m = m >> 1;
		for (j = 0; j < half_m; j++)
			grid[0][j] = grid[1][j] = '*';
		for (j = half_m; j < c; j++)
			grid[0][j] = grid[1][j] = '.';
		grid[1][c-1] = 'c';
		return 1;
	}
	
	if (c == 2) {
		if ((m & 1) || (r * c - m == 2))
			return 0;
		half_m = m >> 1;
		for (i = 0; i < half_m; i++)
			grid[i][0] = grid[i][1] = '*';
		for (i = half_m; i < r; i++)
			grid[i][0] = grid[i][1] = '.';
		grid[r-1][1] = 'c';
		return 1;
	}

	if (n < 4 || n == 5 || n == 7)
		return 0;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			grid[i][j] = '*';

	cnt = 0;
	if (n == 9) {
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				grid[i][j] = '.';
		grid[0][0] = 'c';
		return 1;
	}
	else if (n & 1) {
		return try_fill_row(r, c, n) || try_fill_column(r, c, n);
	}
	else {
		half_n = n >> 1;
		if (r > c) {
			if (half_n <= r) {
				for (i = 0; i < half_n; i++)
					grid[i][0] = grid[i][1] = '.';
				grid[0][0] = 'c';
				return 1;
			}
			else
				return try_fill_row(r, c, n) || try_fill_column(r, c, n);
		}
		else {
			if (half_n <= c) {
				for (j = 0; j < half_n; j++)
					grid[0][j] = grid[1][j] = '.';
				grid[0][0] = 'c';
				return 1;
			}
			else
				return try_fill_row(r, c, n) || try_fill_column(r, c, n);
		}
	}

	return 0;
}

void output(int r, int c) {
	int i, j;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++)
			putchar(grid[i][j]);
		putchar('\n');
	}
}

int main(int argc, char* argv[]) {
	int case_no, t, r, c, m;

	scanf("%d", &t);
	for (case_no = 1; case_no <= t; case_no++) {
		scanf("%d%d%d", &r, &c, &m);
		printf("Case #%d:\n", case_no);

		if (solve(r, c, m))
			output(r, c);
		else
			puts("Impossible");
	}

	return 0;
}