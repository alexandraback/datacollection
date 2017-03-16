#include <iostream>
using namespace std;

int a[10000];

void solve(){
	int n; cin >> n;
	int ans = 1000000000;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int m=1; m<=1000; m++){
		int na = m;
		for(int i=0; i<n; i++) na += (a[i]+m-1)/m - 1;
		if(ans > na) ans = na;
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
