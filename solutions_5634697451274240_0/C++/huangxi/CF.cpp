//============================================================================
// Name        : CF.cpp
// Author      :
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
#define  whatis(x)  cout << #x << ": " << x << endl;
//int dx[4] = {0, -1, 0, 1};
//int dy[4] = {1, 0, -1, 0};
using namespace std;
#define  N   123
#define  eps 1e-13
#define  pi  acos(-1.0)
#define  inf 0XFFFFFFFFFFFFFFFll
#define  mod 1000000007ll
#define  LL  long long
#define  ULL unsigned long long


int Main() {

	ios_base::sync_with_stdio(0);
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	clock_t t1 = clock();

	int T; cin >> T;

	FOR(_T, T) {

		cout << "Case #" << _T << ": ";

		string s;
		cin >> s;

		int cnt = 0;
		REP(i, s.length()) {
			if (i == s.length() - 1 || s[i] != s[i+1]) {
				if (!(i == s.length() - 1 && s[i] == '+'))
					cnt++;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}


int main() {
	return Main();
}
