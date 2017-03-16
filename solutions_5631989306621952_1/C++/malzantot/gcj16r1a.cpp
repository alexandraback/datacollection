#include <iostream>
#include <cstdio>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/malzantot/Documents/codingspace/A-large.in-2.txt", "r", stdin);
	freopen("/Users/malzantot/Documents/codingspace/A1-large-output.txt", "w", stdout);

#endif

	int tt;
	cin >> tt;
	for (int i = 1; i <= tt; i++) {
	string s;
	cin >> s;

	string ret = " ";
	ret[0] = s[0];
	int n = s.size();
	for (int i = 1; i <n ;i++) {
		if (s[i] >= ret[0]) {
			ret = (s[i] ) + ret;
		} else {
			ret += s[i];
		}
	}
	printf("Case #%d: %s\n", i, ret.c_str());
	}

	
	return 0;

}
