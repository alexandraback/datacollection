#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<functional>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int solve1(int A, int B, int K) {
	int ans = 0;
	for(int a = 0; a < A; ++a)
		for(int b = 0; b < B; ++b) {
			if ((a & b) < K)
				ans++;
		}
	return ans;
}
int main() {
	int T, A, B, K;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> A >> B >> K;
		cout << "Case #" << t << ": ";
		cout << solve1(A, B, K) << endl;
	}
	return 0;
}
