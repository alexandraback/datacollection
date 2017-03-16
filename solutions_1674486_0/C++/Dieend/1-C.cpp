#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

bool bfs(int start, vector<vector<int> >& path, vector<bool>& udah) {
	queue<int> q;
	q.push(start);
	udah[start] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i=0; i< (int)path[now].size(); i++) {
			//cout << "cek  " << path[now][i] << endl;
			if (udah[path[now][i]]) {
				return true;
			}
			q.push(path[now][i]);
			udah[path[now][i]] = true;
		} 
	}
	return false;
}

int main(){
	int t,n,np;
	cin >> t;
	for (int tc=1; tc<=t; tc++) {
		scanf("%d",&n);
		vector<vector<int> > path(n);
		bool diamond = false;
		for (int j=0; j<n; j++) {
			scanf("%d",&np);
			path[j] = vector<int>(np);
			for (int k=0; k<np; k++) {
				scanf("%d",&path[j][k]);
				path[j][k]--;
			}
		}
		for (int i=0; i<n; i++) {
			vector<bool> udah(n);
			if (bfs(i, path, udah)) {
				diamond = true;
				break;
			} 
		}
		if (diamond) {
			printf("Case #%d: Yes\n", tc);
		} else {
			printf("Case #%d: No\n", tc);
		}
	}
	return 0;
}
