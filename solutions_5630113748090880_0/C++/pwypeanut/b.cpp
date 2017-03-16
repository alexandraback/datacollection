#include <bits/stdc++.h>
using namespace std;

int TC, N;

bool cmp(vector<int> a, vector<int> b) {
	if (a[1] != b[1]) return a[1] < b[1];
	else return a < b;
}

int main() {
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++) {
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
		multiset< vector<int> > S;
		int grid[55][55];
		for (int bm = 0; bm < (1 << (2 * N - 1)); bm++) {
			S.clear();
			if (__builtin_popcount(bm) != N) continue;
			int cur = 0;
			for (int i = 0; i < 2 * N - 1; i++) {
				if (!(bm & (1 << i))) continue;
				for (int j = 0; j < N; j++) grid[cur][j] = V[i][j];
				cur++;
			}
			
			for (int i = 1; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (grid[i][j] <= grid[i - 1][j]) goto failed;
				}
			}
			for (int i = 0; i < N; i++) {
				for (int j = 1; j < N; j++) {
					if (grid[i][j] <= grid[i][j - 1]) goto failed;
				}
			}
			for (int j = 0; j < N; j++) {
				vector<int> tmp;
				for (int i = 0; i < N; i++) tmp.push_back(grid[i][j]);
				S.insert(tmp);
				//for (int i = 0; i < N; i++) printf("%d ", tmp[i]);
				//printf("\n");
			}
			for (int i = 0; i < 2 * N - 1; i++) {
				if (bm & (1 << i)) continue;
				multiset< vector<int> >::iterator it = S.find(V[i]);
				if (it == S.end()) goto failed;
				if ((*it) != V[i]) goto failed;
				S.erase(it);
			}
			printf("Case #%d: ", tc);
			for (int i = 0; i < N; i++) {
				if(i) printf(" ");
				printf("%d", (*S.begin())[i]);
			}
			printf("\n");
			break;
			failed:
			continue;
		}
		
		
	}
}
