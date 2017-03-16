#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int __count(vector <vector <bool>> &matrix, vector <int> &d, vector <bool> &v, int vertex) {
	if (v[vertex]) {
		return d[vertex];
	}
	else {
		int sum = 0;
		for (int i = 0; i < matrix.size(); ++i) {
			if(matrix[i][vertex])
				sum += __count(matrix, d, v, i);
		}
		d[vertex] = sum;
		v[vertex] = true;
		return sum;
	}
}
int countWays(vector <vector <bool>> &matrix, int B) {
	vector <int> d(B);
	vector <bool> v(B);
	d[0] = 1;
	v[0] = true;
	return __count(matrix, d, v, B - 1);
}

bool __dfs(vector <vector <bool>> &matrix, vector <int> &color, int vertex) {
	color[vertex] = 1;
	for (int i = 0; i < matrix.size(); ++i) {
		if (matrix[vertex][i]) {
			if (color[i] == 1) {
				return false;
			}
			else if(color[i] == 0 && !__dfs(matrix, color, i)) {
				return false;
			}
		}
	}
	color[vertex] = 2;
	return true;
}

bool isAcyclic(vector <vector <bool>> &matrix, int B) {
	vector <int> color(B);
	for (int i = 0; i < B; ++i) {
		if (color[i] == 0) {
			if (!__dfs(matrix, color, i)) {
				return false;
			}
		}
	}
	return true;
}

bool isPossible(int B, int M, vector <vector <bool>> &matrix, int from, int to) {
	if (to == B) {
		from++;
		to = from + 1;
	}
	if (from == B - 1) {
		if (isAcyclic(matrix, B) && countWays(matrix, B) == M) {
			cout << "POSSIBLE\n";
			for (int y = 0; y < B; ++y) {
				for (int x = 0; x < B; ++x) {
					cout << matrix[y][x];
				}
				if(y != B - 1) 
					cout << endl;
			}
			return true;
		}
		return false;
	}
	else {
		for (int i = 0; i <= (from == B - 1 ? 0 : 1); ++i) {
			for (int j = 0; j <= (to == B - 1 ? 0 : 1); ++j) {
				if (i != 1 || j != 1) {
					matrix[from][to] = i;
					matrix[to][from] = j;
					if (isPossible(B, M, matrix, from, to + 1))
						return true;
				}
			}
		}
		return false;
	}
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T; cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << (t + 1) << ": ";
		/**/
		int B, M;
		cin >> B >> M;
		vector <vector <bool>> matrix(B, vector <bool>(B));
		if (!isPossible(B, M, matrix, 0, 1)) {
			cout << "IMPOSSIBLE";
		}
		/**/
		cout << endl;
	}
}