#include <iostream>
#include <vector>
#include <deque>


struct V
{
	std::vector<int> s;
	bool spr;

	V() : spr(false) { s.clear(); }
};


std::vector<V> M;
int T, N;

bool BFS (int x) {
	std::deque<int> queue;
	queue.push_back (x);
	while (!queue.empty()) {
		M[queue.front()].spr = true;
		for (int i = 0; i < M[queue.front()].s.size(); ++i) {
			if (!M[M[queue.front()].s[i]].spr) {
				queue.push_back (M[queue.front()].s[i]);
				M[M[queue.front()].s[i]].spr = true;
			} else {
				for (int i = 0; i < M.size(); ++i) {
					M[i].spr = false;
				}
				return true;
			}
		}
		queue.pop_front();
	}
	for (int i = 0; i < M.size(); ++i) {
		M[i].spr = false;
	}
	return false;
}

int main()
{
	std::cin >> T;
	for (int c = 1; c <= T; ++c) {
		std::cin >> N;
		M.clear();
		M.resize (N);
		for (int i = 0; i < N; ++i) {
			int n; std::cin >> n;
			for (int j = 0; j < n; ++j) {
				int c; std::cin >> c;
				M[i].s.push_back (--c);
			}
		}
		bool find = false;
		for (int i = 0; i < M.size(); ++i) {
			if (M[i].s.size() > 1) {
				if (BFS (i)) {
					std::cout << "Case #" << c << ": Yes\n";
					find = true; break;
				}
			}
		}
		if (!find) {
			std::cout << "Case #" << c << ": No\n";
		}
	}


	return 0;
}