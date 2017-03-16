#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool foo(char a, char b)
{
	return a > b;
}

int main()
{
	int t; cin >> t;
	for (int i =1; i <= t; i++) {
		string s; cin >> s;
		string ans = s.substr(0,1);
		int len = s.length();
		for (int j = 1; j < len; j++){
			if (s[j]>=ans[0])	ans = s[j]+ans;
			else	ans += s[j];
		}
		cout << "Case #" << i << ": " << ans << "\n";
	}
}
