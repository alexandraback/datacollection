#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }
#define mp(x, y) make_pair(x, y)

int a, b;
int cnt[10000000];

void solve(int t) {
	memset(cnt, 0, sizeof(cnt));
	
	for(int n = a; n <= b; n++) {
		int m = n, maxm = n;
		
		int s = 0, t = 1;
		while(m) {
			s++;
			m/=10;
			t*=10;
		}
		t/=10;
		
		m = n;
		for(int i = 0; i < s; i++) {
			m = 10*(m%t) + (m/t);
			maxm = max(maxm, m);
		}
		
//		cout << n << ' ' << maxm << endl;
		cnt[maxm]++;
	}
	
	int res = 0;
	for(int i = 1; i < 10000000; i++) {
		if(cnt[i]) {
			res += ((cnt[i]-1)*cnt[i])/2;
		}
	}
	
	cout << "Case #" << t << ": " << res << endl;
}

int main() {
	freopen("small.in", "r", stdin);
	freopen("small.out", "w", stdout);
	
	int T; scanf("%d\n", &T);
	for(int t = 1; t <= T; t++) {
		cin >> a >> b;
		solve(t);
	}
}
