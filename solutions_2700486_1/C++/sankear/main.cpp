#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define LLD "%lld"
#else
#define eprintf(...) 42
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef complex <double> tc;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

bool lgood[3030], rgood[3030];
double d[3030][3030];

inline void solve(int test){
	printf("Case #%d: ", test);
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	int sz = 1, cur = 1, lev = 0;
	while(sz + cur + 4 <= n){
		sz += cur + 4;
		cur += 4;
		lev++;
	}
	if(sz == n){
		int vy = 2 * lev + 1;
		if(x < 0){
			if(y <= vy + x){
				printf("%.10lf\n", double(1));
				return;
			}
			printf("%.10lf\n", double(0));
			return;
		}
		if(y <= vy - x){
			printf("%.10lf\n", double(1));
			return;
		}
		printf("%.10lf\n", double(0));
		return;
	}
	int vy = 2 * lev + 1;
	if(x < 0 && y <= vy + x){
		printf("%.10lf\n", double(1));
		return;
	}
	if(x >= 0 && y <= vy - x){
		printf("%.10lf\n", double(1));
		return;
	}
	n -= sz;
	if(n > 3000){
		cerr << "FUCK " << n << endl;
		while(true);
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= i; j++){
			d[i][j] = 0;
		}
	}
	d[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			int lx = -2 * lev - 2 + j, rx = 2 * lev + 2 - (i - j);
			if(lx < 0 && rx > 0){
				d[i + 1][j + 1] += d[i][j] / 2;
				d[i + 1][j] += d[i][j] / 2;
				continue;
			}
			if(lx < 0){
				d[i + 1][j + 1] += d[i][j];
				continue;
			}
			d[i + 1][j] += d[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		int cx = -2 * lev - 2 + i - 1, cy = i - 1;
		lgood[i] = (lgood[i - 1] | (cx == x && cy == y));
	}
	for(int i = 1; i <= n; i++){
		int cx = 2 * lev + 2 - i + 1, cy = i - 1;
		rgood[i] = (rgood[i - 1] | (cx == x && cy == y));
	}
	double ans = 0;
	for(int i = 0; i <= n; i++){
		int lx = -2 * lev - 2 + i - 1, rx = 2 * lev + 2 - (n - i) + 1;
		if((i > 0 && lx >= 0) || (n - i > 0 && rx <= 0)){
			continue;
		}
		if(lgood[i] || rgood[n - i]){
			ans += d[n][i];
		}
	}
	printf("%.10lf\n", ans);
}

int main(int argc, char **argv){
	if(argc > 1){
		freopen(argv[1], "r", stdin);
		freopen("ans.txt", "w", stdout);
	}
	else{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		solve(i + 1);
		cerr << "test " << i + 1 << endl;
	}
	return 0;
}
