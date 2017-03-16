#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <string>
#define INF 2000000000
#define ii pair<int, int>

using namespace std;

bool ok;
int flag[1005];
vector <int> vec[1005];

void bfs(int x) {
	queue <int> q;
	q.push(x);
	while (!q.empty()) {
		if (!ok) break;
		x=q.front(); q.pop();
		flag[x]=1;
		for (int i=0;i<vec[x].size();i++) {
			if (flag[vec[x][i]]==0)  {q.push(vec[x][i]); flag[vec[x][i]]=1;}
			else {ok=false; break;}	
		}	
	}	
}

int main() {
	int ntc,n,m,a;
	scanf("%d",&ntc);
	for (int tc=1;tc<=ntc;tc++) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) vec[i].clear();
		for (int i=1;i<=n;i++) {
			scanf("%d",&m);
			for (int j=0;j<m;j++) {
				scanf("%d",&a);
				vec[i].push_back(a);	
			}	
		}
		ok=true;
		
		for (int i=1;i<=n;i++) {
			if (!ok) break;
			memset(flag,0,sizeof(flag));
			bfs(i);	
		}
		printf("Case #%d: ",tc);
		if (ok) printf("No\n"); else printf("Yes\n");
	}
    return 0;
}
