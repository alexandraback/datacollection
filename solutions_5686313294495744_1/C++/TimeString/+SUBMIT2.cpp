#include <stdio.h>
#include <string>
#include <map>

using namespace std;

const int A = 1;
const int B = 1001;

int num;
int flow[2002][2002];
int capa[2002][2002];
int visited[2002];
int visited_id;

bool dfs(int n) {
	if (n == 2001)
		return true;

	//printf("dfs:%d\n", n);
	if (visited[n] == visited_id)
		return false;
	visited[n] = visited_id;

	for (int i = 0; i < 2002; i++)
		if (flow[n][i] < capa[n][i]) {
			//printf("  exp:%d %d\n", n, i);
			if (dfs(i)) {
				flow[n][i]++;
				flow[i][n]--;
				return true;
			}
		}
	return false;
}

int solve_flow() {
	int ans = 0;
	
	//printf("===\n");
	visited_id++;
	while (dfs(0)) {
		ans++;
		visited_id++;
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int ecase, ecount;
	int caseStart = -1, caseEnd = 9999999;
	scanf("%d", &ecase);

	if (argc > 1) {
		if (sscanf(argv[1], "%d", &caseStart) == 1) {
			if (argc > 2)
				sscanf(argv[2], "%d", &caseEnd);
		}
		if (caseEnd < caseStart)
			caseEnd = caseStart;
		if (caseEnd != 9999999 && caseEnd >= 1 && caseStart <= 0)
			caseStart = 1;
		if (caseStart > 0)
			fprintf(stderr, "....................DEBUG MODE ENABLED (FROM CASE %d to %d)\n", caseStart, caseEnd);
	}

	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		scanf("%d", &num);
		map<string, int> am, bm;
		int a_num = 0;
		int b_num = 0;
		int ano[1000], bno[1000];
		
		for (int i = 0; i < num; i++) {
			char ta[1000], tb[1000];
			scanf("%s%s", ta, tb);
			string s = string(ta);
			if (am.find(s) == am.end())
				am[s] = a_num++;
			ano[i] = am[s];
			if (bm.find(s) == bm.end())
				bm[s] = b_num++;
			bno[i] = bm[s];
		}
		
		for (int i = 0; i < 2002; i++)
			for (int j = 0; j < 2002; j++)
				flow[i][j] = capa[i][j] = 0;
		for (int i = 0; i < a_num; i++)
			capa[0][A + i] = 1;
		for (int i = 0; i < b_num; i++)
			capa[B + i][2001] = 1;
		for (int i = 0; i < num; i++)
			capa[A + ano[i]][B + bno[i]] = 1;

		int mflow = solve_flow();
		int needed = a_num + b_num - mflow;
		int ans = num - needed;

		//printf("mflow:%d a_num:%d b_num:%d\n", mflow, a_num, b_num);
		printf("Case #%d: %d\n", ecount, ans);
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
