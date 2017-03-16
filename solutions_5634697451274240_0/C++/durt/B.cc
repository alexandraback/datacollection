#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		string s;
		cin >> s;
		
		s = s + "+";
		int l = s.length();
		int res = 0;
		for (int i = 1; i < l; i++) {
			if (s[i] != s[i-1])
				res++;
		}
		
		cout << "Case #" << icase << ": " << res << endl;
	}
	return 0;
}
