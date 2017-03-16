#include <bits/stdc++.h>
using namespace std;

int TC, N;
set<int> S;

int main() {
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
		S.clear();
		scanf("%d", &N);
		vector< vector<int> > V;
		for (int i = 0; i < 2 * N - 1; i++) {
			vector<int> tmp;
			for (int j = 0; j < N; j++) {
				int x;
				scanf("%d", &x);
				tmp.push_back(x);
			}
			V.push_back(tmp);
		}
		sort(V.begin(), V.end());
		for (int i = 0; i < V.size(); i++) {
			for (int j = 0; j < N; j++) {
				if (S.find(V[i][j]) != S.end()) S.erase(V[i][j]);
				else S.insert(V[i][j]);
			}
		}
		printf("Case #%d:", tc);
		for (set<int>::iterator it = S.begin(); it != S.end(); it++) printf(" %d", *it);
		printf("\n");
		
		
	}
}
