#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <ctime>
#include <stack>
#include <map>
#include <set>
#if __cplusplus > 199711L
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//	tree<key, mapped = null_type, cmp = less<key>, rb_tree_tag, tree_order_statistics_node_update> name;
//	order_of_key
//	find_by_order
#endif

using namespace std;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a) < 0 ? -(a) : (a))
#define sqr(a) ((a) * (a))

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double eps = 1e-9;
const int mod = (int)1e+9 + 7;
const double pi = acos(-1.);
const int maxn = 100100;



int main() {

	#ifdef SOL
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	#else
	{
		srand(time(0));
		const string file = "";
		if(!file.empty()) {
			freopen((file + ".in").c_str(), "r", stdin);
			freopen((file + ".out").c_str(), "w", stdout);
		}
	}
	#endif

	int t;
	scanf("%d", &t);
	for(int test = 1; t--; test++) {
		printf("Case #%d: ", test);
		ll n, m;
		scanf("%lld%lld", &n, &m);
		if(m > (1ll << (n - 2))) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("POSSIBLE\n");
		int ans[52][52];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(i < j) ans[i][j] = 1;
			}
			if(i) ans[i][n - 1] = 0;
		}
		m--;
		int id = 1;
		while(m) {
			if(m & 1) {
				ans[id][n - 1] = 1;
			}
			m >>= 1;
			id++;
		}

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				printf("%d", ans[i][j]);
			}
			printf("\n");
		}

	}

	#ifdef SOL
	{
		fflush(stdout);
		fprintf(stderr, "%.3lf ms\n", 1000. * clock() / CLOCKS_PER_SEC);
		fflush(stderr);
	}
	#endif
	return(0);
}
