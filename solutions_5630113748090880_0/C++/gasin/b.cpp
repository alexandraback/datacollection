#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define INF 100000000
#define EPS 1e-10
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;

int h[3000];

void solve(){
	int n;
	vector<int> ans;
	rep(i,3000) h[i] = 0;
	cin >> n;
	rep(i,2*n-1) rep(j,n){
		int tmp;
		cin >> tmp;
		h[tmp]++;
	}
	rep(i,3000) if(h[i]%2 == 1) ans.push_back(i);
	rep(i,ans.size()) cout << " " << ans[i];
	cout << endl;
}

int main(){
	int T;
	cin >> T;
	rep(i,T){
		cout << "Case #" << i+1 << ":";
		solve();
	}
}