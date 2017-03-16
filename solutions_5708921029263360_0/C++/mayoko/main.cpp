#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
//#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<list>
#include<queue>
#include<deque>
#include<algorithm>
//#include<numeric>
#include<utility>
//#include<memory>
#include<functional>
#include<cassert>
#include<set>
#include<stack>
#include<random>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

struct JPS {
	int j, p, s;
	JPS() {}
	JPS(int j, int p, int s) : j(j), p(p), s(s) {}
	bool operator<(const JPS& rhs) {
		if (j != rhs.j) return j < rhs.j;
		if (p != rhs.p) return p < rhs.p;
		return s < rhs.s;
	}
};

int J, P, S, K;
int jp[20][20], ps[20][20], sj[20][20];

void solve() {
	cin >> J >> P >> S >> K;
	vector<int> ans;
	int maxi = J*P*S;
	for (int s = 0; s < 1<<maxi; s++) {
		int cnt = __builtin_popcount(s);
		if (ans.size() >= cnt) continue;
		memset(jp, 0, sizeof(jp));
		memset(ps, 0, sizeof(ps));
		memset(sj, 0, sizeof(sj));
		bool ok = true;
		for (int i = 0; i < maxi; i++) {
			if ((s>>i)&1) {
				int j = i%J;
				int p = (i/J)%P;
				int s = i/(J*P);
				if (++jp[j][p] > K) ok = false;
				if (++ps[p][s] > K) ok = false;
				if (++sj[s][j] > K) ok = false;
				if (!ok) break;
			}
		}
		if (ok) {
			ans.clear();
			for (int i = 0; i < maxi; i++) {
				if ((s>>i)&1) ans.push_back(i);
			}
		}
	}
	cout << ans.size() << endl;
	for (int i : ans) {
		int j = i%J;
		int p = (i/J)%P;
		int s = i/(J*P);
		cout << j+1 << " " << p+1 << " " << s+1 << endl;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": " ;
		solve();
	}
	return 0;
}
