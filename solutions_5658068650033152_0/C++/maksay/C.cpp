#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define VI vector<int>
#define inf 1000000000
#define L(s) ((int)(s).size())
#define x first 
#define y second
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define all(s) (s).begin(), (s).end()
int t, n, m, k, res;
int f[22][22][22][444];
int ans[22][22][444];
int main() {

	FILE *fp = fopen("data.txt", "r");

	while(fscanf(fp, "%d%d%d%d", &n, &m, &k, &res) > 0) {
		ans[n][m][k] = res;
	}
 
	for(int i = 1; i <= 20; ++i)
		for(int j = 1; j <= 20; ++j) 
			for(int k = 1; k <= i * j; ++k) {
				ans[i][j][k] = min(ans[i][j][k], k);
				ans[i + 1][j][k] = min(ans[i + 1][j][k], ans[i][j][k]);
				ans[i][j + 1][k] = min(ans[i][j + 1][k], ans[i][j][k]);
			}

	freopen("C-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for(int tc = 1; tc <= t; ++tc) {
		cin >> n >> m >> k;
		if (n == 1 || m == 1 || k == 1) {
			cout << "Case #" << tc <<": " << k <<  endl;
		} else
		cout << "Case #" << tc <<": " << min(ans[n][m][k], k) <<  endl;
	}

//	freopen("input.txt", "r", stdin);
//	freopen("data.txt", "w", stdout);
//	//cin >> t;
//	memset(ans, 63, sizeof(ans));
//	for(int m = 1; m <= 20; ++m) {
//		cerr << "M = " << m << endl;
////	}
////	for(int tc = 1; tc <= t; ++tc) {
////		cin >> n >> m >> k;
//		n = 20;
//		memset(f, 63, sizeof(f));
//		for(int st = 0; st < m; ++st) {
//			for(int fn = st; fn < m; ++fn) {
//				f[0][st][fn][fn - st + 1] = fn - st + 1;
//				ans[1][m][fn - st + 1] = min(ans[1][m][fn - st + 1], fn - st + 1);
//			}
//		}
////		int ans = k;
//		for(int i = 0; i < n - 1; ++i) {
//			cerr << i << endl;
//			for(int st = 0; st < m; ++st) {
//				for(int fn = st; fn < m; ++fn) {
//					for(int put = 1; put <= n * m; ++put) {
//						if (f[i][st][fn][put] < inf) {
//							
//							int val = f[i][st][fn][put];
//
//							for(int s1 = 0; s1 < m; ++s1) {
//								for(int f1 = s1; f1 < m; ++f1) {
//									if (s1 <= st + 1 && f1 >= fn - 1) {
////										if (put + f1 - s1 + 1 == k) {
////											ans = min(ans, val + f1 - s1 + 1);
////										}
//										ans[i + 2][m][put + f1 - s1 + 1] = min(ans[i + 2][m][put + f1 - s1 + 1], val + f1 - s1 + 1);
//										for(int p1 = s1; p1 <= f1; ++p1) {
//											for(int p2 = p1 + 1; p2 <= f1; ++p2) {
//												f[i + 1][p1][p2][put + f1 - s1 + 1] = min(f[i + 1][p1][p2][put + f1 - s1 + 1], val + f1 - s1 + 1);
//											}
//										}
//									}
//								}
//							}
//
//							for(int s1 = 0; s1 < m; ++s1)
//								for(int f1 = s1; f1 < m; ++f1)
//									if (f1 >= st - 1 && s1 <= st + 1)
//									for(int s2 = f1 + 2; s2 < m; ++s2)
//										for(int f2 = s2; f2 < m; ++f2)
//										if (f2 >= fn - 1 && s2 <= fn + 1) {
//											for(int p1 = s1; p1 <= f1; ++p1) {
//												for(int p2 = s2; p2 <= f2; ++p2) {
//													f[i + 1][p1][p2][put + f2 - s1 + 1] = min(f[i + 1][p1][p2][put + f2 - s1 + 1], val + f1 - s1 + 1 + f2 - s2 + 1);
//												}
//											}
//										}
//						}
//					}
//				}
//			}
//		}
//
////		cout << "Case #" << tc <<": " << ans <<  endl;
//	}
//
//	for(n = 1; n <= 20; ++n)
//			for(m = 1; m <= 20; ++m)
//				for(k = 1; k <= n * m; ++k)
//					cout << n << " " << m << " " << k << " " << ans[n][m][k] << endl;
}
	