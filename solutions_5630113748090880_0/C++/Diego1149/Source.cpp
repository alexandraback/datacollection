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
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int main() {
	int T, caso=1;
	cin >> T;
	while (T--) {
		int N, temp;
		map<int, int> m;
		cin >> N;
		FOR(i, 0, 2 * N - 1) {
			FOR(j, 0, N) {
				cin >> temp;
				m[temp]++;
			}
		}
		set<int> ans;
		FORC(m, it) {
			if (it->second & 1) ans.insert(it->first);
		}
		cout << "Case #" << caso++ << ":";
		FORC(ans, it) cout <<" "<< *it;
		if (ans.size() != N) {
			N += 0;
		}
		cout << endl;
	}
	return 0;
}
