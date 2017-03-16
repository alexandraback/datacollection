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
    int height;
    vector<vector<double>> F;
    
    double f(int a, int b, int y, int n)
    {
        if (b > y) return 1.0;
        if (n == 0) return 0.0;
        double &res = F[a][b];
        if (res >= -0.5) return res;
        res = 0;
        if (a < height && b < height)
        {
            res = (f(a + 1, b, y, n - 1) + f(a, b + 1, y, n - 1)) / 2;
        }
        else if (a < height)
        {
            res = f(a + 1, b, y, n - 1);
        }
        else if (b < height)
        {
            res = f(a, b + 1, y, n - 1);
        }
        return res;
    }
    
	void run() 
    {
		int n, x, y;
        cin >> n >> x >> y;
        assert((x + y) % 2 == 0);
        int layers = (abs(x) + y) / 2;
        REP (i, layers)
        {
            n -= 1 + i * 4;
        }
        double res = 0.0;
        parallelize
        {
            if (1 + layers * 4 <= n)
            {
                res = 1.0;
            }
            else if (n > 0)
            {
                height = layers * 2;
                assert(n <= height * 2);
                F = vector<vector<double>>(height + 1, vector<double>(height + 1, -1));
                res = f(0, 0, y, n);
            }
        }
        printf("%.12lf\n", res);
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
