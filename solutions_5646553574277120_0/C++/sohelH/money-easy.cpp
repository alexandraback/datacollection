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
		int C, D, V;
		cin >> C >> D >> V;
		vector<int> v;
		for (int i = 0; i < D; i++) {
			int a; cin >> a; v.push_back(a);
		}
		sort(v.begin(), v.end());

		int dp[55] = {0};
		dp[0] = 1;
		for (int i = 0; i < v.size(); i++) {
			for (int j = V; j >= 0; j--) {
				if (dp[j] && (j + v[i] <= V)) {
					dp[ j + v[i] ] = 1;
				}
			}
		}


		int res = 0;
		for (int i = 1; i <= V; i++) {
			if (dp[i] == 0) {
				res++;
				for (int j = V; j >= 0; j--) {
					if (dp[j] && (j + i <= V)) {
						dp[j + i] = 1;
					}
				}
			}
		}

		printf("Case #%d: %d\n", cases, res);

	}
	return 0;
}
