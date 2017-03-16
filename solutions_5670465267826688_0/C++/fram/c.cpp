#include <iostream>
#include <cassert>
using namespace std;

typedef long long ll;

int molt(int x, int y){
	if(x < 0) return -molt(-x, y);
	if(y < 0) return -molt(x, -y);
	if(x == 1) return y;
	if(y == 1) return x;
	if(x == 2 && y == 2) return -1;
	if(x == 2 && y == 3) return 4;
	if(x == 2 && y == 4) return -3;
	if(x == 3 && y == 2) return -4;
	if(x == 3 && y == 3) return -1;
	if(x == 3 && y == 4) return 2;
	if(x == 4 && y == 2) return 3;
	if(x == 4 && y == 3) return -2;
	if(x == 4 && y == 4) return -1;
}

int a[100000];
void solve(){
	ll l, x;
	cin >> l >> x;
	for(int i=0; i<l; i++){
		char c; cin >> c;
		if(c=='i') a[i] = 2;
		else if(c=='j') a[i] = 3;
		else if(c=='k') a[i] = 4;
		else assert(false);
	}
	for(int i=l; i<l*x; i++) a[i] = a[i-l];
	
	int n = x*l;
	int ci = 0;
	int ris = 1;
	for(int i=0; i<n; i++){
		ris = molt(ris, a[i]);
		if(ris == 2 && ci == 0){ci = i+1;}
	}
	if(ci == 0){cout << "NO"; return;}
	if(ris != -1){cout << "NO"; return;}
	ris = 1;
	for(int i=n-1; i>=ci; i--){
		ris = molt(a[i], ris);
		if(ris == 4){
			{cout << "YES"; return;}
		}
	}
	cout << "NO";
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
