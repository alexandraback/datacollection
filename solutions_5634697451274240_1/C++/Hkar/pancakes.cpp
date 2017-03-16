#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void flip(string &s){for(auto&i:s)i = i == '+' ? '-' : '+';}
int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		int ans = 0;
		for(int i = 0; i < s.size(); ++i) if(s[i] == '-') ++ans, flip(s);
		printf("Case #%d: %d\n",t,ans);
	}
}