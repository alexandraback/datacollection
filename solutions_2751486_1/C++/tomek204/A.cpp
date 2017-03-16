#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

typedef long long int LL;

using namespace std;

const int MAXL = 1e6+100;

int t, l, n, consecutive[MAXL], next[MAXL];
string s;

bool consonant(char c) {
	return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

LL solve() {
	s = "#"+s;
	for(int i=1;i<=l;i++) {
		consecutive[i] = (consecutive[i-1]+1)*consonant(s[i]);
		//printf("%d: %d\n", i, consecutive[i]);
		
	}
	fill(next, next+l+2, MAXL);
	for(int i=l;i>=n;i--) {
		next[i] = min(next[i], next[i+1]);
		if(consecutive[i] >= n) next[i-n+1] = min(next[i-n+1], i);
	}
	for(int i=n;i>=1;i--) next[i] = min(next[i], next[i+1]);
	//for(int i=1;i<=l;i++) printf("%d: %d\n", i, next[i]);
	LL res = 0;
	for(int i=1;i<=l;i++) if(next[i] <= l) res += (l-next[i]+1);
	return res;
}

int main() {
	cin >> t;
	for(int cs=1;cs<=t;cs++) {
		cin >> s >> n;
		l = s.length();
		printf("Case #%d: %lld\n", cs, solve());
	}
	return 0;
}
