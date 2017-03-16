#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cmath>
#include <cassert>

using namespace std;


void task();

int main() {
#ifdef LUNAWYLL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
//	 freopen("bisector.in", "r", stdin);
//	 freopen("bisector.out", "w", stdout);
#endif
	task();
#ifdef LUNAWYLL
	//cout << "\n============\n" <<(double)clock()/CLOCKS_PER_SEC;
#endif
	return 0;
}

#ifdef LUNAWYLL
#define dbg(x) cout << #x << " = " << (x) << endl;
#define dbg2(a, b) cout << #a << " = " << (a) << "; "<<\
#b << " = " << (b) << endl;
#define dbg3(a, b, c) cout << #a << " = " << (a) << "; "<<\
		#b << " = " << (b) << "; "<<\
#c << " = " << (c) << endl;
#else
#define dbg(...) (void(1));
#define dbg2(...) (void(1));
#define dbg3(...) (void(1));
#endif

typedef long long int llint;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define ALL(v) ((v).begin()), ((v).end())

const int N = 2e5 + 10;
const llint MOD = (llint)1e9 + 7;
const int INF = 0x3f3f3f3f;
const llint LINF = (llint)8e18 + 100;
const int BUF_SIZE = (int)1e6 + 10;

const double PI = acos(-1);

vector<vi> gen(int n, int mask){
	vector<vi> res(n, vi(n));
	int num = 0;
	for (int i = 0; i < n; ++i){
		for (int j = i + 1; j < n; ++j, ++num){
			//dbg2(num, mask & (1 << num));
			res[i][j] = ((mask & (1 << num)) > 0);
		}
	}
	return res;
}

bool check(vector<vi> g, int m){
	vi dp(g.size());
	dp[g.size() - 1] = 1;
	for (int i = g.size() - 2; i >= 0; --i){
		for (int j = 0; j < g.size(); ++j) if (g[i][j]){
			dp[i] += dp[j];
		}
	}
	return dp[0] == m;
}

void task(){
	int t;
	cin >> t;
	for (int tnum = 1; tnum <= t; ++tnum){
		int n, m;
		cin >> n >> m;
		int sz = n*(n - 1)/2;
		//dbg(sz);
		bool ok = 0;
		for (int mask = 0; mask < (1 << sz); ++mask){
			///dbg(mask);
			auto g = gen(n, mask);
//			dbg("------------");
//			for (auto x: g){
//				for (auto y: x){
//					cout << y;
//				}
//				cout << endl;
//			}
//			dbg("------------");
//			cout << endl;
			if (check(g, m)){
				ok = 1;
				printf("Case #%d: POSSIBLE\n", tnum);
				for (auto x: g){
					for (auto y: x){
						cout << y;
					}
					cout << endl;
				}
				break;
			}

		}
		if (!ok)
			printf("Case #%d: IMPOSSIBLE\n", tnum);

	}

}
