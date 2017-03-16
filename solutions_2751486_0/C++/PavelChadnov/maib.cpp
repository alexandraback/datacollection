#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define forn(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define lng long long

bool is_vowel(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

bool ok(string const &s, int n) {
	int l = s.length();
	int i=0;
	while (i<l) {
		while (i<l && is_vowel(s[i])) ++i;
		if (i==l)break;
		int j=i;
		while (j<l && !is_vowel(s[j]))++j;
		if (j-i>=n)return true;
		i=j;
	}
	return false;
}

int solve(string s, int k) {
	int l = s.length();
	int res=0;
	for(int i=0;i<l;++i) {
		for(int j=1;j<=l-i;++j) {
			string t = s.substr(i, j);
			if (ok(t, k)) {
				++res;
			}
		}
	}
	return res;
}

int main() {
#ifdef __ASD__ 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	

	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	int t=0;
	while (tc--) {
		string s;
		int k;
		cin >> s >> k;
		int res = solve(s, k);
		++t;
		printf("Case #%d: %d\n", t, res);
	}


	return 0;

}