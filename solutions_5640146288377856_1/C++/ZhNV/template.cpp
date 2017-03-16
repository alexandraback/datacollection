#include <iostream>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define mp make_pair
#define pb push_back
#define put(x) { cout << #x << " = "; cout << (x) << endl; }

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef double db;

const int M = 1020;
const ll Q = 1e18 + 7;



int dp[30][30][30], f[30];

int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int tq = 1; tq <= t; tq++){
		int r, c, w;
		cin >> r >> c >> w;
		for (int n = w; n <= 20; n++)
			for (int dl = w;  dl >= 1; dl--)
				for (int a = 1; a <= n; a++){
					int b = a + dl - 1;
					if (b > n)
						continue;
					if (a == 1 || b == n)
						dp[n][a][b] = w - (b - a + 1);
					else
						dp[n][a][b] = min(1 + max(dp[n][a - 1][b], (w - (b - a + 1))), 1 + max(dp[n][a][b + 1], (w - (b - a + 1))));
				}
	   	for (int n = w; n <= 20; n++){
	   		f[n] = 1 + max(f[n - w], dp[n][w][w]);
	   	//	cerr << n << " " << f[n] << " " << dp[n][w][w] << endl;
	   	}	
	   	cout << "Case #" <<tq << ": " << (r - 1) * (c / w) + f[c] << endl;
	}
	return 0;
}