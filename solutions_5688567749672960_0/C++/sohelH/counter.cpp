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

const int MAX = 1123456;
int dp[MAX];

int reverse(int n) {
	char str[10];
	sprintf(str, "%d", n);
	string s = str;
	reverse(s.begin(), s.end());
	sscanf(s.c_str(), "%d", &n);
	return n;
}

void bfs(int n) {
	for (int i = 1; i <= n; i++) dp[i] = -1;
	dp[1] = 1;
	queue<int> q;
	q.push(1);

	while( !q.empty() ) {
		int a = q.front();
		q.pop();

		// add 1
		int newVal = a + 1;
		if (newVal < MAX && dp[newVal] == -1) {
			dp[newVal] = dp[a] + 1;
			q.push(newVal);
		}

		// reverse
		newVal = reverse(a);
		if (newVal < MAX && dp[newVal] == -1) {
			dp[newVal] = dp[a] + 1;
			q.push(newVal);
		}
	}
}

int main() {
	int test, cases = 1;
	cin >> test;
	bfs(1000000);
	for (cases = 1; cases <= test; cases++) {
		int n; cin >> n;
		cout << "Case #" << cases << ": " << dp[n] << endl;
	}
	return 0;
}
