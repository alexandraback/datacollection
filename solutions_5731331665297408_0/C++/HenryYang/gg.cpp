#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
int n, m;
string zip[100];
int adj[100][100];
int com[100] = {};
int len;
void dfs(int x){
	while(len < n && adj[x][com[len]] ){
		len++;
		//printf("(%d->%d)", x, com[len-1]);
		dfs(com[len-1]);
	}
}
int main(){
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	int t, ctt = 0;
	cin >> t;
	while(t--){
		memset(adj, 0, sizeof(adj));
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			cin >> zip[i];
		for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			adj[a][b] = adj[b][a] = 1;
		}
		
		string ans="";
		for(int i = 0; i < n; i++)
			com[i] = i+1, ans += zip[i];
		for(int i = 0; i < ans.length(); i++)
			ans[i] = '9';
		do{
			len = 1;
			dfs(com[0]);
			if(len == n){
				string temp = "";
				for(int i = 0; i < n; i++)
					temp += zip[com[i]-1];
				
				if(temp < ans){
					ans = temp;
					//for(int i = 0; i < n; i++)
					//	cout << com[i];puts("");
					//puts("");
				}
			}
		}while(next_permutation(com, com+n));
		printf("Case #%d: %s\n", ++ctt, ans.c_str());
	}
	return 0;
}