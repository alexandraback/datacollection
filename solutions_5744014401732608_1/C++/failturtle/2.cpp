#include <bits/stdc++.h>

#define sz(z) (int)z.size()
#define fo(i,a,b) for (auto (i) = (a); (i) < (b); (i)++)
#define mp make_pair
#define pb push_back

using namespace std;

#define DEBUG

#ifdef DEBUG
#define D(x...) printf(x)
#else
#define D(x...) 
#endif

typedef long long ll;
typedef pair<int,int> ii;

int adj[55][55];
int num[55];
int in[55];

int main() {
	int t;
	scanf("%d\n", &t);
	for (int _ = 1; _ <= t; _++) {
		printf("Case #%d: ", _);
		int b, m;
		scanf("%d %d", &b, &m);
		vector <ii> v;
		for (int i = 1; i <= b; i++) {
			for (int j = i+1; j <= b; j++) {
				v.pb({i,j});
			}
			in[i] = 0;
			num[i] = 0;
		}
		bool good = 0;
		fo(k,0,(1<<(sz(v)))) {
			fo(i,1,b+1)
				in[i] = num[i] = 0;
			fo(j,0,sz(v)) {
				if ((1<<j)&k) {
					adj[v[j].first][v[j].second] = 1;
					in[v[j].second]++;
				} else {
					adj[v[j].first][v[j].second] = 0;
				}
			}
			num[1] = 1;
			queue <int> q;
			q.push(1);
			while (sz(q)) {
				int at = q.front();
				q.pop();
				for (int i = 1; i <= b; i++) {
					if (adj[at][i] == 1) {
						num[i] += num[at];
						in[i]--;
						if (in[i] == 0) {
							q.push(i);
						}
					}
				}
			}
			if (num[b] == m) {
				printf("POSSIBLE\n");
				fo(i,1,b+1) {
					fo(j,1,b+1) {
						printf("%d", adj[i][j]);
					}
					puts("");
				}
				good = 1;
				break;
			}
		}
		if (!good) puts("IMPOSSIBLE");
		
	}
	
	return 0;
}
