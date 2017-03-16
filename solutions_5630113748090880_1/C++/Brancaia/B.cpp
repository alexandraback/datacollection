#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vvi lists;
vi ini;

int N;

vi solve(vvi& grid, vector<bool>& taken) {
	int K = 2*N-1;
	int r = (int) grid.size();

	if (r == N) {
		vi row, col, c;
		row.assign(2505, 0);
		col.assign(2505, 0);
		c.assign(2505, 0);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				c[grid[i][j]]++;

				cout << grid[i][j] << " ";
			}
			cout << endl;
		}

		vi res = vi();
		for (int h = 1; h <= 2500; h++) {
			if (ini[h] != 2*c[h]) {
				//cout << h << " ini = " << ini[h] << " c = " << c[h] << endl;
				res.push_back(h);
				if (res.size() == N) break;
			}
		}

		sort(res.begin(), res.end());
		return res;
	} 

	vi last = grid[r-1];
	for (int i = 0; i < K; i++) {
		if (!taken[i]) {
			bool check = true;

			for (int j = 0; j < N && check; j++) {
				check &= (lists[i][j] > last[j]);
			}

			if (check) {
				taken[i] = true;
				//cout << "chose list nbr " << i << endl;
				grid.push_back(lists[i]);
				vi tmp = solve(grid, taken);

				if (tmp.size() > 0) return tmp;

				taken[i] = false;
				grid.pop_back();
			}
		}
	}

	return vi();
}

int main() {
	ifstream in ("in.txt");
	ofstream out ("out.txt");

	int T; in >> T;

	for (int i = 1; i <= T; i++) {
		in >> N;
		int smallest = 3000;
		lists = vvi();
		ini.assign(3000,0);

		for (int j = 0; j < 2*N-1; j++) {
			vi l = vi();
			//cout << "j = " << j << endl;
			for (int u = 0; u < N; u++) {
				int v; in >> v;
				smallest = min(smallest, v);
				ini[v]++;
				//printf("ini[%d] = %d\n", v, ini[v]);
				l.push_back(v);
			}
			lists.push_back(l);
		}

		//cout << "smallest = " << smallest << endl;
		vvi grid = vvi();
		vector<bool> taken;
		taken.assign(N*N, false);

		vi res = vi();
		for (int h = 1; h <= 2500; h++) {
			if (ini[h] % 2 != 0) {
				res.push_back(h);
			}
		}

		out << "Case #" << i << ": ";
				for (int r = 0; r < N-1; r++) {
					out << res[r] << " ";
				}
				out << res[N-1] << endl;


		/*
		bool done = false;
		for (int j = 0; j < 2*N-1; j++) {
			if (lists[j][0] == smallest) {
				grid.push_back(lists[j]);
				taken[j] = true;
				cout << "start with list nbr " << j << endl;
				vi res = solve(grid, taken);

				if (res.size() == 0) continue;

				if (res.size() != N) {
					cout << res.size() << " " << N << endl;
				}
				assert(res.size() == N);

				out << "Case #" << i << ": ";
				for (int r = 0; r < N-1; r++) {
					out << res[r] << " ";
				}
				out << res[N-1] << endl;

				break;
			}
		}*/
	}

	return 0;
} 