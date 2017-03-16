#include <iostream>
#include <vector>

void print_solution(int r, int c, int m) {
	bool good = false;
	std::vector<std::string> map(r, std::string(c, '.'));
	map[r - 1][c - 1] = 'c';
	if (m == r * c - 1) {
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				map[i][j] = '*';
		map[r - 1][c - 1] = 'c';
		good = true;
	}
	else if (r == 1) {
		for (int i = 0; i < m; ++i)
			map[0][i] = '*';
		good = true;
	}
	else if (c == 1) {
		for (int i = 0; i < m; ++i)
			map[i][0] = '*';
		good = true;
	}
	else {
		for (int x = 0; x < r - 1; ++x) {
			for (int y = 0; y < c - 1; ++y) {
				int min = x * c + y * r - x * y;
				int max = (r - 2) * (c - 2) + 2 * (x + y);
				if (m >= min && m <= max) {
					good = true;
					for (int i = 0; i < x; ++i)
						for (int j = 0; j < c; ++j)
							map[i][j] = '*';
					for (int j = 0; j < y; ++j)
						for (int i = 0; i < r; ++i)
							map[i][j] = '*';
					{
						int left = m - min;
						int c_left = y, c_right = c - 2;
						int i = x; int j = c_left;
						while (left > 0) {
							map[i][j] = '*';
							if (++j == c_right) {
								++i;
								j = c_left;
							}
							--left;
						}
					}
					break;
				}
			}
			if (good)
				break;
		}
	}

	if (good) {
		for (int i = 0; i < r; ++i)
			std::cout << map[i] << '\n';
	}
	else
		std::cout << "Impossible\n";
}

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int r, c, m;
		std::cin >> r >> c >> m;
		std::cout << "Case #" << i + 1 << ":\n";
		print_solution(r, c, m);
	}
	return 0;
}
