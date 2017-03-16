#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

const double eps = 1e-8;
const int MAXN = 1000 + 200;
typedef pair<int, int> PII;
#define X first
#define Y second
#define PB push_back
vector<int> adj[MAXN], far[MAXN];
int in[MAXN];
int par[MAXN];

bool dfs(int u){
	for(int i = 0 ; i < far[u].size() ; i ++){
		int rt = far[u][i];
		if(par[rt] != 0)return true;
		par[rt] = 1;
		if(dfs(rt))return true;
	}
	return false;
}

bool solve(int n){
	bool cnt[MAXN];
	for(int i = 1; i <= n; i++){
		cnt[i] = 0;
	}
	//cout << "init!";
	while(true){
		int found = -1;
		for(int i = 0; i < n; i++){
			if(cnt[i + 1] == false && in[i + 1] == 0){
				found = i + 1;
				cnt[i + 1] = true;
				//cout << i + 1 << endl;
				break;
			}
		}
		if(found == -1)break;
		for(int i = 1; i <= n; i++){
			par[i] = 0;
		}
		if(dfs(found))return true;
	}
	return false;
}

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int T; cin >> T;

	for(int cas = 0; cas < T; cas++){
		printf("Case #%d: ", cas + 1);
		int n; cin >> n;
		for(int i = 0; i < n; i++){
			in[i + 1] = 0;
			adj[i + 1].clear();
			far[i + 1].clear();
		}
		for(int i = 0; i < n; i++){
			int v, u = i + 1, m;
			cin >> m;
			for(int j = 0; j < m; j++){
				cin >> v;
				adj[v].push_back(u);
				far[u].push_back(v);
				in[v] ++;
			}
		}
		//cout << "ok";
		if(solve(n)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
}