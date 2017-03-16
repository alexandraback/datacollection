#include <bits/stdc++.h>
using namespace std;
int dp[200];
int compress(string s) {
	string f = "#";
	for (int j = 0; j < s.length(); j++) if (s[j] != (*f.rbegin())) f.push_back(s[j]);
	return *f.rbegin() == '+' ? f.length() - 2 : f.length() - 1;
}

int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
    	string inp; 
    	cin >> inp;
    	printf("Case #%d: %d\n", i, compress(inp));
    }
	return 0;
}