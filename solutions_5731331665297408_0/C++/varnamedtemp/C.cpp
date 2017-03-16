#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cmath>
#include <queue>
#include <assert.h>
#include <cstdlib>

using namespace std;

typedef long long ll;

int N, M, G[55][55], G2[55][55], used[55];
string zip[55];

int main() {
	freopen("C-small-attempt0.in.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d",&T);
	for(int t = 1;t<=T;t++) {
		scanf("%d %d",&N,&M);
		for(int i = 1;i<=N;i++)
			cin>>zip[i];
		for(int i = 1;i<=N;i++)
			for(int j = 1;j<=N;j++)
				G[i][j] = G2[i][j] = 0;
		for(int i = 0;i<M;i++) {
			int u, v;
			scanf("%d %d",&u,&v);
			G[u][v] = G[v][u] = 1;
		}
		fill(used, used + 1 + N, 0);
		int start = 1;
		for(int i = 1;i<=N;i++) {
			if(zip[start] > zip[i]) {
				start = i;
			}
		}
		string res = zip[start];
		used[start] = 1;
		vector<int> stk;
		stk.push_back(start);
		while(!stk.empty()) {
			int top = stk.back();
			string best = "";
			int idx = -1;
			for(int i = 1;i<=N;i++) {
				if(G[top][i] && !used[i]) {
					if(best == "" || best > zip[i]) {
						best = zip[i];
						idx = i;
					}
				}
			}
			if(idx == -1) {
				stk.pop_back();
			}
			else {
				stk.push_back(idx);
				used[idx] = 1;
				res += zip[idx];
			}
		}

		printf("Case #%d: ", t);
		cout<<res<<endl;
	}
    return 0;
}
