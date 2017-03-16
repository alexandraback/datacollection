#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <list>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <valarray>
#include <ctime>
#include <set>
#include <sstream>

using namespace std;

typedef pair<int, int> pi;
typedef pair<pi, int> ppi;
typedef unsigned long long ull;
typedef vector<int> vi;

#define x first
#define y second
#define mp make_pair


void solution() {	
	ull ac[100] = {0};
	int a[100] = {0};
	ull bc[100] = {0};
	int b[100] = {0};
		
	int n = 0, m = 0;

	int tn, tm;
	scanf("%d%d", &tn, &tm);
	
	for (int i = 0; i < tn; ++i) {
		ull c;
		int t;
		scanf("%llu%d", &c, &t);
		if (n && a[n - 1] == t) {
			ac[n - 1] += c;
		} else {			
			a[n] = t;
			ac[n] = c;
			++n;
		}
	}

	for (int i = 0; i < tm; ++i) {
		ull c;
		int t;
		scanf("%llu%d", &c, &t);
		if (m && b[m - 1] == t) {
			bc[m - 1] += c;
		} else {			
			b[m] = t;
			bc[m] = c;
			++m;
		}
	}

	
	while (n != 3) {
		ac[n] = 0;
		a[n] = 1000;
		++n;
	}
	ull best = 0;
	for (int p1 = 0; p1 <= m; ++p1) {
		for (int p2 = p1; p2 <= m; ++p2) {
			ull s1 = 0, s2 = 0, s3 = 0;
			for (int i = 0; i < p1; ++i) {
				if (b[i] == a[0]) {
					s1 += bc[i];
				}
			}

			for (int i = p1; i < p2; ++i) {
				if (b[i] == a[1]) {
					s2 += bc[i];
				}
			}

			if (p1) {
				if (b[p1 - 1] == a[1] && b[p1 - 1] == a[0]) {
					s2 += min(bc[p1 - 1], s1 - min(s1, ac[0]));
				}
			}

			for (int i = p2; i < m; ++i) {
				if (b[i] == a[2]) {
					s3 += bc[i];
				}
			}

			if (p2) {
				if (p1 == p2) {
					if (b[p2 - 1] == a[2] && b[p2 - 1] == a[0]) {
						s2 += min(bc[p2 - 1], s1 - min(s1, ac[0]));
						if (min(bc[p2 - 1], s1 - min(s1, ac[0])) > 0) {
							int t = 0;
						}
					}
				} else {
					if (b[p2 - 1] == a[2] && b[p2 - 1] == a[1]) {
						s2 += min(bc[p2 - 1], s2 - min(s2, ac[1]));
					}
				}

			}

			ull res = min(s1, ac[0]) + min(s2, ac[1]) + min(s3, ac[2]);
			best = max(res, best);
		}
	}
	cout << best << endl;
}

int main() {

	//freopen("in.in", "rt", stdin);
	//freopen("out.out", "wt", stdout);

	/*freopen("A-small.in", "rt", stdin);
	freopen("A-small.out", "wt", stdout);*/

	//freopen("A-large.in", "rt", stdin);
	//freopen("A-large.out", "wt", stdout);

	/*freopen("B-small.in", "rt", stdin);
	freopen("B-small.out", "wt", stdout);*/

	//freopen("B-large.in", "rt", stdin);
	//freopen("B-large.out", "wt", stdout);


	freopen("C-small.in", "rt", stdin);
	freopen("C-small.out", "wt", stdout);

	//freopen("C-large.in", "rt", stdin);
	//freopen("C-large.out", "wt", stdout);
	
	int t = 0;
	scanf("%d\n", &t);
	for (int tt = 0; tt < t; tt++) {
		printf("Case #%d: ", tt + 1);
		solution();
	}

	return 0;
}