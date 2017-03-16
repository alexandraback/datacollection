#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

struct Hiker{
	int D, H, M;
};

Hiker hikers[5];

int main() {
	int T, caso=1, N;
	cin >> T;
	while (T--) {
		cin >> N;
		if (N == 2) {
			cin >> hikers[1].D >> hikers[0].H >> hikers[0].M;
			cin >> hikers[0].D >> hikers[1].H >> hikers[1].M;
		}
		else {
			cin >> hikers[1].D >> hikers[0].H >> hikers[0].M;
			hikers[1] = hikers[0];
			if (hikers[0].H > 1) N = 2;
		}
		int ans = 0;
		if (N == 2) {
			double t11 = (hikers[0].M / 360.0)*(360.0 - hikers[0].D);
			double t12 = t11+hikers[0].M;
			double t21 = (hikers[1].M / 360.0)*(360.0 - hikers[1].D);
			double t22 = t21 + hikers[1].M;
			if (t22 <= t11) {
				ans = 1;
			}
			if (t12 <= t21) {
				ans = 1;
			}
		}
		cout << "Case #" << caso++ << ": " << ans;
		cout << endl;
	}
	return 0;
}
