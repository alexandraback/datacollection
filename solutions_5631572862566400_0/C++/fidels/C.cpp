#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAXN 1024

int next[MAXN], state[MAXN], size[MAXN], depth[MAXN];
vector<int> in[MAXN];

int dfs(int cur, int d) {
	depth[cur] = d;
	
	state[cur] = 1;
	if (state[next[cur]] == 0) size[cur] = dfs(next[cur], d+1);
	else if (state[next[cur]] == 1) size[cur] = d-depth[next[cur]]+1;
	else size[cur] = size[next[cur]];
	state[cur] = 2;
	
	return size[cur];
}

int dfs2(int cur) {
	int RES = 0;
	for (int i=0; i<(int)in[cur].size(); i++) {
		int tmp = in[cur][i];
		if (tmp != next[cur]) RES = max(RES, dfs2(tmp));
	}
	return RES+1;
}

int main() {
	int T, t, N, i, RES1, RES2;
	
	cin >> T;
	for (t=1; t<=T; t++) {
		cin >> N;
		for (i=1; i<=N; i++) in[i].clear();

		for (i=1; i<=N; i++) {
			cin >> next[i];
			in[next[i]].push_back(i);
		}
		
		memset(state, 0, sizeof(state)); RES1 = 0;
		for (i=1; i<=N; i++) if (!state[i]) RES1 = max(RES1, dfs(i, 0));
		
		memset(state, 0, sizeof(state)); RES2 = 0;
		for (i=1; i<=N; i++) if (next[next[i]] == i) RES2 += dfs2(i);
		
		cout << "Case #" << t << ": " << max(RES1, RES2) << endl;
	}

	return 0;
}
