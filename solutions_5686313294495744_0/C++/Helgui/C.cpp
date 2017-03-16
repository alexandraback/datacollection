#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <utility>

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)
#define _with_file
#define TASK ""
#define forn(i, n) for(int i = 0; i < (int)n; ++i)

void quit(); 

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
#ifdef local
typedef double ld;
#else
typedef long double ld;
#endif
typedef pair <int, int> PII;
typedef pair <i64, i64> PII64;
typedef pair <ld, ld> PLL;

const ld PI = acos(-1);
const ld EPS = 1e-10;
double __t;

vector<PII> a;
bool b[32];

map<string, int> fw;
map<string, int> sw;

int fc;
int sc;

int indexOf(const string &s, map<string, int> & w, int &c) {
	auto it = w.find(s);
	if (it != w.end())
		return it -> y;
	w.emplace(s, c);
	++c;
	return c - 1;
}

inline bool check(int n) {
	set <int> f;
	set <int> s;
	for(int i = 0; i < n; ++i) {
		if (!b[i]) {
			f.insert(a[i].x);
			s.insert(a[i].y);
		}	
	}
	for(int i = 0; i < n; ++i) {
		if (!b[i])
			continue;
		if (f.count(a[i].x) == 0 || s.count(a[i].y) == 0)
			return 0;	
	}
	return 1;
}	

int main()
{
	#ifdef local
		__t = clock();
		#ifndef _with_files
			freopen("z.in", "rt", stdin);
			freopen("z.out", "wt", stdout);
		#endif
	#endif
	#ifdef _with_files
		freopen(TASK".in", "rt", stdin);
		freopen(TASK".out", "wt", stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int test = 1; test <= T; ++test) {
		int n;
		cin >> n;
		a.clear();
		fw.clear();
		sw.clear();
		sc = 0;
		fc = 0;
		string s1, s2;
		for(int i = 0; i < n; ++i) {
			cin >> s1 >> s2;
			a.emplace_back(indexOf(s1, fw, fc), indexOf(s2, sw, sc));
		}

		int cnt;
		int ans = 0;
		int ansm = 0;
		for(int i = 0; i < (1 << n); ++i) {
			cnt = 0;
			for(int j = 0; j < n; ++j) {
				if (i & (1 << j)) {
					b[j] = 1;
					++cnt;
				} else {
					b[j] = 0;
				}
			}
			if (check(n)) {      
				if (cnt > ans) {
					ans = cnt;
					ansm = i;
				}
			}
		}
		//cerr << ansm << endl;
		cout << "Case #" << test <<": " << ans << endl;
	}
	quit();
}

void quit()
{
	#ifdef local
		cerr << "\nTOTAL TIME: "<< (clock() - __t)/1000.0 << " s\n";
	#endif
	exit(0);		
}