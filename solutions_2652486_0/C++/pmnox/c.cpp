#define ll long long
#include <iostream>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;

int R, N, M, K;

int prod[111];

void solve() {
	scanf("%d%d%d%d", &R, &N, &M, &K);
	for (int ii = 0; ii < R; ii++) {
		for (int j = 0; j < K; j++) {
			scanf("%d", &prod[j]);
		}
		for (int i = 0; ; i++) {
			set<int> Q;
			vector<int> q;
			int tmp = i;
			for (int j = 0; j < N; j++) { q.push_back(2 + (tmp % (M - 1))); tmp /= M - 1; }

			for (int j = 0; j < (1<<N); j++)  {
				int il = 1;
				for (int k = 0; k < N; k++) if (j&(1<<k)) il *= q[k];
				Q.insert(il);
			}


			if (tmp > 0) break;
			bool ok = true;
			for (int j = 0; j < K; j++) if (Q.count(prod[j]) == 0) ok = false;


			if (ok) {
				for (int j = 0; j < N ; j++) printf("%d", q[j]);
				break;
			}
		}
		printf("\n");
	}
}


int main(int argc, char ** argv) {
	int T; 
	scanf("%d", &T);;
	for (int i = 1; i <= T; i++) { printf("Case #%d:\n", i);	
		solve();}
	return 0;
}
