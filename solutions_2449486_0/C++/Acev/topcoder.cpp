#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;



int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		vector<vector<int> > board;
		int N, M;
		cin >> N >> M;
		board.resize(N);
		for (int i = 0; i < N; ++i) {
			board[i].resize(M);
			for (int j = 0; j < M; ++j) {
				scanf("%d", &board[i][j]);
			}
		}

		bool result = true;
		for (int i = 0; i < N && result; ++i) {
			for (int j = 0; j < M && result; ++j) {
				bool okR = true, okC = true;
				for (int k = 0; k < N; ++k) {
					if (board[k][j] > board[i][j]) {
						okR = false;
						break;
					}
				}

				for (int k = 0; k < M; ++k) {
					if (board[i][k] > board[i][j]) {
						okC = false;
						break;
					}
				}

				if (!okR && !okC) {
					result = false;
				}
			}
		}

		string res = (result) ? "YES" : "NO";
		cout << "Case #" << t << ": " << res << endl;
	}

	return 0;
}
