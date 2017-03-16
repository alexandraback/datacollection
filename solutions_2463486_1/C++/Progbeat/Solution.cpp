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

vector<ll> good;

template <class hocus = bool> struct Solver {
	
    vi ds(ll x)
    {
        vi r;
        do r.push_back(x % 10);
        while (x /= 10);
        return r;
    }
    
    bool ispal(const vi &a)
    {
        for (int i = 0; 2 * i < sz(a); ++i)
            if (a[i] != a[sz(a) - 1 - i])
                return false;
        return true;
    }
    
	void run() {
        if (sz(good) == 0)
        {
            for (ll x = 1; x < 20000000; ++x)
            {
                if (ispal(ds(x)) && ispal(ds(x * x)))
                {
                    good.push_back(x * x);
                }
            }
        }
		ll a, b, res = 0;
        cin >> a >> b;
        cout << upper_bound(all(good), b) - lower_bound(all(good), a) << endl;
	}
};

int main() {
	freopen("C-large-1.in", "r", stdin);
	freopen("C-large-1.out", "w", stdout);
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
