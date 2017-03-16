#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#define MAXN 1024
using namespace std;

int n;
vector<int> par[MAXN];
set<int> canreach[MAXN];
int incoming[MAXN];
queue<int> q;

//int p[MAXN];
/*int find_id(int id) {
	if(p[id] == id || p[id] == -1) return p[id];
	p[id] = find_id(p[id]);
}*/

int main() {
	int t,tc;
	int i, j;
	int t1, t2, cc, cv;
	bool diamond;
	scanf("%d", &tc);
	for(t=0;t<tc;t++) {
		scanf("%d", &n);
//		memset(p, -1, sizeof(p));
		memset(incoming, 0, sizeof(incoming));
		while(!q.empty()) q.pop();
		diamond = 0;
		for(i=0;i<n;i++) {
			par[i].clear();
			canreach[i].clear();
		}

		for(i=0;i<n;i++) {
			scanf("%d", &t1);
			if(t1 == 0) q.push(i);
			for(j=0;j<t1;j++) {
				scanf("%d", &t2);
				par[t2-1].push_back(i);
				incoming[i]++;
			}
		}
		
		while(!q.empty()) {
			cc = q.front(); q.pop();
			canreach[cc].insert(cc);
			t1 = canreach[cc].size();
//			fprintf(stderr, "%d|", cc);
//			for(set<int>::iterator ii = canreach[cc].begin();ii!=canreach[cc].end();ii++)
//				fprintf(stderr, "%d,", *ii);
			for(i=0;i<(int)par[cc].size();i++) {
				cv = par[cc][i];
//				fprintf(stderr, "%d,", cv);
				t2 = canreach[cv].size();
				canreach[cv].insert(canreach[cc].begin(), canreach[cc].end());
				if(canreach[cv].size() != t2+t1) {
					diamond=1; break;
				}
				incoming[cv]--;
				if(incoming[cv] == 0) q.push(cv);
			}
			if(diamond) break;
//			fprintf(stderr, "\n");
		}
		printf("Case #%d: ", t+1);
		if(diamond) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

