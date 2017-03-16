#include <bits/stdc++.h>
using namespace std;

inline void Solve(){
	int m, n, w;
	cin>>m>>n>>w;
	int ans = m * ( w + (n - 1) / w );
	cout<<ans<<endl;
	return;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, tt = 0;
	cin>>t;
	while(t--){
		cout<<"Case #"<<++tt<<": ";
		Solve();
	}
	return 0;
}
