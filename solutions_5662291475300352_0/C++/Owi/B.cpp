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
				hikers.push_back(make_pair(m + j, d));
			}
		}
		sort(hikers.begin(), hikers.end());
		int ans = 0;
		if(hikers.size() == 2){
			double x = hikers[1].ft * (360 - hikers[1].sd);
			double y = hikers[0].ft * (720 - hikers[0].sd);
			//cout << x << " " << y << endl;
			if(y <= x) ans = 1;
		}
		printf("Case #%d: %lld\n", cases, ans);
	}
}