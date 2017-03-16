#include <bits/stdc++.h>
using namespace std;

int T, i, N;

long long bbcv, bbjv;
string c, j, s;

void go(int i, long long bcv, long long bjv) {
	if (i == c.length()) {
		if (abs(bcv-bjv) < abs(bbcv-bbjv) ||
			abs(bcv-bjv) == abs(bbcv-bbjv) && bcv < bbcv ||
			abs(bcv-bjv) == abs(bbcv-bbjv) && bcv == bbcv && bjv < bbjv)
			bbcv = bcv, bbjv = bjv;
		return;
	}

	if (c[i] == '?' && j[i] == '?') {
		if (bcv == 0 && bjv == 0) {
			go(i+1, bcv*10 + 0, bjv*10 + 0);
			go(i+1, bcv*10 + 1, bjv*10 + 0);
			go(i+1, bcv*10 + 0, bjv*10 + 1);
		} else if (bcv == bjv) {
			go(i+1, bcv*10 + 0, bjv*10 + 0);
			go(i+1, bcv*10 + 0, bjv*10 + 1);
			go(i+1, bcv*10 + 1, bjv*10 + 0);
		} else if (bcv > bjv) {
			go(i+1, bcv*10+0, bjv*10+9);
		} else {
			go(i+1, bcv*10+9, bjv*10+0);
		}
	} else if (c[i] == '?') {
		if (bcv == bjv) {
			go(i+1, bcv*10 + (j[i]-'0'), bjv*10 + (j[i]-'0'));
			if (j[i] > '0') go(i+1, bcv*10 + (j[i]-'0'-1), bjv*10 + (j[i]-'0'));
			if (j[i] < '9') go(i+1, bcv*10 + (j[i]-'0'+1), bjv*10 + (j[i]-'0'));
		} else if (bcv > bjv) {
			go(i+1, bcv*10 + 0, bjv*10 + (j[i]-'0'));
		} else {
			go(i+1, bcv*10 + 9, bjv*10 + (j[i]-'0'));
		}
	} else if (j[i] == '?') {
		if (bcv == bjv) {
			go(i+1, bcv*10 + (c[i]-'0'), bjv*10 + (c[i]-'0'));
			if (c[i] > '0') go(i+1, bcv*10 + (c[i]-'0'), bjv*10 + (c[i]-'0'-1));
			if (c[i] < '9') go(i+1, bcv*10 + (c[i]-'0'), bjv*10 + (c[i]-'0'+1));
		} else if (bcv > bjv) {
			go(i+1, bcv*10 + (c[i]-'0'), bjv*10 + 9);
		} else {
			go(i+1, bcv*10 + (c[i]-'0'), bjv*10 + 0);
		}
	} else {
		go(i+1, bcv*10 + (c[i]-'0'), bjv*10 + (j[i]-'0'));
	}
}

int main() {
	cin >> T;
	for (int t=1; t<=T; t++) {
		
		bbcv = 1LL<<62, bbjv = 0;
		cin >> c >> j;
		go(0, 0, 0);
		
		string fmt("Case #%d: %0__lld %0__lld\n");
		for (int i=0; i<fmt.length(); i++)
			if (fmt[i] == '_') {
				fmt[i] = '0'+c.length()/10;
				fmt[i+1] = '0'+c.length()%10;
			}

		printf(fmt.c_str(), t, bbcv, bbjv);
	}
}
