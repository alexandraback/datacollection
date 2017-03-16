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

#define endl '\n'

const int MAXN = 1005;

int n;
char a[MAXN];

void solve() {
	int ans = 0;
	int sum = 0;
	for(int i = 0; i <= n; i++) {
		a[i] -= '0';
		if(a[i] > 0) {
			ans = max(ans, i-sum);
		}
		sum += a[i];
	}
	printf("%d\n", ans);
}

int main() {
	freopen("A-input.in", "r", stdin);
	freopen("A-output.out", "w", stdout);
	int t; scanf("%d", &t);
	for(int c = 1; c <= t; c++) {
        printf("Case #%d: ", c);
		scanf("%d %s", &n, a);
		solve();
	}
}
