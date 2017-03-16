#include <vector>

#include <string>
#include <cstdio>

#include <algorithm>
#include <utility>
#include <cstring>

#include <map>
#include <set>

#include <cassert>

#include <numeric>
#include <bitset>

#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <cmath>
#include <complex>
#include <cstdlib>

#include <list>
#include <deque>
#include <queue>
#include <stack>

#include <functional>
#include <cctype>
#include <ctime>

using namespace std;

const int INF = 1000000000;

const double pi = acos(-1);
const double eps = 1e-8;
const long double ep = 1e-20;


#if 1
#define DBG(z) cerr << #z << ": " << (z) << endl
#define NEWL() cerr << endl;
#else
#define DBG(z)
#define NEWL()
#endif

#define fill(f, a) memset(f, a, sizeof(f))
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define for_each(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define next_int() ({int __t; scanf("%d", &__t); __t;})


bool guranteed(double p, int i, int x, const vector <int> &v) {
	double mysc = v[i] + x * p;
	vector <int> y;
	for (int j = 0; j < v.size(); ++j)
		if (i != j)
			y.push_back(v[j]);
	sort(all(y));
	double tot = 1 - p;
	for (int j = 0; j < y.size(); ++j) {
		if (y[j] >= mysc)
			continue;
		double myp = (mysc - y[j]) / x;
		tot -= myp;
	}
	return tot < 0;
}

vector <double> compute(const vector <int> &v) {
	int n = v.size();
	int x = 0;
	for (int i = 0; i < v.size(); ++i)
		x += v[i];
	vector <double> ans;
	for (int i = 0; i < n; ++i) {
		double low = 0, high = 1, mid;
		for (int j = 0; j < 100; ++j) {
			mid = (high + low) / 2.0;
			if (guranteed(mid, i, x, v))
				high = mid;
			else
				low = mid;
		}
		ans.push_back(high * 100);
	}
	return ans;
}
int main() {
	int t, n;
	t = next_int();
	for (int kase = 1; kase <= t; ++kase) {
		n = next_int();
		vector <int> v(n);
		for (int i = 0; i < n; ++i)
			v[i] = next_int();
		vector <double> ans = compute(v);
		printf("Case #%d:", kase);
		for (int i = 0; i < ans.size(); ++i)
			printf(" %lf", ans[i]);
		printf("\n");
	}
    return 0;
}



