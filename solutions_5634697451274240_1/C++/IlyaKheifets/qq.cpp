#include <bits/stdc++.h>
using namespace std;

string s, ans;
int res=  0;

void solve(int x){
	cin >> s;
	ans.clear();
	for (int res = 0 ;; ++res){
		bool c = true;
		for (int i = 0; i < s.size(); ++i){
			if (s[i] == '-'){
				c = false;
				break;
			}
		}
		if (c){
			cout << "Case #" << x << ": " << res << "\n";
			break;
		}
		int p = 0;
		while (s[p] == s[0])
			p++;
		for (int i = 0; i < p; ++i)
			s[i] = (s[i] == '+' ? '-' : '+');
	}
}

int main(){
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i){
		solve(i);
	}
	return 0;
}
