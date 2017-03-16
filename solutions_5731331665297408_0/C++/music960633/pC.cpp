#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string str[10], ans;
bool map[10][10], visit[10], first;

void dfs(int now, int n, vector<int> path, int S, string s){
	//for(int i=0; i<path.size(); ++i) printf("%d ", path[i]);
	//printf("[%d]\n", S);
	if(S == (1<<n)-1){
		// cout << s << endl;
		if(first || s<ans){
			ans = s;
			first = false;
		}
		return;
	}
	for(int i=0; i<n; ++i){
		if(map[now][i] && (S&(1<<i))==0){
			path.push_back(i);
			dfs(i, n, path, S|(1<<i), s+str[i]);
			path.pop_back();
		}
	}
	if(path.size()>1){
		path.pop_back();
		dfs(path[path.size()-1], n, path, S, s);
	}
}

int main(){
	int T, n, m;
	vector<int> path;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t){
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; ++i) cin >> str[i];
		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j) map[i][j] = false;
		}
		for(int i=0; i<m; ++i){
			int a, b;
			scanf("%d%d", &a, &b);
			map[a-1][b-1] = map[b-1][a-1] = true;
		}
		first = true;
		path.clear();
		for(int i=0; i<n; ++i){
			path.push_back(i);
			dfs(i, n, path, 1<<i, str[i]);
			path.pop_back();
		}
		printf("Case #%d: ", t);
		cout << ans << endl;
	}
	return 0;
}

