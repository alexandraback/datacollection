#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef long long lint;
const double eps = 1e-8;

inline bool eq(double a, double b) {
	return fabs(a - b) < eps;
}
inline bool lt(double a, double b) {
	return a < b && !eq(a, b);
}
inline bool ge(double a, double b) {
	return a > b || eq(a, b);
}

bool Solve(int test) {
	printf("Case #%d:", test);
	int n;
	int s[222];
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> s[i];
		sum += s[i];
	}
	
	for(int k = 0; k < n; k++) {
		double lo = 0, hi = 1;
		while(hi - lo > eps) {
			double med = 0.5 * (lo + hi);
			double score = s[k] + med * sum;
			double x = 0;
			for(int i = 0; i < n; i++) {
				if(i == k) continue;
				if(ge(s[i], score)) continue;
				x += score - s[i];
			}
			if(lt(x, (1.0 - med) * sum)) {
				lo = med;
			}
			else {
				hi = med;
			}
		}
		printf(" %.7lf", 100.0 * lo);
	}
	printf("\n");
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 0;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i)
		Solve(i);
	//*/while(Solve(++t));
	return 0;
}