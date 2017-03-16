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

int n, x, y, lx, ly, rx, ry, lev;
double ans;

void gen(int step, double ver = 1, bool fl = false){
	if(step >= n){
		if(fl){
			ans += ver;
		}
		return;
	}
	if(lx < 0 && rx > 0){
		if(lx == x && ly == y){
			lx++;
			ly++;
			gen(step + 1, ver / 2, true);
			lx--;
			ly--;
		}
		else{
			lx++;
			ly++;
			gen(step + 1, ver / 2, fl);
			lx--;
			ly--;
		}
		if(rx == x && ry == y){
			rx--;
			ry++;
			gen(step + 1, ver / 2, true);
			rx++;
			ry--;
		}
		else{
			rx--;
			ry++;
			gen(step + 1, ver / 2, fl);
			rx++;
			ry--;
		}
		return;
	}
	if(lx < 0){
		if(lx == x && ly == y){
			lx++;
			ly++;
			gen(step + 1, ver, true);
			lx--;
			ly--;
		}
		else{
			lx++;
			ly++;
			gen(step + 1, ver, fl);
			lx--;
			ly--;
		}
		return;
	}
	if(rx == x && ry == y){
		rx--;
		ry++;
		gen(step + 1, ver, true);
		rx++;
		ry--;
	}
	else{
		rx--;
		ry++;
		gen(step + 1, ver, fl);
		rx++;
		ry--;
	}
}

inline void solve(int test){
	printf("Case #%d: ", test);
	scanf("%d %d %d", &n, &x, &y);
	lev = 0;
	int sz = 1, cur = 1;
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
	ans = 0;
	lx = -2 * lev - 2;
	ry = 0;
	rx = 2 * lev + 2;
	ry = 0;
	gen(0);
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
