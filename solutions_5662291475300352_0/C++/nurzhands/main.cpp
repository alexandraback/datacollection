#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define ms(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef pair<int,int> pt;

const int N = 1<<17;
const int inf = 1<<30;

int d[10],h[10],m[10];
double d1,d2,m1,m2,t1,t2;

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T;
	scanf("%d\n", &T);
	for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> d[i] >> h[i] >> m[i];
			sum += h[i];
		}
		int ans = 0;
		if (sum == 2) {
			if (n == 1) {
				d1 = d2 = d[0];
				m1 = m[0];
				m2 = m1 + 1;
			} else {
				d1 = d[0];
				d2 = d[1];
				m1 = m[0];
				m2 = m[1];
			}
			cerr << d1 << " " << m1 << " " << d2 << " " << m2 << endl;
			t1 = (360.0-d1)*m1/360;
			t2 = (360.0-d2)*m2/360;
			//cerr << t1 << " " << t2 << endl;
			if (t1 > t2) {
				swap(t1, t2);
				swap(d1, d2);
				swap(m1, m2);
			}
			cerr << t1 << " " << m2 << endl << endl;
			if (t2 >= m1+t1) ans = 1;
		}
		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}