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
const ll X = ll(2e5) + 3;
const ll X2 = 203;

int sz;
char s[4040];
int d[4040][7];
ll H[6000000];

inline void load(){
	freopen("garbled_email_dictionary.txt", "r", stdin);
	sz = 0;
	int max_len = 0;
	while(gets(s)){
		int len = strlen(s), all = (1 << len);
		max_len = max(max_len, len);
		for(int i = 0; i < all; i++){
			ll cur = 0;
			int last = -1;
			bool bad = false;
			for(int j = 0; j < len; j++){
				if((i & (1 << j)) != 0){
					cur = cur * X + s[j];
				}
				else{
					cur = cur * X + ' ';
					if(last != -1 && j - last < 5){
						bad = true;
						break;
					}
					last = j;
				}
			}
			if(bad){
				continue;
			}
			cur = cur * X + len * X2;
			H[sz++] = cur;
		}
	}
	sort(H, H + sz);
	cerr << "SIZE = " << sz << endl;
	sz = unique(H, H + sz) - H;
	cerr << "prepared SIZE = " << sz << " MAX_LEN = " << max_len << endl;
}

inline void solve(int test){
	printf("Case #%d: ", test);
	gets(s);
	int n = strlen(s);
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= 5; j++){
			d[i][j] = inf;
		}
	}
	d[0][5] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 5; j++){
			if(d[i][j] == inf){
				continue;
			}
			for(int z = 1; z <= 10 && i + z <= n; z++){
				int all = (1 << z);
				for(int h = 0; h < all; h++){
					int last = -1, cnt = 0;
					ll cur = 0;
					bool bad = false;
					for(int t = 0; t < z; t++){
						if((h & (1 << t)) != 0){
							cur = cur * X + s[i + t];
						}
						else{
							cur = cur * X + ' ';
							cnt++;
							if(last == -1 && t + j + 1 < 5){
								bad = true;
								break;
							}
							if(last != -1 && t - last < 5){
								bad = true;
								break;
							}
							last = t;
						}
					}
					if(bad){
						continue;
					}
					cur = cur * X + z * X2;
					int pos = lower_bound(H, H + sz, cur) - H;
					if(pos < 0 || pos >= sz || H[pos] != cur){
						continue;
					}
					int ni = i + z, nj;
					if(last == -1){
						nj = min(j + z, 5);
					}
					else{
						nj = min(z - last - 1, 5);
					}
					d[ni][nj] = min(d[ni][nj], d[i][j] + cnt);
				}
			}
		}
	}
	int ans = inf;
	for(int i = 0; i <= 5; i++){
		ans = min(ans, d[n][i]);
	}
	printf("%d\n", ans);
}

int main(int argc, char **argv){
	load();
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
	gets(s);
	for(int i = 0; i < t; i++){
		solve(i + 1);
		cerr << "test " << i + 1 << endl;
	}
	return 0;
}
