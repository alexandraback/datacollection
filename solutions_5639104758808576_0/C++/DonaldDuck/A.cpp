#include <iostream>
#include <stdio.h>
#include <cassert>
#include <algorithm>
#include <string.h>

#define MAXN 1010

using namespace std;

char s[MAXN];
int T;
int N;

int solve() {
	cin >> N;
	cin >> s;
	assert(N == (int)(strlen(s) - 1));
	
	int res = 0;
	int sum = s[0]-'0';
	for (int i=0; i<N; i++) {
		res = max(res, i+1-sum);
		sum += (s[i+1]-'0');
	}
	
	return res;
}

int main() {
	cin >> T;
	for (int t=1; t<=T; t++)
		cout << "Case #" << t << ": " << solve() << endl;
	return 0;
}
