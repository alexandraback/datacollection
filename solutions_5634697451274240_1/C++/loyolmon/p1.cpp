#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	int T; cin>>T;
	for (int testCase=1; testCase<=T; testCase++) {
		int ans=0;
		string s; cin>>s; s.push_back('+');
		
		for (int i=0; i<s.size()-1; i++) if (s[i]!=s[i+1]) ans++;
		printf("Case #%d: %d\n", testCase, ans);
	}
	return 0;
}
