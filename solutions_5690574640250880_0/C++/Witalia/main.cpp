#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
#include <limits.h>
#include <cassert>
#include <chrono>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <valarray>

using namespace std;
using namespace std::chrono;

typedef long long ll;

const int N = 16005;
const int K = 605;
const ll InfL = 1000000000000000000LL;
const int MOD = 1000000007;

void fill(vector<vector<char>> &grid, int rs, int cs, int r, int c, int &m) {
	for (int i = rs; i < r; ++i) {
		for (int j = cs; j < c; ++j) {
			if (m > 0) {
				m--;
				grid[i][j] = '*';
			}
		}
	}
}

//#define ONLINE_JUDGE
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ":\n";

		int r, c, m;
		cin >> r >> c >> m;
		int n = r * c - m;
		//cout << r << " " << c << " " << m << " " << n << endl;
		bool swapped = false;
		if (r < c) {
			swap(r, c);
			swapped = true;
		}
		vector<vector<char>> grid(r, vector<char>(c, '.'));
		if ((n == 7 || n == 5 || n == 3 || n == 2) && c != 1) {
			cout << "Impossible\n";
			continue;
		}
		if (n >= c * 2 || n == 1 || c == 1) {
			fill(grid, 0, 0, r, c, m);
			if (n % c == 1 && n != 1 && c != 1) {
				int x, y;
				for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) if (grid[i][j] == '*') x = i, y = j;
				if (y > 0) {
					grid[x][y] = '.';
					grid[x + 1][0] = '*';
					if (x + 2 == r - 1) {
						if (y > 1) {
							grid[x][y - 1] = '.';
							grid[x + 2][0] = '*';
						}
						else {
							cout << "Impossible\n";
							continue;
						}
					}
				}
				else {
					cout << "Impossible\n";
					continue;
				}
				//cout << "----------------------------------------------------------------\n";
			}
			grid[r - 1][c - 1] = 'c';
		}
		else {
			if (n % 2 == 0) {
				fill(grid, 0, 0, r - 2, c, m);
				fill(grid, r - 2, 0, r, m / 2, m);
				grid[r - 1][c - 1] = 'c';
			}
			else {
				if (c < 3) {
					cout << "Impossible\n";
					continue;
				}
				fill(grid, 0, 0, r - 3, c, m);
				fill(grid, r - 3, 0, r - 2, c - 3, m);
				fill(grid, r - 2, 0, r, m / 2, m);
				grid[r - 1][c - 1] = 'c';
			}
		}
		for (int i = 0; i < (swapped ? c : r); ++i) {
			for (int j = 0; j < (swapped ? r : c); ++j) {
				cout << (!swapped ? grid[i][j] : grid[j][i]);
			}
			cout << endl;
		}
	}
	/*ifstream fin("input.txt");
	ifstream fout("output.txt");
	int T;
	fin >> T;
	for (int t = 0; t < T; ++t) {
		int r, c, m;
		fin >> r >> c >> m;
		int n = r * c - m;
		string s;
		getline(fout, s);
	}*/
	return 0;
}