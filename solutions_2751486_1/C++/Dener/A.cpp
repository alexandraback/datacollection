#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

string s;
vector< int > goodlen;
vector< int > firstgood;
int kol;

inline bool isfalse(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void solve() {
	cin >> s >> kol;

	goodlen.resize(s.size());
	goodlen[s.size() - 1] = (isfalse(s[s.size() - 1]) ? 0 : 1);
	for (int i = (int)(s.size()) - 2; i >= 0 ; i--) {
		if (isfalse(s[i]))
			goodlen[i] = 0;
		else
			goodlen[i] = 1 + goodlen[i+1];
	}

	firstgood.assign(s.size(), -1);
	if (goodlen[0] >= kol)
		firstgood[0] = 0;

	for (int i = 1; i < s.size(); i++)
		if (goodlen[i] >= kol)
			firstgood[i] = i;
		else
			firstgood[i] = firstgood[i-1];

	long long ans = 0;
	for (int r = kol - 1; r < s.size(); r++) {
		int pos = firstgood[r - kol + 1];
		ans += pos + 1;
	}

	cout << ans << endl;

	return;
}

int main() {
#ifdef OFFLINE
	freopen("A_input.txt","r", stdin);
	freopen("A_output.txt","w", stdout);
#endif
	int t;
	scanf("%d\n", &t);
	for (int testnum = 0; testnum < t; testnum++) {
		printf("Case #%d: ", testnum + 1);
		solve();
	}
}
