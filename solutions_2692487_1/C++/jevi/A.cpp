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
typedef pair<int,int> pii;
typedef vector<vector<int> > graph;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

#define MAXN 105

int TESTS, CASE;
int a, n, b[MAXN];

void solve() {
	cout << "Case #" << CASE << ": ";
	
	sort(b,b+n);
	
	int i = 0;
	while(i < n && a > b[i]) {
		a += b[i];
		i++;
	}
	
	if(a == 1) {
		cout << n << endl;
		return;
	}
	
	int ans = 2000000000;
	for(int j = i; j <= n; j++) {
		int cnt = 0;
		int ta = a;
		for(int k = i; k < j; k++) {
			if(ta <= b[k]) {
				ta += ta-1;
				cnt++;
				k--;
			} else {
				ta += b[k];
			}
		}
		cnt += n-j;
		ans = min(ans, cnt);
	}
	
	cout << ans << endl;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	cin >> TESTS;
	for(CASE = 1; CASE <= TESTS; CASE++) {
		scanf("%d %d", &a, &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", b+i);
		}
		solve();
	}
}
