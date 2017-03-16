#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>

#define sz(a) int((a).size())
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define uniq(c) sort(all((c))); (c).resize(unique(all((c))) - (c).begin())
#define lobo(c, x) (int) (lower_bound(all((c)), (x)) - (c).begin())
#define upbo(c, x) (int) (upper_bound(all((c)), (x)) - (c).begin())
#define mii(a, b) if(b < a) a = b
#define maa(a, b) if(b > a) a = b

#define INF 2000000000
#define EPS 1e-5
#define PB push_back
#define MP make_pair
#define S second
#define F first
#define X first
#define Y second
#define DEBUG(x) printf("debugging.. %d\n", x);
#ifdef TEST
#define deb(...) fprintf(stderr, __VA_ARGS__)
#else 
#define deb(...)
#endif
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

string tobin(int x, int len) {
	string c;
	while(x) { c.PB(x%2+'0'); x /= 2; }
	while(sz(c) < len) c.PB('0');
	reverse(all(c));
	return c;
}
//------------------------------

const int MXN = 20;
int T, K, N;
int need[MXN+5];
vector <int> ck, keys[MXN+5], myKeys, ans;
int nkeys[(1 << MXN)+5][MXN+5];
int dp[(1 << MXN)+5], p[(1 << MXN)+5];

void init() {
	ck.clear(); myKeys.clear(); ans.clear();
	for(int i = 0; i < MXN; i++)
		keys[i].clear();
}

int f(int mask) {
	if(mask == (1 << N)-1) return 1;
	
	int &ret = dp[mask];
	if(ret != -1) return ret;
	
//	printf("f(%s)\n", tobin(mask, N).c_str());
	
	ret = 0;
	for(int i = 0; i < N; i++)
		if((mask & (1 << i)) == 0 && nkeys[mask][need[i]] > 0) {
			if(f(mask | (1 << i))) {
				p[mask] = i;
				return ret = 1;
			}
		}
	
	return ret;
}

void build(int mask) {
	if(p[mask] == -1) return;
	ans.PB(p[mask]+1);
	build(mask | (1 << p[mask]));
}

void solve() {
	for(int i = 0; i < N; i++) {
		if(!binary_search(all(ck), need[i])) {
			printf("IMPOSSIBLE\n");
			return;
		}
	}
	
	// ubah menjadi index ck
	for(int i = 0; i < K; i++) 
		myKeys[i] = lobo(ck, myKeys[i]);
	
	for(int i = 0; i < N; i++) {
		need[i] = lobo(ck, need[i]);
//		printf("chest[%d]->need(%d), has(", i, need[i]);
		for(int j = 0; j < sz(keys[i]); j++) {
			keys[i][j] = lobo(ck, keys[i][j]);
//			printf("{%d}", keys[i][j]);
		}
//		puts(")");
	}
	
	for(int mask = 0; mask < (1 << N); mask++) {
		int tmp[25] = {0};
		for(int i = 0; i < K; i++)
			tmp[myKeys[i]]++;
			
		for(int i = 0; i < N; i++)
			if((mask & (1 << i)) > 0) {
				tmp[need[i]]--;
				for(int j = 0; j < sz(keys[i]); j++)
					tmp[keys[i][j]]++;
			}
		
//		printf("mask=(%s), key[", tobin(mask, N).c_str());
		for(int i = 0; i < sz(ck); i++) {
			nkeys[mask][i] = tmp[i];
//			printf("{%d}", tmp[i]);
		}
//		puts("]");
	}
	
	memset(dp, -1, sizeof(dp));
	memset(p, -1, sizeof(p));
	
	int can = f(0);
	if(can == 0)	printf("IMPOSSIBLE\n");
	else {
		build(0);
		for(int i = 0; i < sz(ans); i++) {
			if(i > 0) printf(" ");
			printf("%d", ans[i]);
		}
		puts("");
	}
}

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; tc++) {
		init();
		scanf("%d%d", &K, &N);
		
		for(int i = 0; i < K; i++) {
			int key;
			scanf("%d", &key);
			
			myKeys.PB(key);
			ck.PB(key);
		}
		
		for(int i = 0; i < N; i++) {
			int nk;
			scanf("%d%d", &need[i], &nk);
			
			for(int j = 0; j < nk; j++) {
				int key;
				scanf("%d", &key);
				
				keys[i].PB(key);
				ck.PB(key);
			}
		}
		
		uniq(ck);
		
//		for(int i = 0; i < sz(ck); i++) printf("[%d]", ck[i]); puts("");
		
		printf("Case #%d: ", tc+1);
		solve();
	}
	
	return 0;
}
