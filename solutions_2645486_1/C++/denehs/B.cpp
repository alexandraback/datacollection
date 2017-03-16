#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>

#define MAXN 10
using namespace std;

int main () {
	int testcases;

	cin >> testcases;

	for (int testcase=1; testcase<=testcases; testcase++) {
		cout << "Case #" << testcase << ": ";
	
		map <int, int> dp[MAXN];
		int value[MAXN];

		int E, R, N;

		cin >> E >> R >> N;

		for (int i=0; i<N; i++)
			cin >> value[i];

		for (int i=0; i<=E; i++) {
			int nextE = E-i+R;
			if (nextE > E)
				nextE = E;
			
			int nextv = dp[0][nextE];
			if (nextv < value[0]*i)
				nextv = value[0]*i;
			dp[0][nextE] = nextv;
		}

		for (int i=1; i<N; i++) {
			for (map<int, int>::iterator j=dp[i-1].begin(); j!=dp[i-1].end(); j++) {
				for (int k=0; k<=j->first; k++) {
					int nextE = j->first - k + R;
					if (nextE > E)
						nextE = E;
					
					int nextv = dp[i][nextE];
					if (nextv < j->second + k*value[i])
						nextv = j->second + k*value[i];
					dp[i][nextE] = nextv;
				}
			}
		}

		int ans = 0;
		for (map<int, int>::iterator j=dp[N-1].begin(); j!=dp[N-1].end();j++) {
			if (ans < j->second)
				ans = j->second;
		}

		cout << ans;

		cout << endl;
	}

	return 0;
}
