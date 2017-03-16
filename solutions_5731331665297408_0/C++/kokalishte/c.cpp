#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>

#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;
inline long double get_time(){   
	return (long double)clock()/CLOCKS_PER_SEC;
};


string solve() {
	stringstream res;
	int n, m;
	cin >> n >> m;
	pair <int, int> zips[55];
	for (int i = 0; i < n; ++i) {
		cin >> zips[i].first;
		zips[i].second = i;
	}
	vector <int> neibs[51];
	for (int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		neibs[from-1].push_back(to-1);
		neibs[to-1].push_back(from-1);
	}
	sort(zips, zips+n);
	map <int, int> zipsmap;
	for (int i  = 0;i<n;++i) zipsmap[zips[i].second]=i;
	bool vis[51]; memset(vis, 0, sizeof(vis));
	map<int, int> fathers;
	int who = zips[0].second;
	res << zips[0].first;
	vis[who] = 1;
	fathers[who]=-1;
	vector <pair <int, int> > possible_moves;
	while (who != -1) {
		int min1 = 999999999;
		int mini = -1;
		for (int i = 0; i < neibs[who].size(); ++i) {
			int neib = neibs[who][i];
			if (!vis[neib] && min1 > zips[zipsmap[neib]].first) {
				min1 = zips[zipsmap[neib]].first;
				mini = neib;
			} else if (!vis[neib]) {
				possible_moves.push_back(make_pair(zips[zipsmap[neib]].first, neib));
			}
		}
		for (int i = 0; i < possible_moves.size(); ++i) {
			if (!vis[possible_moves[i].second] && min1 > possible_moves[i].first) {
				bool ima_nevidqn_sused = false;
				for (int j = 0; j < neibs[possible_moves[i].second].size(); ++j) {
					if (vis[neibs[possible_moves[i].second][j]] == 0) {
						ima_nevidqn_sused = true;
						break;
					}
				}

				if( ima_nevidqn_sused) {
					min1 = possible_moves[i].first;
					mini = possible_moves[i].second;
				}
			}
		}
		if (mini != -1) {
			vis[mini]=1;
			fathers[mini]=who;
			who = mini;
			res << min1;
		} else {
			who = fathers[who];
		}
	}

	return res.str();
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	//program
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		printf("Case #%d: %s\n", test, solve().c_str());
	}
	//end program
	return 0;
}




