#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define LL long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
int a[111][111],cur[111][111];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n,m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				cur[i][j] = 100;
			}
		}
		for (int i = 0; i < n; i++) {
			int ma = 0;
			for (int j = 0; j < m; j++) {
				ma = max(ma,a[i][j]);
			}
			for (int j = 0; j < m; j++) {
				cur[i][j] = min(cur[i][j],ma);
			}
		}
		for (int j = 0; j < m; j++) {
			int ma = 0;
			for (int i = 0; i < n; i++) {
				ma = max(ma,a[i][j]);
			}
			for (int i = 0; i < n; i++) {
				cur[i][j] = min(cur[i][j],ma);
			}
		}
		bool ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cur[i][j] != a[i][j]) {
					ok = false;
				}
			}
		}
		cout << "Case #" << t << ": ";
		if (ok) cout << "YES" << endl; else cout << "NO" << endl;
	}
	return 0;
}
