#include<bits/stdc++.h>
using namespace std;
int const N = 55;
int t, b, T = 1;
long long m;
bool ok;
int adj[N][N];
long long dp[N];
void solve(){
	memset(adj,0,sizeof(adj));
	memset(dp,0,sizeof(dp));
	ok = false;
	long long cont = 0;
	adj[1][b] = 1;
	cont++;
	dp[b] = 1;
	vector<int> nodes;
	for(int i = 2; i <= b; i++)
	 if(i != b) nodes.push_back(i);
 for(int i = 0; i < nodes.size(); i++){
 	adj[1][nodes[i]] = 1;
 	for(int j = 0; j < i; j++)
 		if(cont+dp[nodes[j]] <= m) cont += dp[nodes[j]], adj[nodes[i]][nodes[j]] = 1, dp[nodes[i]] += dp[nodes[j]];
	 if(cont+1LL <= m) cont++, adj[nodes[i]][b] = 1, dp[nodes[i]]++;
	 assert(cont<=m);
	}
	if(cont == m) ok = true;
}
int main(){
	//ifstream cin ("input.b");
	ofstream cout ("output.txt");
	cin >> t;
	while(t--){
		cin >> b >> m;
		cout << "Case #" << T++ << ":";
		solve();
		if(ok){
		 cout << " POSSIBLE\n";
		 for(int i = 1; i <= b; i++){
		 	assert(adj[i][i] == 0);
		 	for(int j = 1; j <= b; j++) cout << adj[i][j];
		 	cout << '\n';
			}
		}
		else cout << " IMPOSSIBLE\n";
	}
	return 0;
}
