#include <iostream>
#include <string>
using namespace std;


void solve(){
	string s;
	cin >> s;
	int ans = 0;
	int l = s.size();
	for(int i=0; i<l-1; i++) if(s[i] != s[i+1]) ans++;
	if(s[l-1] == '-') ans++;
	cout << ans << endl;
}

int main(){
	int t;
	cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
