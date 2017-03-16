#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<int> G[1010];
int N,P[1010],ans,chk[1010],Q[1010],deg[1010],dep[1010],sum;

void go(int x)
{
	int head = -1, tail = -1;
	Q[++head] = x; chk[x] = 1;
	while (tail < head){
		int x = Q[++tail];
		for (int y : G[x]) if (!chk[y]){
			Q[++head] = y; chk[y] = 1;
		}
	}
	
	queue<int> q;
	int n = head + 1;
	for (int i=0;i<n;i++){
		int x = Q[i];
		deg[x] = G[x].size();
		dep[x] = 0;
		if (deg[x] == 1) q.push(x);
	}

	int c = n;
	while (!q.empty()){
		int x = q.front(); q.pop(); c--; dep[x]++;
		for (int y : G[x]){
			deg[y]--;
			if (deg[y] == 1){
				q.push(y);
			}
			if (deg[y] != 0){
				if (dep[y] < dep[x])
					dep[y] = dep[x];
			}
		}
	}

	if (c == 2){
		sum += 2;
		for (int i=0;i<n;i++){
			int x = Q[i];
			if (deg[x] == 2) sum += dep[x];
		}
	}
	ans = max(ans,c);
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test); for (int Case=1;Case<=Test;Case++){
		scanf ("%d",&N);
		for (int i=1;i<=N;i++){
			scanf ("%d",&P[i]);
			G[i].push_back(P[i]);
			G[P[i]].push_back(i);
			chk[i] = 0;
		}
		ans = 0; sum = 0;
		for (int i=1;i<=N;i++) if (!chk[i]) go(i);
		ans = max(ans,sum);

		for (int i=1;i<=N;i++) G[i].clear();
		printf ("Case #%d: %d\n",Case,ans);
	}

	return 0;
}