//============================================================================
// Name        : CodeJam.cpp
// Author      : ccdd4211
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#define  RD(x)      scanf("%d", &x)
#define  REP(i, n)  for (int i=0; i<int(n); ++i)
#define  FOR(i, n)  for (int i=1; i<=int(n); ++i)
#define  pii        pair<int, int>
#define  piL        pair<int, long long>
#define  mp         make_pair
#define  pb         push_back
#define  whatis(x)  cout << #x << ": " << x << endl
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

using namespace std;
#define  N   1234678
#define  eps 1e-8
#define  pi  acos(-1.0)
#define  inf 0XFFFFFFFFFFFFFFll
#define  mod 1000000007ll
#define  LL  long long
#define  ULL unsigned long long

int mul[5][5] = {
		{0, 0, 0, 0, 0},
		{0, 1, 2, 3, 4},
		{0, 2, -1, 4, -3},
		{0, 3, -4, -1, 2},
		{0, 4, 3, -2, -1}
};

string work(string s) {
	int n = s.length();
	static int a[N];
	REP(i, n) {
		if (s[i] == '1')
			a[i] = 1;
		if (s[i] == 'i')
			a[i] = 2;
		if (s[i] == 'j')
			a[i] = 3;
		if (s[i] == 'k')
			a[i] = 4;
	}

	static int suf[N];

	suf[n-1] = a[n-1];
	for (int i = n - 2; i >= 0; i--) {
		if (suf[i+1] > 0)
			suf[i] = mul[a[i]][suf[i+1]];
		else
			suf[i] = -mul[a[i]][-suf[i+1]];
	}

	bool two = false;
	int pre = 1;
	REP(i, n-1) {
		if (pre > 0)
			pre = mul[pre][a[i]];
		else
			pre = -mul[-pre][a[i]];

		if (two && mul[2][3] == pre && suf[i+1] == 4)
			return "YES";
		if (pre == 2)
			two = true;
	}

	return "NO";

}

int Main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("codejam.out", "w", stdout);


	int T;
	cin >> T;

	FOR(_T, T) {
		int l, x;
		string s;
		cin >> l >> x >> s;
		if (x > 16) {
			x = 16 + x % 4;
		}
		string str;
		while (x--)
			str += s;

		cout << "Case #" << _T << ": " << work(str) << endl;
	}

	return 0;
}


int main() {
	return Main();
}
