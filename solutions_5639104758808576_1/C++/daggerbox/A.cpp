

#if 1

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;
typedef int64_t int64;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;
#define mp make_pair
#define X first
#define Y second  

static void solve();

int main() {
	freopen("A.in.txt","r",stdin);
	freopen("A.out.txt","w",stdout);
	int test_case;
	cin >> test_case;
	for (int t = 1; t <= test_case; ++t) {
		cout << "Case #" << t << ": ";
		solve();
		cout << '\n';
	}
	return 0;
}

static void solve() {
	int smax;
	cin >> smax;
	vector<int> shyness;
	char c;
	for (int i = 0; i <= smax; i++) {
		cin >> c;
		shyness.push_back(int(c - '0'));
	}
	int nc = 0;
	int nf = 0;

	for (int i = 0; i <= smax; i++) {
		if (nc < i) {
			nf += i - nc;
			nc = i;
		}
		nc += shyness[i];
	}
	cout << nf;
}

#endif

