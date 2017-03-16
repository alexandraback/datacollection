/*
 * GCC version:			4.6
 * Command line:		g++ -std=c++0x -m64 -02 -fno-strict-aliasing -Wl,--stack=268435456 Solution.cpp
 */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for(int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define CL(a, b)		memset(a, b, sizeof a)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define parallelize if (hocus pokus = true)

template <class hocus = bool> struct Solver {
	
	void run() {
		int n, m;
        cin >> n >> m;
        vector<vi> a(n, vi(m));
        REP (i, n) REP (j, m) cin >> a[i][j];
        REP (h, 100)
        {
            vector<bool> row(n, true), col(m, true);
            REP (i, n) REP (j, m)
            {
                if (a[i][j] != h)
                {
                    row[i] = false;
                    col[j] = false;
                }
            }
            REP (i, n) REP (j, m)
            {
                a[i][j] += row[i] || col[j];
            }
        }
        REP (i, n) REP (j, m)
        {
            if (a[i][j] != 100)
            {
                puts("NO");
                return;
            }
        }
        puts("YES");
	}
};

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	cout.precision(12);	
	cout.setf(ios::fixed);
	int i = 0, n;
	for (cin >> n; i < n; ) {
		printf("Case #%d: ", ++i);
		Solver<> *s = new Solver<>;
		s->run();
		delete s;
	}
	return 0;
}
