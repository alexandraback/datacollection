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
#define  N   123456789
#define  eps 1e-8
#define  pi  acos(-1.0)
#define  inf 0XFFFFFFFFFFFFFFll
#define  mod 1000000007ll
#define  LL  long long
#define  ULL unsigned long long


int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("codejam.out", "w", stdout);

	int T;
	cin >> T;

	FOR(_T, T) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int sum = s[0] - '0';
		int ans = 0;
		FOR(i, n) {
			ans = max(ans, i - sum);
			sum += s[i] - '0';
		}
		cout << "Case #" << _T << ": " << ans << endl;
	}

	return 0;
}
