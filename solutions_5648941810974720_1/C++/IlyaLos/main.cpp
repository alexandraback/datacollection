#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

const int N = 2000 + 13;
int n;
char s[N]; 

inline bool read()
{
	if (scanf ("%s", s) != 1)
		return false;
		
	n = int(strlen(s));

	return true;
}

int cnt[26];
int ansCnt[10];

inline void solve(int test)
{
	printf ("Case #%d: ", test + 1);
	
	forn (i, 26)
		cnt[i] = 0;
	forn (i, 10)
		ansCnt[i] = 0;
	
	forn (i, n)
		cnt[ s[i] - 'A' ]++;
		
	while (cnt['Z' - 'A'] > 0)
	{
		ansCnt[0]++;

		cnt['Z' - 'A']--;
		cnt['E' - 'A']--;
		cnt['R' - 'A']--;
		cnt['O' - 'A']--;
	}
	
	while (cnt['W' - 'A'] > 0)
	{
		ansCnt[2]++;
		
		cnt['T' - 'A']--;
		cnt['W' - 'A']--;
		cnt['O' - 'A']--;
	}
	
	while (cnt['U' - 'A'] > 0)
	{
		ansCnt[4]++;
		
		cnt['F' - 'A']--;
		cnt['O' - 'A']--;
		cnt['U' - 'A']--;
		cnt['R' - 'A']--;
	}
	
	while (cnt['X' - 'A'] > 0)
	{
		ansCnt[6]++;
		
		cnt['S' - 'A']--;
		cnt['I' - 'A']--;
		cnt['X' - 'A']--;
	}
	
	while (cnt['G' - 'A'] > 0)
	{
		ansCnt[8]++;
		
		cnt['E' - 'A']--;
		cnt['I' - 'A']--;
		cnt['G' - 'A']--;
		cnt['H' - 'A']--;
		cnt['T' - 'A']--;
	}
	
	while (cnt['O' - 'A'] > 0)
	{
		ansCnt[1]++;
		
		cnt['O' - 'A']--;
		cnt['N' - 'A']--;
		cnt['E' - 'A']--;
	}
	
	while (cnt['T' - 'A'] > 0)
	{
		ansCnt[3]++;
		
		cnt['T' - 'A']--;
		cnt['H' - 'A']--;
		cnt['R' - 'A']--;
		cnt['E' - 'A']--;
		cnt['E' - 'A']--;
	}
	
	while (cnt['F' - 'A'] > 0)
	{
		ansCnt[5]++;
		
		cnt['F' - 'A']--;
		cnt['I' - 'A']--;
		cnt['V' - 'A']--;
		cnt['E' - 'A']--;
	}
	
	while (cnt['S' - 'A'] > 0)
	{
		ansCnt[7]++;
		
		cnt['S' - 'A']--;
		cnt['E' - 'A']--;
		cnt['V' - 'A']--;
		cnt['E' - 'A']--;
		cnt['N' - 'A']--;
	}
	
	while (cnt['N' - 'A'] > 0)
	{
		ansCnt[9]++;
		
		cnt['N' - 'A']--;
		cnt['I' - 'A']--;
		cnt['N' - 'A']--;
		cnt['E' - 'A']--;
	}
	
	forn (i, 26)
		assert(cnt[i] == 0);
		
	forn (i, 10)
		forn (j, ansCnt[i])
			printf ("%d", i);
	puts("");
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));
	
	int testCnt;
	assert(scanf ("%d", &testCnt) == 1);

	forn (test, testCnt)
	{
		assert(read());
		solve(test);
	}

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}
