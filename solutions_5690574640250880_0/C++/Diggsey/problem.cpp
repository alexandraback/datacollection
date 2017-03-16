#include "stdafx.h"

int grid[50][50];

void clear(int r, int c) {
	for (int y = 0; y < r; ++y)
	for (int x = 0; x < c; ++x)
		grid[y][x] = 0;
}

bool check(int r, int c) {
	for (int y = 0; y < r; ++y)
	for (int x = 0; x < c; ++x) {
		if (grid[y][x] == -1)
			continue;

		int total = 0;
		if ((x > 0) && (grid[y][x - 1] == -1)) ++total;
		if ((x < (c-1)) && (grid[y][x + 1] == -1)) ++total;
		if ((y > 0) && (grid[y - 1][x] == -1)) ++total;
		if ((y < (r - 1)) && (grid[y + 1][x] == -1)) ++total;
		if ((x > 0) && (y > 0) && (grid[y - 1][x - 1] == -1)) ++total;
		if ((x > 0) && (y < (r - 1)) && (grid[y + 1][x - 1] == -1)) ++total;
		if ((x < (c - 1)) && (y > 0) && (grid[y - 1][x + 1] == -1)) ++total;
		if ((x < (c - 1)) && (y < (r - 1)) && (grid[y + 1][x + 1] == -1)) ++total;

		grid[y][x] = total;
	}

	for (int y = 0; y < r; ++y)
	for (int x = 0; x < c; ++x) {
		if (grid[y][x] == -1 || grid[y][x] == 0)
			continue;

		bool valid = false;
		if ((x > 0) && (grid[y][x - 1] == 0)) valid = true;
		if ((x < (c - 1)) && (grid[y][x + 1] == 0)) valid = true;
		if ((y > 0) && (grid[y - 1][x] == 0)) valid = true;
		if ((y < (r - 1)) && (grid[y + 1][x] == 0)) valid = true;
		if ((x > 0) && (y > 0) && (grid[y - 1][x - 1] == 0)) valid = true;
		if ((x > 0) && (y < (r - 1)) && (grid[y + 1][x - 1] == 0)) valid = true;
		if ((x < (c - 1)) && (y > 0) && (grid[y - 1][x + 1] == 0)) valid = true;
		if ((x < (c - 1)) && (y < (r - 1)) && (grid[y + 1][x + 1] == 0)) valid = true;

		if (!valid)
			return false;
	}

	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input("problem.in");
	ofstream output("problem.out");

	int t;
	input >> t;

	for (int i = 1; i <= t; ++i) {
		int r, c, m, om;
		input >> r >> c >> om;
		bool succeeded = false;

		if (r*c - om == 1) {
			for (int y = 0; y < r; ++y)
			for (int x = 0; x < c; ++x)
				grid[y][x] = -1;
			succeeded = true;
			goto done;
		}

		clear(r, c);
		m = om;

		for (int y = 0; y < r-2; ++y)
		for (int x = 0; x < c; ++x) {
			if (m) {
				if (!--m && (x == c - 2) && y < (r - 1)) {
					grid[y+1][0] = -1;
					if ((y == r - 3) && (x > 0)) {
						swap(grid[y + 2][0], grid[y][x - 1]);
					}
				} else {
					grid[y][x] = -1;
				}
			}
		}
		for (int x = 0; x < c - 2; ++x)
		for (int y = max(r-2, 0); y < r; ++y) {
			if (m) {
				if (!--m && (y == r - 2) && x < (c - 1) && (r > 2) && (c > 2)) {
					grid[y][x] = -1;
					swap(grid[r - 3][c - 1], grid[y + 1][x]);
					swap(grid[r - 3][c - 2], grid[y][x + 1]);
					swap(grid[r - 3][c - 3], grid[y + 1][x + 1]);
				} else {
					grid[y][x] = -1;
				}
			}
		}

		if (!m && check(r, c)) {
			succeeded = true;
			goto done;
		}

		clear(r, c);
		m = om;

		for (int x = 0; x < c-2; ++x)
		for (int y = 0; y < r; ++y) {
			if (m) {
				if (!--m && (y == r - 2) && x < (c - 1)) {
					grid[0][x + 1] = -1;
					if ((x == c - 3) && (y > 0)) {
						swap(grid[0][x + 2], grid[y - 1][x]);
					}
				} else {
					grid[y][x] = -1;
				}
			}
		}
		for (int y = 0; y < r - 2; ++y)
		for (int x = max(c - 2, 0); x < c; ++x) {
			if (m) {
				if (!--m && (x == c - 2) && y < (r - 1) && (r > 2) && (c > 2)) {
					grid[y][x] = -1;
					swap(grid[r - 1][c - 3], grid[y][x + 1]);
					swap(grid[r - 2][c - 3], grid[y + 1][x]);
					swap(grid[r - 3][c - 3], grid[y + 1][x + 1]);
				} else {
					grid[y][x] = -1;
				}
			}
		}

		if (!m && check(r, c)) {
			succeeded = true;
			goto done;
		}

	done:

		grid[r - 1][c - 1] = -2;

		output << "Case #" << i << ":" << endl;
		if (succeeded) {
			for (int y = 0; y < r; ++y) {
				for (int x = 0; x < c; ++x) {
					if (grid[y][x] == -1)
						output << '*';
					else if (grid[y][x] == -2)
						output << 'c';
					else
						output << '.';
				}
				output << endl;
			}
		} else {
			output << "Impossible" << endl;
		}
	}


	return 0;
}

