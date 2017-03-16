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

#define maxS 1000

int main() {
	int T, caso=1, S, count, ans;
	string people;
	cin >> T;
	while (T--) {
		count = ans = 0;
		cin >> S >> people;
		FOR(i, 0, people.length()) {
			if (count < i) {
				ans += i - count;
				count = i;
			}
			count += people[i] - '0';
		}
		cout << "Case #" << caso++ << ": " << ans << endl;
	}
	return 0;
}
