#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define FOR(i, s, t) for(int i(s); i<=(int)(t); i++)
#define REP(i, n) FOR(i,0,n-1)

int a[55][55];
long long b[55];

void Work(int casen) {
	cout << "Case #" << casen << ": ";
	long long n, m;
	cin >> n >> m;
	if ((1LL << (n - 2)) < m) {
		cout << "IMPOSSIBLE" << endl;
		return ;
	}
	cout << "POSSIBLE" << endl;
	memset(a, 0, sizeof(a));
	long long mm = m;

	REP(i, n - 1) {
		REP(j, i)
		a[j][i] = 1;
	}
	if ((1LL << (n - 2)) == m) {
		a[0][n - 1] = 1;
		m--;
	}
	REP(i, n - 1) if ((1LL << i) & m) {
		a[i + 1][n - 1] = 1;
	}

	memset(b, 0, sizeof(b));
	b[0] = 1;
	FOR(i, 1, n - 1) {
		REP(j, i) if (a[j][i])
			b[i] += b[j];
	}
	if (b[n - 1] != mm) {
		cout << "Error" << endl << b[n - 1] << ' ' << m << endl;
	}

	REP(i, n) {
		REP(j, n) cout << a[i][j];
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		Work(i);
}
