#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <stdint.h>
#include <queue>
using namespace::std;

map<pair<int, int>, vector < vector<bool>>> table;

int cnt_way(vector < vector<bool>>& m)
{
	queue<int> queue;
	vector<int> cnt(m.size());
	queue.push(0);
	cnt[0] = 1;
	while (!queue.empty()) {
		int u = queue.front();
		queue.pop();
		//printf("u%d\n", u);
		for (int i = 0; i < m.size(); ++i) {
			if (m[u][i]) {
				cnt[i] += cnt[u];
				if (i != m.size() - 1) {
					queue.push(i);
				}
			}
		}
	}
	return cnt.back();
}

void dfs(int p, vector < vector<bool>>& m, vector<bool>& color, bool& flag)
{
	if (flag) {
		return;
	}
	if (p >= m.size()) {
		return;
	}
	for (int i = 0; i < m.size(); ++i) {
		if (m[p][i]) {
			if (color[i]) {
				flag = true;
				return;
			} else {
				color[i] = true;
				dfs(i, m, color, flag);
				color[i] = false;
			}
		}
	}
}


bool hasCycle(vector < vector<bool>>& m)
{
	vector<bool> visited(m.size(), false);

	visited[0] = true;
	bool flag = false;
	dfs(0, m, visited, flag);
	return flag;
}



void helper(int B)
{
	set<int> s;
	vector<int64_t> r;
	int total = (1 << ((B - 1)*(B - 1)));
	for (int i = 0; i < total; ++i) {
		if (B == 6 && (i % (total / 100) == 0)) {
			printf("percent %lf\n", (double)i / total);
		}
		vector<vector<bool>> m(B, vector<bool>(B, 0));
		for (int j = 0; j < (B - 1) *(B - 1); ++j) {
			if (i & (1 << j)) {
				int c = j % (B - 1);
				int r = j / (B - 1);
				m[r][c+1] = 1;
			}
		}
		bool flag = true;
		for (int j = 0; j < B; ++j) {
			if (m[j][j]){
				flag = false;
				break;
			}
		}

		//printf("i%d\n", i);
		if (hasCycle(m)) {
			continue;
		}
		//for (auto xx : m) {
		//	for (auto x : xx) {
		//		printf("%d", x);
		//	}
		//	printf("\n");
		//}
		//printf("?\n");
		int w = cnt_way(m);
		if (w != 0) {
			auto p = make_pair(B, w);
			table[p] = m;
			//printf("w%d\n", w);
			s.insert(w);

		}
	}

	cout << "B " << B << ":";
	for (auto t : s) {
		cout << t << " ";
	}
	cout << "\n";

}

int main() 
{
	helper(2);
	helper(3);
	helper(4);
	helper(5);
	helper(6);


	system("pause");
	//return 0;
	FILE* file_in = fopen("b.in","r");
	FILE* file_out = fopen("b.out","w");
	int n_case;
	fscanf(file_in,"%d",&n_case);
	for (int i_case = 0; i_case < n_case; ++i_case) {
		printf("i%d\n", i_case);
		int B, M;
		fscanf(file_in,"%d%d", &B, &M);
		
		
		fprintf(file_out,"Case #%d:", i_case + 1);
		auto t = table.find(make_pair(B, M));
		if (t == table.end()) {
			fprintf(file_out, " IMPOSSIBLE\n");
		}
		else {
			fprintf(file_out, " POSSIBLE\n");
			auto m = t->second;
			for (int i = 0; i < m.size(); ++i) {
				for (int j = 0; j < m.size(); ++j) {
					if (m[i][j]) {
						fprintf(file_out, "1");
					} else {
						fprintf(file_out, "0");
					}
				}
				fprintf(file_out, "\n");
			}
		}
	
	}


	
	fclose(file_out);
	fclose(file_in);

	system("pause");
	return 0;
}