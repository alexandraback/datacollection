/*
 * GCC version:			4.6.3
 * GMP version:         5.1.1
 * Command line:		g++ -std=c++0x -fopenmp -0fast -Wall -Wl,--stack=268435456 -lgmpxx -lgmp Solution.cpp
 */
#include <algorithm>
#include <iostream>
#include <fstream>
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

vector<string> words;

struct __AA__
{
    __AA__()
    {
        ifstream fin("garbled_email_dictionary.txt");
        for (string word; getline(fin, word); words.push_back(word));
        sort(all(words));
    }
} __aa__;

void relax(int &x, int y)
{
    if (y < x) x = y;
}

template <class hocus = bool> struct Solver 
{
	
	void run() 
    {
		assert(sz(words) == 521196);
        string s;
        cin >> s;
        vector<vector<int>> f(sz(s) + 1, vector<int>(11, -1u/4));
        REP (i, 11) f[0][i] = 0;
        REP (i, sz(s))
        {
            for (int j = 9; j >= 0; --j)
            {
                f[i][j] = min(f[i][j], f[i][j + 1]);
            }
            for (int k = 1; k <= 10 && i + k <= sz(s); ++k)
            {
                auto word = s.substr(i, k);
                cout.flush();
                if (binary_search(all(words), word)) 
                {
                    REP (j, 11)
                        relax(f[i + k][min(j + k, 10)], f[i][j]);
                }
                else
                {
                    REP (y, k)
                    {
                        for (char cj = 'a'; cj <= 'z'; ++cj)
                        {
                            if (word[y] == cj) continue;
                            swap(word[y], cj);
                            if (binary_search(all(words), word))
                            {
                                REP (j, 11)
                                {
                                    if (j + y < 5) continue;
                                    relax(f[i + k][min(k - y, 10)], f[i][j] + 1);
                                }
                            }
                            else
                            {
                                for (int x = 0; x + 5 <= y; ++x)
                                {
                                    for (char ci = 'a'; ci <= 'z'; ++ci)
                                    {
                                        if (word[x] == ci) continue;
                                        swap(word[x], ci);
                                        if (binary_search(all(words), word))
                                        {
                                            REP (j, 11)
                                            {
                                                if (j + x < 5) continue;
                                                relax(f[i + k][min(k - y, 10)], f[i][j] + 2);
                                            }
                                        }
                                        swap(word[x], ci);
                                    }
                                }
                            }
                            swap(word[y], cj);
                        }
                    }
                }
            }
        }
        cout << *min_element(all(f.back())) << endl;
	}
};

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
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
