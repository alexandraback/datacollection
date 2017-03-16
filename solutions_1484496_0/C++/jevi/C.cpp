#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }
#define mp(x, y) make_pair(x, y)

int n;
vector<int> s;

void solve(int test) {
	bool good = false;
	map<int, int> dp;
	int sum, m;
	for(m = 1; m < (1<<20); m++) {
		sum = 0;
		dp = map<int, int>();
		dp[0] = 0;
		for(int i = 0; i < n; i++) {
			if(m & (1<<i)) {
				sum += s[i];
			} else {
				vector<pair<int, int> > v;
				for(map<int, int>::iterator it = dp.begin(); it != dp.end(); it++) {
					v.push_back(mp(it->first + s[i], it->first));
				}
				for(int j = 0; j < (int)v.size(); j++) {
					dp[v[j].first] = v[j].second;
				}
			}
		}
		
		if(dp.find(sum) != dp.end()) {
			good = true;
			break;
		}
	}

	cout << "Case #" << test << ":" << endl;
	if(good) {
		for(int i = 0; i < n; i++) {
			if(m & (1<<i)) {
				cout << s[i] << ' ';
			}
		}
		cout << endl;
		int parent = dp[sum];
		while(sum != 0) {
			cout << sum-parent << ' ';
			sum = parent;
			parent = dp[sum];
		}
		cout << endl;
	} else {
		cout << "Impossible" << endl;
	}
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int testNumber; scanf("%d\n", &testNumber);
	for(int test = 1; test <= testNumber; test++) {
		cin >> n;
		s = vector<int>(n);
		for(int i = 0; i < n ; i++) {
			cin >> s[i];
		}
		solve(test);
	}
}
