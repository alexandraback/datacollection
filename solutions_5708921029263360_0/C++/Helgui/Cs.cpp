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

vector<tuple<int, int, int>> ans;
vector<tuple<int, int, int>> tmp;

int J, P, S, k;

bool u[3][3][3];
int jp[3][3];
int js[3][3];
int ps[3][3];

void bf() {
	if (tmp.size() > ans.size()) {
		ans = tmp;
	}
	for(int j = 0; j < J; ++j) {
		for(int p = 0; p < P; ++p) {
			for(int s = 0; s < S; ++s) {
				if (u[j][p][s])
					continue;
				if (jp[j][p] == k)
					continue;
				if (js[j][s] == k)
					continue;
				if (ps[p][s] == k)
					continue;
				if (tuple<int, int, int>(j, p, s) < tmp.back())
					continue;
				u[j][p][s] = 1;
				jp[j][p]++;
				js[j][s]++;
				ps[p][s]++;
				tmp.emplace_back(j, p, s);
				bf();
				jp[j][p]--;
				js[j][s]--;
				ps[p][s]--;
				u[j][p][s] = 0;
				tmp.pop_back();
			}
		}	
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
	int _T;
	cin >> _T;
	for(int _test = 1; _test <= _T; ++_test) {
		cin >> J >> P >> S >> k;
		memset(u, 0, sizeof(u));
		memset(js, 0, sizeof(js));
		memset(jp, 0, sizeof(jp));
		memset(ps, 0, sizeof(ps));
		tmp.clear();
		ans.clear();
		tmp.emplace_back(0, 0, 0);
		u[0][0][0] = 1;
		jp[0][0] = 1;
		ps[0][0] = 1;
		js[0][0] = 1;
		bf();
		cout << "Case #" << _test << ": " << ans.size() << endl;
		for(auto tup : ans) {
			cout << (get<0>(tup) + 1) << ' ' << (get<1>(tup) + 1) << ' '<< (get<2>(tup) + 1) << endl; 
		}
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