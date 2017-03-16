#include <fstream>
#include <string.h>
using namespace std;

int T, n,ans;
char st[10][101];
int visit[10], order[10], chuxian[26];

int cal() {
	for (int i=0; i<26; i++) chuxian[i] = 0;
	char pre = st[order[0]][0];
	chuxian[pre-'a'] = 1;
	int now = 0;
	for (int i=0; i<n; i++) {
		int len = strlen(st[order[i]]);
		for (int j=0; j<len; j++) {
			if (st[order[i]][j] != pre && chuxian[st[order[i]][j]-'a']) return 0;
			if (st[order[i]][j] != pre) {
				chuxian[st[order[i]][j]-'a'] = 1;
				pre = st[order[i]][j];
			}
		}
	}
	ans++;
	return 1;
}

void dfs(int dep) {
	if (dep == n) {
		cal();
		return;
	}
	for (int i=0; i<n; i++)
		if (!visit[i]) {
			visit[i] = 1;
			order[dep] = i;
			dfs(dep+1) ;
			visit[i] = 0;
		}
}

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> T;

	for (int test = 1; test <= T; ++test)
	{
		fin >> n;
		for (int i = 0; i < n; ++i)
			fin >> st[i];
		for (int i=0; i<n; i++) visit[i] = 0;
		ans = 0;
		dfs(0);
		fout << "Case #" << test << ": " << ans << endl;
	}
	fin.close();
	fout.close();
}
