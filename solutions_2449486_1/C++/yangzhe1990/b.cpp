#include <cstdio>
#include <string>
#include <algorithm>

const int max_h = 100;
const int any_h = 101;

template <class X>
struct auto_array_ptr {
	X* _p;

	auto_array_ptr(X* p): _p(p) {}
	X *get() { return _p; }
	~auto_array_ptr() { delete[] _p; }
};

inline void read_data(int n, int m, int *board) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			scanf("%d", &(board[i * m + j]));
		scanf("\n");
	}
}

inline bool try_remove_line(int height,
			    int start, int delta, int step, int *board) {
	int pos = start;
	for (int i = 0; i < step; ++i, pos += delta) {
		if (board[pos] != height && board[pos] != any_h)
			return false;
	}
	pos = start;
	for (int i = 0; i < step; ++i, pos += delta)
		board[pos] = any_h;
	return true;
}

inline bool try_remove(int pos, int h, int n, int m, int *board) {
	return (try_remove_line(h, pos - pos % m, 1, m, board)
		|| try_remove_line(h, pos % m, m, n, board));
}

struct int_arr_idx_sorter {
	int *a;
	int_arr_idx_sorter(int *arr) : a(arr) {}

	bool operator() (int i, int j) {
		return a[i] < a[j];
	}
};

std::string get_result(int n, int m, int *board) {
	int size = n * m;

	int *sorted_grid = new int[size];
	auto_array_ptr<int> sorted_grid_mem(sorted_grid);
	// auto release mem upon returning

	for (int i = 0; i < size; ++i)
		sorted_grid[i] = i;
	std::sort(sorted_grid, sorted_grid + size, int_arr_idx_sorter(board));

	for (int i = 0; i < size; ++i) {
		int pos = sorted_grid[i];
		int h = board[pos];
		if (h == any_h)
			continue;
		if (!try_remove(pos, h, n, m, board))
			return "NO";
	}

	return "YES";
}

int main() {
	int t;
	scanf("%d\n", &t);
	for (int i = 1; i <= t; ++i) {
		int n, m;
		scanf("%d%d\n", &n, &m);
		auto_array_ptr<int> board(new int[n * m]);
		read_data(n, m, board.get());
		printf("Case #%d: %s\n", i, get_result(n, m, board.get()).c_str());
	}
}
