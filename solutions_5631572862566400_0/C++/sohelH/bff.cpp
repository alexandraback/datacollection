#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

const int debug = 0;
#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

int BF[2000];

bool possible(vector<int> &v) {
	do {
		bool ok = true;
		for (int i = 0; i < v.size(); i++) {
			int n = (i + 1) % v.size();
			int p = (v.size() + i - 1) % v.size();
			if ( BF[ v[i] ] == v[n] || BF[ v[i] ] == v[p] ) {
			} else {
				ok = false;
			}
		}
		if (ok) return true;
	}while( next_permutation(v.begin(), v.end()));
	return false;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			BF[i] = a;
		}
		int res = 0;
		for (int i = 0; i < (1<<n); i++) {
			if (__builtin_popcount(i) < res) continue;
			vector<int> v;
			for (int j = 0; j < n; j++) {
				if (i & (1<<j)) {
					v.push_back(j + 1);
				}
			}
			if (possible(v)) {
				res = max(res, __builtin_popcount(i));
			}
		}
		cout << "Case #" << cases << ": " << res << endl;

	}
	return 0;
}
