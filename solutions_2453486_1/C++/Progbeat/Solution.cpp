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
	
    char s[4][5];
    
    bool check(char p)
    {
        vector<int> c1(7), c2(7), c3(7), c4(7);
        REP (i, 4)
        {
            REP (j, 4)
            {
                if (s[i][j] == 'T' || s[i][j] == p)
                {
                    ++c1[i];
                    ++c2[j];
                    ++c3[i + j];
                    ++c4[i - j + 3];
                }
            }
        }
        REP (i, 7)
        {
            if (c1[i] == 4 || c2[i] == 4 || c3[i] == 4 || c4[i] == 4)
            {
                return true;
            }
        }
        return false;
    }
    
	void run() {
        bool over = true;
	    REP (i, 4)
        {
            cin >> s[i];
            REP (j, 4)
                if (s[i][j] == '.')
                {
                    over = false;
                }
        }
        if (check('X'))
        {
            puts("X won");
        }
        else if (check('O'))
        {
            puts("O won");
        }
        else if (over)
        {
            puts("Draw");
        }
        else 
        {
            puts("Game has not completed");
        }
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
