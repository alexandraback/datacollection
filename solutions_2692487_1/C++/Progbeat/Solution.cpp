/*
 * GCC version:			4.6.3
 * GMP version:         5.1.1
 * Command line:		g++ -std=c++0x -fopenmp -0fast -Wall -Wl,--stack=268435456 -lgmpxx -lgmp Solution.cpp
 */
#include <algorithm>
#include <iostream>
#include <cassert>
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

template <class hocus = bool> struct Solver 
{

    void run() 
    {
		int A, n;
        cin >> A >> n;
        vector<int> B(n);
        REP (i, n) cin >> B[i];
        sort(all(B));
        int res = n, added = 0;
        REP (i, n)
        {
            while (A <= B[i] && added < res)
            {
                A += A - 1;
                ++added;
            }
            if (added == res) break;
            assert(B[i] < A);
            A += B[i];
            res = min(res, n - i - 1 + added);
        }
        cout << res << endl;
	}
};

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
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
