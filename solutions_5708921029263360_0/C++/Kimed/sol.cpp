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
		srand(time(0));
	}
	#else
	{
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
		int j, p, s, k;
		scanf("%d%d%d%d", &j, &p, &s, &k);
		vector<pair<pair<int, int>, int> > vc, ans;
		int acnt = 0;
		for(int x = 0; x < j; x++)
			for(int y = 0; y < p; y++)
				for(int z = 0; z < s; z++)
					vc.pb(mp(mp(x, y), z));
		for(int i = 0; i < 1000; i++) {
			int jp[10][10] = {0}, js[10][10] = {0}, ps[10][10] = {0};
			int cnt = 0;
			random_shuffle(vc.begin(), vc.end());
			for(int i = 0; i < (int)vc.size(); i++) {
				int xx = vc[i].fs.fs, yy = vc[i].fs.sc, zz = vc[i].sc;
				if(jp[xx][yy] + 1 > k) continue;
				if(js[xx][zz] + 1 > k) continue;
				if(ps[yy][zz] + 1 > k) continue;
				jp[xx][yy]++;
				js[xx][zz]++;
				ps[yy][zz]++;
				cnt++;
			}
			if(cnt > acnt) ans = vc, acnt = cnt;
		}

		int jp[10][10] = {0}, js[10][10] = {0}, ps[10][10] = {0};
		printf("Case #%d: %d\n", test, acnt);
		for(int i = 0; i < (int)ans.size(); i++) {
			int xx = vc[i].fs.fs, yy = vc[i].fs.sc, zz = vc[i].sc;
			if(jp[xx][yy] + 1 > k) continue;
			if(js[xx][zz] + 1 > k) continue;
			if(ps[yy][zz] + 1 > k) continue;
			jp[xx][yy]++;
			js[xx][zz]++;
			ps[yy][zz]++;
			printf("%d %d %d\n", xx + 1, yy + 1, zz + 1);
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
