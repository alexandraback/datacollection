#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sz(v) (int)v.size()
#define all(c) (c).begin(), (c).end()

typedef long long int ll;

// %I64d for ll in CF

int r, c, m;
bool found;
int solution;
int click;

bool valid(int i, int j) {
	return i >= 0 && i < r && j >= 0 && j < c;
}

int get_click(int bitmask) {
	char board[r][c];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			board[i][j] = bitmask & (1 << (i * c + j)) ? '*' : '.';
		}
	}

	int count[r][c];
	memset(count, 0, sizeof count);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
			int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
			int neighbours = 0;
			for (int k = 0; k < 8; k++) {
				int i1 = i + dy[k];
				int j1 = j + dx[k];
				if (valid(i1, j1) && board[i1][j1] == '*') neighbours++;
			}

			count[i][j] = neighbours;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == '*') continue;

			int idx0 = i * c + j;
			bool visited[r * c + 1];
			memset(visited, false, sizeof visited);
			visited[idx0] = true;

			queue<int> q;
			q.push(idx0);
			while (!q.empty()) {
				int u = q.front();
				q.pop();

				int i0 = u / c;
				int j0 = u % c;
				if (count[i0][j0] == 0) {
					int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
					int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
					for (int k = 0; k < 8; k++) {
						int i1 = i0 + dy[k];
						int j1 = j0 + dx[k];
						if (valid(i1, j1) && !visited[i1 * c + j1] && board[i1][j1] == '.') {
							visited[i1 * c + j1] = true;
							q.push(i1 * c + j1);
						}
					}
				}
			}

			bool possible = true;
			for (int i1 = 0; i1 < r * c && possible; i1++) {
				possible = board[i1 / c][i1 % c] == '*' || (board[i1 / c][i1 % c] == '.' && visited[i1]);
			}

			if (possible) return i * c + j;
		}
	}

	return -1;
}

void solve(int i, int remaining, int bitmask) {
	if (found) return;

	if (remaining == 0) {
		int click0 = get_click(bitmask);
		if (click0 != -1) {
			found = true;
			solution = bitmask;
			click = click0;
		}
		return;
	}
	if (i == r * c) return;

	solve(i + 1, remaining, bitmask);
	solve(i + 1, remaining - 1, bitmask | (1 << i));
}

int main() {
	int t;
	scanf("%d", &t);
	int q = 1;
	while (t--) {
		scanf("%d %d %d", &r, &c, &m);
		found = false;
		solve(0, m, 0);
		printf("Case #%d:\n", q);
		if (!found) printf("Impossible\n");
		else {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					int idx = i * c + j;
					if (idx == click) printf("c");
					else if (solution & (1 << idx)) printf("*");
					else printf(".");
				}

				printf("\n");
			}
		}
		q++;
	}
	return 0;
}
