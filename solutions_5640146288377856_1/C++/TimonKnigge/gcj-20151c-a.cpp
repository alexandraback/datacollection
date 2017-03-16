#include <iostream>
#include <iomanip>
#include <vector>           
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <functional>
#include <string>
#include <string.h>  // memset
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
		int R, C, W;
		cin >> R >> C >> W;

		long long ans = 0;

		ans += R * max(1, C / W);

		int lspace = W - 1, rspace = C % W;
		if (rspace == 0)
			ans += lspace;
		else {
			ans += lspace + 1;
		}

		cout << "Case #" << t << ": " << ans << endl;
	}

	return 0;
}