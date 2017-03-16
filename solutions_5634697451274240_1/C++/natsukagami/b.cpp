#include <iostream>
#include <cstdio>
using namespace std;

string s;

int main() {
	int Tc; cin >> Tc;
	for (int T = 1; T <= Tc; ++T) {
		printf("Case #%d: ", T);
		cin >> s; int cnt = 0;
		for (int i = 0; i < (int)s.length(); ++i) {
			++cnt; int st = i; 
			while (i < (int)s.length() && s[i] == s[st]) ++i; --i;
		}
		if (s[s.length() - 1] == '+') --cnt;
		printf("%d\n", cnt);
	}
}