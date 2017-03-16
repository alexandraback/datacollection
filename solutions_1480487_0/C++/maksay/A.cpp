#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>
#include <set>
using namespace std;
#define L(s) (int)((s).size())
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define x first
#define y second
#define inf 1000000000
#define all(s) (s).begin(), (s).end()
#define ll long long
#define VI vector<int>
#define ull unsigned ll
int t, n, s[222];
double ans[222];
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for(int  num = 1; num <= t; ++num) {
		cin >> n;
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			cin >> s[i];
			sum += s[i];
		}

		for(int i = 0; i < n; ++i) {
			double low = 0, high = 1;
			for(int iter = 0; iter < 1000; ++iter) {
				double mid = (high + low) / 2.;
				double others = 0;
				for(int j = 0; j < n; ++j) {
					if (j != i) {
						others += max(0., (double)s[i] + mid * sum - s[j]);
					}
				}
				if (mid + others / sum < 1) {
					low = mid;
				} else high = mid;
			}
			ans[i] = high * 100;
		}
		printf("Case #%d:", num);
		for(int i = 0; i < n; ++i) {
			printf(" %0.15lf", ans[i]);
		}
		printf("\n");
	}
}
