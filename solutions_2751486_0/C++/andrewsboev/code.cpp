#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <deque>

using namespace std;

int t;

bool vowel(char c) {
	return ( c == 'a' || c == 'e' ||
			 c == 'i' || c == 'o' ||
			 c == 'u' );
}

bool has(string s, int n) {
	for ( int i = 0 ; i < s.length() - n + 1 ; ++i ) {
		bool flag = true;
		for ( int j = i ; j < i + n ; ++j )
			if ( vowel(s[j]) ) { flag = false; break; }
		if ( flag ) return true;
	}
	return false;
}

__int64 solve(string s, int n) {
	__int64 ans = 0;
	for ( int i = 0 ; i < s.length() - n + 1 ; ++i ) {
		for ( int j = i + n - 1 ; j < s.length() ; ++j )
			if ( has(s.substr(i, j - i + 1), n) ) ++ans;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d\n", &t);
	for ( int i = 0 ; i < t ; ++i ) {
		__int64 answer = 0;

		int n;
		char s[200];
		scanf("%s %d\n", &s, &n);

		answer = solve(string(s), n);

		printf("Case #%d: %d\n", i + 1, answer);
	}

	return 0;
}