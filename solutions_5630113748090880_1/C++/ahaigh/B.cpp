#include <iostream>
#include <algorithm>
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
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define MP make_pair
#define PB push_back
#define CL(x) memset(x, 0, sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;

map<int,int> m;
int T, n, x;
int main() {
	cin >> T;
	REP(qqq,T) {
		m.clear();

		cin >> n;
		REP(i, 2*n-1) {
			REP(j, n) {
				cin >> x;
				m[x]++;
			}
		}

		vector<int> ans;
		for (auto p: m) {
			x = p.first;
			if (m[x] % 2) {
				ans.PB(x);
			}
		}
		sort(ans.begin(), ans.end());
		assert(ans.size() == n);

		cout << "Case #" << (qqq+1) << ":";
		for (auto x: ans) {
			cout << " " << x;
		}
		cout << endl;
	}
}
