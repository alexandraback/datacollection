#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	string s;
	for (int cas=1;cas<=T;cas++) {
		cin >> s;
		int i=0;
		for (int c=0;c<(int)s.size()-1;c++) i+=s[c]!=s[c+1];
		i+=s.back()=='-';
		printf("Case #%d: %d\n",cas,i);
	}
}
