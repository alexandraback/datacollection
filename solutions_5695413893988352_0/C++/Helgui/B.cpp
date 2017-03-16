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

vector<PII> qm;

void solve(string &s1, string &s2) {
	int cnt = 0;
	qm.clear();
	
	for(int i = 0; i < (int)s1.size(); ++i) {
		if (s1[i] == '?') {
			++cnt;
			qm.emplace_back(0, i);
		}
	}

	for(int i = 0; i < (int)s2.size(); ++i) {
		if (s2[i] == '?') {
			++cnt;
			qm.emplace_back(1, i);
		}
	}

	if (cnt == 0)
		return;
	int p = 1;
	for(int i = 0; i < cnt; ++i) {
		p *= 10;		
	}
	int ans = 1000000000;
	int a1 = 0;
	int a2 = 0;
	int ansmask = -1;
	for(int i = 0; i < p; ++i) {
		int t = i;
		for(int j = 0; j < cnt; ++j) {
			if (qm[j].x == 0) {
				s1[qm[j].y] = '0' + (t % 10);
			} else {
				s2[qm[j].y] = '0' + (t % 10);
			}
			t /= 10;
		}
		int t1 = stoi(s1);
		int t2 = stoi(s2);
		if (abs(t1 - t2) < ans) {
			ans = abs(t1 - t2);
			a1 = t1;
			a2 = t2;
			ansmask = i;
		} else {
			if (abs(t1 - t2) == ans) {
				if (t1 < a1 || (t1 == a1 && t2 < a2)) {
					a1 = t1;
					a2 = t2;
					ansmask = i;
				}
			}
		}
	}
	int t = ansmask;
	for(int j = 0; j < cnt; ++j) {
		if (qm[j].x == 0) {
			s1[qm[j].y] = '0' + (t % 10);
		} else {
			s2[qm[j].y] = '0' + (t % 10);
		}
		t /= 10;
	}
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
	string s1, s2;
	for(int test = 1; test <= T; ++test) {
		cin >> s1 >> s2;
		solve(s1, s2);
		cout << "Case #" << test << ": " << s1 << ' ' << s2 << endl; 
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