#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int t;
	cin>>t;
	for (int k = 0; k < t; ++k) {
		int sm;
		cin>>sm;
		string s;
		cin>>s;
		int res = 0, st = 0;
		for (int i = 0; i < s.size(); ++i) {
			int d = max(0, i-st);
			res += d;
			st += d + s[i]-'0';
		}
		printf("Case #%d: %d\n", k+1, res);
	}
	return 0;
}

