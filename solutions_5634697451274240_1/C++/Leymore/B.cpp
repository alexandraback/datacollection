#include <bits/stdc++.h>

using namespace std;

int T, res;
string S, E;

void Rev(string::iterator s, string::iterator t) {
	string::iterator p;
	for(p = s; p != t; p ++) {
		if(*p == '-') *p = '+';
		else *p = '-';
	}
}

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++) {
		cin >> S; E = "";
		for(unsigned i = 0; i < S.size(); i ++) E += '+';
		for(res = 0; S != E; res ++) {
			if(S[0] == '-') {
				string::iterator k = S.end(); k --;
				for(; *k == '+'; k --); k ++;
				Rev(S.begin(), k);
			} else {
				string::iterator k = S.begin();
				for(; *k == '+'; k ++);
				Rev(S.begin(), k);
			}
		}
		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}
