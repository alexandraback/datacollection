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

const ll inf = ll(1e17);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));

int sz[111];
ll d[111][111];

inline void solve(int test){
	printf("Case #%d: ", test);
	int A, n;
	scanf("%d %d", &A, &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &sz[i]);
	}
	sort(sz, sz + n);
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			d[i][j] = -inf;
		}
	}
	d[0][0] = A;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= n; j++){
			if(d[i][j] == -inf){
				continue;
			}
			d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j]);
			if(d[i][j] > sz[i]){
				d[i + 1][j] = max(d[i + 1][j], min(d[i][j] + sz[i], inf));
			}
			if(j < n && d[i][j] > 1){
				d[i][j + 1] = max(d[i][j + 1], min(2 * d[i][j] - 1, inf));
			}
		}
	}
	int ans = -1;
	for(int i = 0; i <= n; i++){
		if(d[n][i] != -inf){
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
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
