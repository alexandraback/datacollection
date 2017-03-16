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
#define LLD "%I64d"
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

int a[111][111], b[111][111];
pair <int, pii> p[10100];

inline void solve(int test){
	printf("Case #%d: ", test);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			b[i][j] = 100;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			p[i * m + j] = mp(a[i][j], mp(i, j));
		}
	}
	sort(p, p + n * m);
	reverse(p, p + n * m);
	for(int i = 0; i < n * m; i++){
		bool good = true;
		for(int j = 0; j < m; j++){
			if(min(b[p[i].sc.fs][j], p[i].fs) < a[p[i].sc.fs][j]){
				good = false;
				break;
			}
		}
		if(good){
			for(int j = 0; j < m; j++){
				b[p[i].sc.fs][j] = min(b[p[i].sc.fs][j], p[i].fs);
			}
			continue;
		}
		good = true;
		for(int j = 0; j < n; j++){
			if(min(b[j][p[i].sc.sc], p[i].fs) < a[j][p[i].sc.sc]){
				good = false;
				break;
			}
		}
		if(good){
			for(int j = 0; j < n; j++){
				b[j][p[i].sc.sc] = min(b[j][p[i].sc.sc], p[i].fs);
			}
			continue;
		}
		printf("NO\n");
		return;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] != b[i][j]){
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n");
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
		cerr << "test " << i << " of " << t << endl;
	}
	return 0;
}
