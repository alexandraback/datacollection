// IN THE NAME OF GOD

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long int lld;
typedef long double ldb;

#define all(c) c.begin(),c.end()
#define tr(c,it) for(__typeof(c.begin()) it; it!=c.end(); it++)

#define ff ifstream cin; ofstream cout; cout.open("out2.txt");


bool vis[100010];
vector <int> vct[100010];
int dfs(int i, int par){
	if(vis[i]){
		return 0;
	}
	vis[i]=1;
	int zz = 0;
	bool mk = 0;
	pair <bool,int> pi;
	int sz = vct[i].size();
	for(int j=0; j<sz; j++){
		if(vct[i][j]==par) continue;
		zz=max(zz,dfs(vct[i][j],i));
	}
	return zz+1;
}

int main(){
	ff
	cin.open("C-small-attempt1 (1).in");
	int n, m, x, y;
	int t;
	cin >> t;
	int j=0;
	while(t--){
		j++;
		
	cin >> n;
	for(int i=1; i<=n;i++){
		vis[i]=0;
		vct[i].clear();
	}
	for(int i = 1; i <= n; i++){
		cin >> x;
		vct[i].pb(x);
		vct[x].pb(i);
	}
	int zz = 0;
	int ans =0;
	pair <bool,int> rr;
	for(int i=1; i<=n; i++){
		for(int kk=1; kk<=n; kk++) vis[i]=0;
		ans = max(ans,dfs(i,-1));
	}
	cout << "Case #" << j << ": ";
	cout << ans << endl;
}
	return 0;
}
