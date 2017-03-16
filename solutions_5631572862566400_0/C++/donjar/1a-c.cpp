#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

double PI = acos(-1.0);
double EPS = 1e-9;
int INF = 2000000000;

#define FOR(i, a, b) for (int i = a; i < b; i++)

template <typename Type>
void print_array(Type arr, int start, int end) {
	cout << "[";
	FOR(i, start, end) {
		cout << arr[i] << ", ";
	}
	cout << "]" << endl;
}

template <typename Type>
void print_vector(vector<Type> v) {
	cout << "[";
	FOR(i, 0, v.size()) {
		cout << v[i] << ", ";
	}
	cout << "]" << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// END OF HEADER

	freopen("1a-c.in", "r", stdin);
	freopen("1a-c.res", "w", stdout);

	int testcases;
	cin >> testcases;

	for (int cse = 1; cse <= testcases; cse++) {
		int res = 0;
		// END OF CODE JAM HEADER

		int p;
		cin >> p;
		int mat[p][p] = {0};
		FOR (i, 0, p) {
			FOR (j, 0, p) {
				mat[i][j] = {0};
			}
		}
		vector<int> doubles;
		FOR (i, 0, p) {
			int bff;
			cin >> bff;
			mat[i][bff - 1]++;
			mat[bff - 1][i]++;

			if (mat[i][bff - 1] == 2) {
				doubles.push_back(i);
				doubles.push_back(bff - 1);
			}
		}

		bool kosong = false;
		if (doubles.empty()) {
			kosong = true;
		}

		int result[p]{0};

		FOR (i, 0, doubles.size()) {
			int v = doubles[i];
			int dist[p]{0};
			vector<int> bfs;
			bfs.push_back(v);
			int iter = 0;

			while (!bfs.empty()) {
				int ver = bfs[0];
				FOR (k, 0, p) {
					if (mat[ver][k] == 1) {
						if (dist[k] == 0 && k != v) {
							bfs.push_back(k);
							dist[k] = dist[ver] + 1;
						}
					}
				}

				bfs.erase(bfs.begin());
			}

			FOR (j, 0, p) {
				if (result[v] < dist[j]) {
					result[v] = dist[j];
				}
			}
			result[v]++;
		}

		int cycle = 0;
		if (kosong) {
			int dist[p]{0};
			FOR (i, 0, p) {
				if (cycle != 0) { break; }
				vector<int> bfs;
				bfs.push_back(i);

				while (!bfs.empty() && cycle == 0) {
					int v = bfs[bfs.size() - 1];

					bool located = false;
					FOR (j, 0, p) {
						if (mat[v][j] == 1) {
							if ((j == i && dist[v] != 1) || (dist[j] != 0 && dist[j] < dist[v] - 1)) {
								cycle = dist[v] - dist[j] + 1;
								located = true;
								break;
							} else if (dist[j] == 0 && j != i) {
								dist[j] = dist[v] + 1;
								bfs.push_back(j);
								located = true;
								break;
							}
						}
					}

					if (!located) {
						bfs.erase(bfs.end() - 1);
					}
				}
			}
		}

		FOR (i, 0, p) {
			if (!kosong) {
				res += result[i];
			} else {
				res = cycle;
			}
		}

		// START OF CODE JAM FOOTER
		cout << "Case #" << cse << ": " << res << endl;
	}
}
// END OF CODE JAM FOOTER
