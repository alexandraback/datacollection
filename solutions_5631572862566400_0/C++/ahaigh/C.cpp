#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <utility>
#include <bitset>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define MP make_pair
#define PB push_back
#define CL(x) memset(x, 0, sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;

const int N = 1005;

int ans, adj[N];
bool seen[N];
void dfs(int x, int from, int deep) {
	if (seen[x]) return;
	seen[x] = true;
	cout << (x+1) << " ";
	deep++;
	ans = max(ans, deep);
	dfs(adj[x], from, deep);
}

void dfs2(int x) {
	int s = 1;
	int y = x;
	while (!seen[ adj[y] ]) {
		cout << (y+1) << " ";
		seen[y] = true;
		y = adj[y];
		s++;
	};
	ans = max(ans, s);
}


int dfs3(int x, int from, int depth, int banned) {
	//cout << x << " " << from << endl;
	if (x == banned) return -1000000;
	if (x == from) return depth;
	if (seen[x]) return -1000000;
	seen[x] = true;
	return dfs3(adj[x], from, depth+1, banned);
}

int n;
int solve() {
	ans = 0;

	REP(i,n) {
		if (i < adj[i] && adj[ adj[i] ] == i) {
			//reciprocal
			int s = 2, tmp1 = 0, tmp2 = 0;
			//fringes
			REP(j,n) {
				CL(seen); tmp1 = max(tmp1, dfs3(j, i, 0, adj[i]));
				CL(seen); tmp2 = max(tmp2, dfs3(j, adj[i], 0, i));
			}
			//cout << (i+1) << " " << tmp1 << " " << tmp2 << endl;
			ans = ans + (s+tmp1+tmp2);
		}
	}

	//?
	REP(i,n) {
		int x = i, s = 1;
		CL(seen);
		do {
			if (seen[x]) break;
			seen[x] = true;
			x = adj[x];
			if (x != i) s++;
		} while (x != i);
		//cout << (i+1) << " " << s << " " << (x == i) << endl;
		if (x == i) ans = max(ans, s);
	}
	return ans;
}

int brute() {
	int ans = 0;
	REP(tt,1<<n) {
		vector<int> z;
		REP(i,n) if (tt & (1<<i)) z.PB(i);
		do {
			//REP(i,z.size()) cout << z[i] << " ";
			//cout << endl;
			bool fail = false;
			REP(i,z.size()) {
				if (adj[ z[i] ] != z[(i+1)%z.size()]
					&& adj[ z[i] ] != z[(i+z.size()-1)%z.size()])
					fail = true;
			}
			if (!fail && ans < z.size()) ans = z.size();
		} while (next_permutation(z.begin(), z.end()));
	}
	return ans;
}


int T;
int main() {
	cin >> T;
	REP(qqq,T) {
		cin >> n;
		REP(i,n) {
			cin >> adj[i];
			adj[i]--;
		}
		int q = solve();
		cout << "Case #" << (qqq+1) << ": " << q << endl;
		/*if (q != brute()) {
			cout << q << " " << brute() << endl;
			REP(i,n) cout << (adj[i]+1) << endl;
			return 0;
		}*/
		//cout << brute() << endl;
	}
}
