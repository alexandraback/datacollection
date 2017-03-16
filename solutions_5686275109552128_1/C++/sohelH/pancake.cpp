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

#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		vector<int> v;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a; cin >> a; v.push_back(a);
		}
		int res = inf;

		for (int minHeight = 1; minHeight <= 1000; minHeight++) {
			int s = 0;
			for (int i = 0; i < v.size(); i++) {
				s += (v[i] - 1) / minHeight;
			}
			s += minHeight;
			res = min(res, s);
		}
		cout << "Case #" << cases << ": " << res << endl;
	}
	return 0;
}
