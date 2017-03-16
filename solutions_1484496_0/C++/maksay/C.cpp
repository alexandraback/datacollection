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
int t, n, a[22];
int cost[1 << 20];
int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for(int num = 1; num <= t; ++num) {
		cerr << num << endl;
		cin >> n; for(int i = 0; i < n; ++i) cin >> a[i];
		for(int mask = 0; mask < (1 << n); ++mask) {
			int sum = 0;
			for(int i = 0; i < n; ++i) {
				if (mask & (1 << i)) sum += a[i];
			}
			cost[mask] = sum;
		}
		printf("Case #%d:\n", num);
		bool ok = 0;
		for(int mask = 0; mask < (1 << n) && !ok; ++mask) {
			for(int sub = mask & (mask - 1); sub && !ok; sub = (sub - 1) & mask) {
				if (cost[sub] == cost[mask ^ sub]) {
					ok = 1;

					bool was = 0;
					for(int i = 0; i < n; ++i) {
						if (sub & (1 << i)) {
							if (!was) was = 1; else printf(" ");
							printf("%d", a[i]);
						}
					}
					printf("\n");
					was = 0;
					for(int i = 0; i < n; ++i) {
						if ((mask ^ sub) & (1 << i)) {
							if (!was) was = 1; else printf(" ");
							printf("%d", a[i]);
						}
					}
					printf("\n");
				}
			}
		}
		if (ok) continue;
		printf("Impossible\n");
	}

}
