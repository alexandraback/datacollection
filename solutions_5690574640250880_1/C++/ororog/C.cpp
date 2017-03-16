#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

#define REP(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long LL;

int nextInt() {
  char c;
  int res = 0;
  while (!isdigit(c = getchar())){};
  do {
    res = res * 10 + c - '0';
  } while (isdigit(c = getchar()));
  return res;
}

int R, C, M;

int dr[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dc[] = {-1, 1, 0, 0, 1, -1, 1, -1};

bool valid(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}

vector<string> result;
set<vector<string> > cache;

bool dfs(vector<string> state) {
	if (cache.count(state)) return false;
	REP(i, R) {
		//cout << state[i] << endl;
	}
	//cout << endl;
	int cnt = 0;
	REP(r, R) REP(c, C) {
		if (state[r][c] == '*') cnt++;
	}
	if (cnt == M) {
		result = state;
		return true;
	}
	cache.insert(state);
	REP(r, R) REP(c, C) {
		REP(i, 4) {
			int tr = r + dr[i], tc = c + dc[i];
			if (valid(tr, tc) && state[tr][tc] == '.') {
				vector<string> nstate = state;
				nstate[tr][tc] = '.';
				REP(j, 8) {
					int nr = tr + dr[j], nc = tc + dc[j];
					if (valid(nr, nc)) {
						nstate[nr][nc] = '.';
					}
				}
				bool res = dfs(nstate);
				if (res) return true;
				break;
			}
		}
	}
	return false;
}

void solve_small(int caseCnt) {
		cache.clear();
		cin >> R >> C >> M;
		vector<string> state;
		REP(i, R) state.push_back(string(C, '*'));
		state[R-1][C-1] = '.';
		printf("Case #%d:\n", caseCnt);
		if (dfs(state)) {
			result[R-1][C-1] = 'c';
			REP(i, R) {
				cout << result[i] << endl;
			}
		} else {
			printf("Impossible\n");
		}
}
/*
***....
.c.....
.......
.......
*/
bool memo[51][51][2501];
int lines[51];

void dfs(int column, int row, int space) {
	if (row < 0) return;
	if (memo[column][row][space]) return;

	memo[column][row][space] = true;

	if (space == 0) {
		throw 0;
	}
	for (int i = column; i >= 2; i--) {
		if (space - i < 0) continue;
		lines[row] = i;
		dfs(i, row - 1, space - i);
	}
}

void solve_large(int caseCnt) {
	cin >> R >> C >> M;
	int SP = R*C-M;
	bool ok = false;
	vector<string> result;
	REP(i, R) result.push_back(string(C, '*'));
	REP(i, R) lines[i] = 0;
	if (SP == 1) {
		lines[R] = 1;
		ok = true;
	} else if (R == 1) {
		lines[R] = SP;
		ok = true;
	} else if (C == 1) {
		REP(i, SP) {
			lines[R-i] = 1;
		}
		ok = true;
	} else {
		memset(memo, 0, sizeof(memo));
		try {
			for (int i = C; i >= 2; i--) {
				int space = SP - i * 2;
				lines[R-1] = lines[R] = i;
				if (space == 0) {
					ok = true;
					break;
				} else if (space > 0) {
					dfs(i, R - 2, space);
				}
			}
		} catch (int e) {
			ok = true;
		}
	}

	printf("Case #%d:\n", caseCnt);
	if (ok) {
		REP(i, R) {
			REP(j, lines[i+1]) {
				result[i][C-1-j] = '.';
			}
			//cout << lines[i+1] << ' ';cout << endl;
		}
		result[R-1][C-1] = 'c';
		REP(i, R) {
			cout << result[i] << endl;
		}
	} else {
		printf("Impossible\n");
	}
}


int main(){
	int TestCase = nextInt();

	for(int caseCnt=1; caseCnt <= TestCase; caseCnt++){
		//solve_small(caseCnt);
		solve_large(caseCnt);
	}
	return 0;
}
