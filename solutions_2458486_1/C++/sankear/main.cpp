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
const int N = 200;

int n;
vi cur, ncur, mem;
bool used[222];
vi v[222];
int t[222], lst[222], cnt[222], sz[222];
int a[222][444];

inline bool can(int num){
	for(int i = 0; i < sz(cur); i++){
		if(cur[i] == t[num]){
			return true;
		}
	}
	return false;
}

inline void modify(int num){
	ncur.clear();
	bool fl = false;
	for(int i = 0; i < sz(cur); i++){
		if(cur[i] == t[num]){
			if(!fl){
				fl = true;
				continue;
			}
		}
		ncur.pb(cur[i]);
	}
	for(int i = 0; i < sz[num]; i++){
		ncur.pb(a[num][i]);
	}
	cur = ncur;
}

inline bool check(){
	for(int i = 1; i <= N; i++){
		cnt[i] = 0;
		v[i].clear();
	}
	for(int i = 0; i < sz(cur); i++){
		cnt[cur[i]]++;
	}
	int need = 0;
	for(int i = 0; i < n; i++){
		if(!used[i]){
			need++;
			v[t[i]].pb(i);
		}
	}
	for(int i = 0; i < need; i++){
		int ans = -inf, best = -1;
		for(int j = 1; j <= N; j++){
			if(cnt[j] == 0){
				continue;
			}
			for(int z = 0; z < sz(v[j]); z++){
				cnt[j]--;
				for(int h = 0; h < sz[v[j][z]]; h++){
					cnt[a[v[j][z]][h]]++;
				}
				int res = 0;
				for(int h = 1; h <= N; h++){
					if(cnt[h] > 0){
						res += sz(v[h]) - (h == j);
					}
				}
				if(res > ans){
					ans = res;
					best = v[j][z];
				}
				for(int h = 0; h < sz[v[j][z]]; h++){
					cnt[a[v[j][z]][h]]--;
				}
				cnt[j]++;
			}
		}
		if(best == -1){
			return false;
		}
		for(int j = 1; j <= N; j++){
			if(cnt[j] == 0){
				continue;
			}
			ncur.clear();
			for(int z = 0; z < sz(v[j]); z++){
				if(v[j][z] == best){
					cnt[j]--;
					for(int h = 0; h < sz[v[j][z]]; h++){
						cnt[a[v[j][z]][h]]++;
					}
				}
				else{
					ncur.pb(v[j][z]);
				}
			}
			v[j] = ncur;
		}
	}
	return true;
}

inline void solve(int test){
	printf("Case #%d: ", test);
	int k;
	scanf("%d %d", &k, &n);
	cur.clear();
	for(int i = 0; i < k; i++){
		int cur_t;
		scanf("%d", &cur_t);
		cur.pb(cur_t);
	}
	for(int i = 0; i < n; i++){
		scanf("%d %d", &t[i], &sz[i]);
		for(int j = 0; j < sz[i]; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		used[i] = false;
	}
	for(int i = 0; i < n; i++){
		bool fl = false;
		for(int j = 0; j < n; j++){
			if(used[j] || !can(j)){
				continue;
			}
			mem = cur;
			modify(j);
			used[j] = true;
			if(check()){
				lst[i] = j;
				fl = true;
				break;
			}
			used[j] = false;
			cur = mem;
		}
		if(!fl){
			assert(i == 0);
			printf("IMPOSSIBLE\n");
			return;
		}
	}
	for(int i = 0; i < n; i++){
		if(i > 0){
			printf(" ");
		}
		printf("%d", lst[i] + 1);
	}
	printf("\n");
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
