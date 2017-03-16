#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <utility>
#include <cstring>
#include <list>
#include <stack>
using namespace std;

typedef long long LL;
typedef unsigned int UI;

#define ft first
#define sd second

const int MAXN = 511111;
const int MOD = 1e9 + 7;
const double eps = 1e-6;
const LL MAXL = (LL)(0x7fffffffffffffff);
const int MAXI = 0x7fffffff;

bool mt[22][22];
int off[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("outputA.txt", "w", stdout);
#endif

	int T;
	cin >> T;
	for(int cases = 1; cases <= T; cases++){
		int n;
		vector<pair<double, double> > hikers;
		cin >> n;
		for(int i = 0; i < n; i++){
			LL h; double d, m;
			cin >> d >> h >> m;
			for(int j = 0; j < h; j++){
				hikers.push_back(make_pair(d, m + j));
			}
		}
		int nh = hikers.size();
		sort(hikers.begin(), hikers.end());
		int ans = 0;
		vector<int> res(nh, 0);
		for(int i = 0; i < nh; i++){
			int a = 0;
			for(int j = 0; j < nh; j++){
				if(i == j) continue;
				int ii = i, jj = j;
				if(hikers[ii].sd < hikers[jj].sd) swap(ii, jj);
				double x = hikers[ii].sd * (360 - hikers[ii].ft);
				double y = hikers[jj].sd * (720 - hikers[jj].ft);
				if(y <= x) a = 1;
			}
			res[i] = a;
		}
		for(int i = nh - 1; i >= 0; i--){
			for(int j = 0; j < i; j++){
				double x = hikers[j].sd * (360 - hikers[j].ft);
				double y = hikers[i].sd * (360 - hikers[i].ft);
				if(x >= y) res[j] = 1;
			}
		}
		for(int i = nh - 1; i >= 0; i--){
			ans += res[i];
		}
		printf("Case #%d: %lld\n", cases, ans);
	}
}