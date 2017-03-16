#include <bits/stdc++.h>

using namespace std;

#define INP "inp.txt"
#define OUT "out.txt"
#define oo 123456789

int T, N, len, c, j, hieu;
string s1, s2, ans1, ans2, s;
char tmpS[10];

int abs(int N) {
	return (N < 0) ? N * -1 : N;
}

void check() {
	int tmpC, tmpJ;
	string sc, sj;
	sc = sj = "";
	tmpC = tmpJ = 0;
	for (int i = 0; i < len; ++i)
	{
		tmpC = tmpC * 10 + tmpS[i] - '0';
		sc += tmpS[i];
	}
	for (int i = len; i < len * 2; ++i)
	{
		tmpJ = tmpJ * 10 + tmpS[i] - '0';
		sj += tmpS[i];
	}

	if((abs(tmpC - tmpJ) < hieu) || ((abs(tmpC - tmpJ) == hieu) && c > tmpC) || ((abs(tmpC - tmpJ) == hieu) && c == tmpC && j > tmpJ)) {
		c = tmpC; j = tmpJ; ans1 = sc; ans2 = sj; hieu = abs(tmpC - tmpJ);
	}
}

void iku(int m) {
	if(m == len * 2) {
		//update
		check();
		return;
	}
	if(s[m] == '?') {
		for (int i = 0; i < 10; ++i)
		{
			char tmp = tmpS[m];
			tmpS[m] = i + '0';
			iku(m + 1);
			tmpS[m] = tmp;
		}
	}
	else {
		tmpS[m] = s[m];
		iku(m + 1);
	}

}

void solve() {
	len = s1.length();
	ans1 = ans2 = "";
	s = s1 + s2;
	c = j = hieu = oo;
	iku(0);
}

int main () {
	freopen(INP, "r", stdin);
	freopen(OUT, "w", stdout);

	scanf(" %d ", &T);
	for(int tt = 1; tt <= T; tt++) {
		cin >> s1 >> s2;
		solve();
		cout << "Case #" << tt << ": " << ans1 << " " << ans2 << endl;
	}
	return 0;
}