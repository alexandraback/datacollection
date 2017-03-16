#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF 100000000
#define EPS 1e-10
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;

int n;
int ed[1000];
vector<int> red[1000];
bool saw[1000];

int pre(int r, int z){
	int ret = 0;
	saw[z] = true;
	if(saw[ed[z]]){
		if(ed[z] == r) return 1;
		else return 0;
	}
	else return pre(r,ed[z])+1;
}

int dfs(int r, int z){
	int ret = 0;
	rep(i,red[z].size()){
		if(red[z][i] == r) continue;
		ret = max(ret,dfs(r,red[z][i])+1);
	}
	return ret;
}

void solve(){
	cin >> n;
	rep(i,1000) red[i].clear();
	rep(i,n){
		cin >> ed[i];
		ed[i]--;
		red[ed[i]].push_back(i);
	}
	int ans = 0;
	rep(i,n){
		rep(j,n) saw[j] = false;
		ans = max(ans,pre(i,i));
	}
	rep(i,n){
		int cnt = 0;
		rep(j,red[i].size()){
			int add = 0;
			for(int k = j+1; k < red[i].size(); k++){
				add = max(add,dfs(i,red[i][k])+1+(red[i][k]==ed[i]));
			}
			cnt = max(cnt,dfs(i,red[i][j])+1+add+(red[i][j]==ed[i]));
		}
		ans = max(ans,cnt);
	}
	cout << ans << endl;
}

int main(){
	int T;
	cin >> T;
	rep(i,T){
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}