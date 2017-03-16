#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <map>

#define INF 2000000000
#define MOD 1000000007

using namespace std;


int main() {
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int testCount;
	cin >> testCount;
	for (int testNum = 1; testNum <= testCount; testNum++) {
		cout << "Case #" << testNum << ": ";
		vector<long long> coins;
		long long c, d, v;
		cin >> c >> d >> v;
		for (int i = 0; i < d; i++) {
			long long tmp;
			cin >> tmp;
			coins.push_back(tmp);
		}
		sort(coins.begin(), coins.end());
		long long sum = 0;
		long long ans = 0;
		for (int i = 0; i < coins.size(); i++) {
			if (sum >= v)
				break;
			while (coins[i] > sum + 1) {
				ans++;
				sum += c * (sum + 1);
			}
			sum += c * coins[i];	
		}
		while (sum < v) {
			sum += c * (sum + 1);
			ans++;
		}
		cout << ans << endl;
	}	
	return 0;
}