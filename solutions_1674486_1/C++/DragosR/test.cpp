#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
const int maxn = 1005;
using namespace std;

int T, N, d[maxn] ;
long long nr[maxn] ;
vector <int> G[maxn] ;
int main() {

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	scanf("%d\n", &T); 

	for(int t = 1; t <= T; ++t) {
		scanf("%d\n", &N);
		for(int i = 1; i <= N; ++i)
			G[i].clear();
		for(int i = 1; i <= N; ++i) {
			int m, x;
			scanf("%d", &m);
			for(int j = 1; j <= m; ++j) {
				scanf("%d", &x) ;
				G[i].push_back(x);
			}
		}
		bool ok = 0;
/*
		for(int i = 1; i <= N; ++i) {
			printf("%d ", i);
			for(int j = 0; j < G[i].size(); ++j)
				printf("%d ", G[i][j]);
			printf("\n");
		}
*/		for(int i = 1; i <= N; ++i) {
			memset(nr, 0, sizeof(nr)) ;
			memset(d, 0, sizeof(d)) ;
			
			queue <int> q;
			q.push(i) ; 
			nr[i] = d[i] = 1;
			while(!q.empty()) {
				int node = q.front() ; q.pop();
				for(int j = 0; j < G[node].size(); ++j) {
					if(!d[G[node][j]]) {
					       q.push(G[node][j]) ; d[G[node][j]] = d[node] + 1;
					       nr[G[node][j]] = nr[node];
					} else  {
						nr[G[node][j]] += nr[node] ;
					}
				}
			}
			for(int j = 1; j <= N; ++j) {
				if(j != i && nr[j] > 1) 
					ok = 1;
			}
//			printf("%d ", i) ; for(int j = 1; j <= N; ++j) printf("%d ", d[j]); printf("\n");
		}
		printf("Case #%d: ", t);
		if(ok) printf("Yes\n"); else printf("No\n");
	}
	return 0;
}	
