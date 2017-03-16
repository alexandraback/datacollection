#include <iostream>
using namespace std;

void solve(){
	int x, r, c;
	cin >> x >> r >> c;
	if(x > 6){cout << "RICHARD"; return;}
	if(x == 1){cout << "GABRIEL"; return;}
	if(x == 2){if(r*c%2 == 0) cout << "GABRIEL"; else cout << "RICHARD"; return;}
	if(x == 3){
		if(r < 2 || c < 2) cout << "RICHARD";
		else if(r*c%3 != 0) cout << "RICHARD";
		else cout << "GABRIEL";
		return;
	}
	if(x == 4){
		if(r < 3 || c < 3) cout << "RICHARD";
		else if(r*c % 4 != 0) cout << "RICHARD";
		else cout << "GABRIEL";
		return;
	}
	if(x == 5){
		if(r < 3 || c < 3) cout << "RICHARD";
		else if(r*c % 5 != 0) cout << "RICHARD";
		else cout << "GABRIEL";
		return;
	}
	if(x == 6){
		if(r < 4 || c < 4) cout << "RICHARD";
		else if(r*c % 6 != 0) cout << "RICHARD";
		else cout << "GABRIEL";
		return;
	}
}

int main(){
	int t; cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Case #" << i << ": ";
		solve();
		cout << endl;
	}
}
