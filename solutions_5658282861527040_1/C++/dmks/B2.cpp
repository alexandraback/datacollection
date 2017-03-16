#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define REP(i, n) for(int i = 0; i<(n); i++)
#define abs(a) ((a) >= 0 ? (a) : -(a))
#define inf 2000000001
typedef vector<int> VI;
typedef vector<string> VS;

typedef long long i64;
typedef unsigned long long u64;

map<VI, i64> G;

int getF(int a) {
	for (int i = 30; i>=0; i--) if (a & (1<<i)) return i;
	return -1;
}

i64 dp(VI cur) {
	int A = cur[0];
	int B = cur[1];
	int K = cur[2];
	if (cur[0] <= cur[2]) return ((i64)cur[0]) * cur[1];
	if (cur[2] == 0) return 0;
	map<VI, i64>::iterator it = G.find(cur);
	if (it != G.end()) return it->second;
	i64 ret = 0;
	
	int ka = getF(A - 1);
	int kb = getF(B - 1);
	VI next = cur;	
	if (kb > ka) {
		// 0
		next[1] = 1<<kb;
		ret += dp(next);
		
		// 1
		int nb = B - (1<<kb);
		next[0] = min(A, nb);
		next[1] = max(A, nb);
		ret += dp(next);
	} else if (kb == ka) {
		// 0, 0
		next[0] = next[1] = 1<<ka;
		ret += dp(next);
		// 0, 1
		next[0] = B - (1<<kb);
		next[1] = 1<<ka;
		ret += dp(next);
		// 1, 0
		next[0] = A - (1<<ka);
		next[1] = 1<<kb;
		ret += dp(next);
		// 1, 1
		if (K > (1<<kb)) {
			next[0] = A - (1<<ka);
			next[1] = B - (1<<kb);
			next[2] = K - (1<<kb);
			ret += dp(next);
		}
	} else {
		throw "error";
	}
	
	return G[cur] = ret;
}

void go() {
	int A, B, K;
	cin >> A >> B >> K;
	if (A > B) swap(A, B);
	VI cur;
	cur.push_back(A);
	cur.push_back(B);
	cur.push_back(K);
	i64 ret = dp(cur);
	cout << ret;
}

int main() {
  int T;
  cin>>T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
	go();
	cout << endl;
  }
}
