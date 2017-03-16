#include <bits/stdc++.h>
using namespace std;

string fill(int n, size_t a){
	string ans = "";
	while(n > 0){
		ans += char('0' + n%10);
		n /= 10;
	}
	reverse(ans.begin(), ans.end());
	while(ans.size() < a)
		ans = '0' + ans;
	return ans;
}

bool match(int n, string s){
	string t = fill(n, s.size());
	for(size_t i = 0; i < s.size(); i++)
		if(s[i] != '?' && t[i] != s[i])
			return false;
	return true;
}

int main(){
	int T;
	cin >> T;

	for(int t = 0; t < T; t++){
		string c, j;
		cin >> c >> j;
		int ans = 1000, ans_x = -1, ans_y = -1;
		for(int x = 0; x < 1000; x++){
			if(match(x, c)){
				for(int y = 0; y < 1000; y++){
					if(abs(x-y) < ans && match(y, j)){
						ans = abs(x-y), ans_x = x, ans_y = y;
					}
				}
			}
		}
		cout << "Case #" << t+1 << ": " << fill(ans_x, c.size()) << " " << fill(ans_y, j.size()) << endl;
	}

	return 0;
}
