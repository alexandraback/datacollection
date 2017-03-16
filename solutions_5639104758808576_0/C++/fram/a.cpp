#include <iostream>
using namespace std;

int m;

void solve(){
	cin >> m;
	int ans = 0;
	int q = 0;
	for(int i=0; i<=m; i++){
		char c; cin >> c;
		int x = c-'0';
		if(x > 0 && q < i){ans += i-q; q=i;}
		q += x;
	}
	cout << ans;
}

int main(){
	int t; cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
	return 0;
}
