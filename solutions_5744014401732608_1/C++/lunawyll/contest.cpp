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



void task(){
	int t;
	cin >> t;

	for (int tnum = 1; tnum <= t; ++tnum){
		llint n, m;
		cin >> n >> m;
		if ((1 << n - 2) < m){
			printf("Case #%d: IMPOSSIBLE\n", tnum);
			continue;
		}
		vector<vi>g(n, vi(n));
		for (int i = 1; i < n - 1; ++i)
			for (int j = i + 1; j < n; ++j){
				g[i][j] = 1;
			}
		if ((1 << n - 2) == m){
			g[0][n - 1] =1;
			--m;
		}
		int num = n - 2;
		while (m){
			if (m % 2){
				g[0][num] = 1;
			}
			m /= 2;
			--num;
		}
		printf("Case #%d: POSSIBLE\n", tnum);
		for (auto x: g){
			for (auto y : x){
				cout << y;
			}
			cout << endl;
		}
	}

}
