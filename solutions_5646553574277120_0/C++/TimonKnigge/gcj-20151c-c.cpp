#include <iostream>
#include <iomanip>
#include <vector>           
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <functional>
#include <string>
#include <string.h>  // Include for memset!
#include <complex>
#include <random>
#define _USE_MATH_DEFINES
#include <math.h>

#define INF 2000000000              // 9
#define LLINF 9000000000000000000LL // 18
#define LDINF 1e200

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef long long ll;
typedef long double ld;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int C, D, V;
		cin >> C >> D >> V;
		
		vector<bool> coin(V + 1, false);
		vector<bool> possible(V + 1, false);
		coin[0] = possible[0] = true;
		for (int i = 0; i < D; ++i) {
			int n;
			cin >> n;
			coin[n]  = true;
			for (int v = V; v >= 0; --v) {
				if (possible[v] && (v + n) <= V)
					possible[v + n] = true;
			}
			possible[n] = true;
		}

		int ans = 0;
		int x = 0;
		while ((1 << x) <= V) {
			bool f = true;
			for (int i = (1 << x); i <= min(V, (1 << (x + 1))); ++i)
				if (!possible[i]) f = false;
			if (f) {
				x++;
				continue;
			}

			if ((!coin[1 << x])) {
				ans++;
				coin[1 << x] = true;
				for (int v = V; v >= 0; --v) {
					if (possible[v] && (v + (1 << x)) <= V)
						possible[v + (1 << x)] = true;
				}
			}
			x++;
		}

		cout << "Case #" << t << ": " << ans << endl;
	}

	return 0;
}