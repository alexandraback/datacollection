#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second

void solve(double c, double f, double x){
	double t = 0, a = 0, v = 2;
	while (a < x) {
		if (c / v + x / (v + f) < x / v) {
			a = 0;
			t += c / v;
			v += f;
		}
		else {
			a = x;
			t += x / v;
		}
	}
	cout << setprecision(7) << fixed << t << endl;
}

int main() {
	#ifdef _TEST_
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	double c, f, x;
	for (int i = 0; i < t; i ++){
		cin >> c >> f >> x;
		cout << "Case #" << i + 1 << ": ";
		solve(c, f, x);
	}
	return 0;
}
