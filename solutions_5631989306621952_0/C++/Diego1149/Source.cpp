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

int main() {
	int T, caso=1;
	string S;
	cin >> T;
	while (T--) {
		cin >> S;
		string ans = "";
		ans += S[0];
		FOR(i, 1, S.length()) {
			if (S[i] >= ans[0]) {
				ans = S[i] + ans;
			}
			else ans = ans + S[i];
		}
		cout << "Case #" << caso++ << ": " << ans;
		cout << endl;
	}
	return 0;
}
