#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define TR(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define PB push_back
#define MP make_pair
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXK = 10;

const int MAXN = 1000;
const int MAXE = 1000;
long long f[MAXN][MAXE];
int E, R, n;
int value[MAXN];

int main() {
	int test;
	cin >> test;
	for (int cas = 1; cas <= test; ++cas) {
		cin >> E >> R >> n;
		REP(i, n)
			scanf("%d",&value[i]);

		REP(i, n+1) REP(e, E+1) f[i][e] = -1;
		f[0][E] = 0;
		for (int i = 0; i < n; ++i) {
			for (int e = 0; e <= E; ++e)
			if (f[i][e] != -1) {
				for (int x = 0; x <= e; ++x) {
					int up = min(E, e-x+R);
					f[i+1][up] = max(f[i+1][up], f[i][e] + x * value[i]);
				}
			}
		}

		long long ans = 0;
		for (int e = 0; e <= E; ++e)
			ans = max(ans, f[n][e]);

		printf("Case #%d: ",cas);
		cout << ans << endl;
	}
}



