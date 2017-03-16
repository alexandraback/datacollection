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


int main(){
	int TestCase = nextInt();

	for(int caseCnt=1; caseCnt <= TestCase; caseCnt++){
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
	return 0;
}
