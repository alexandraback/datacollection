#include <iostream>
#include <stdio.h>
#include <queue>

#define N 1000010

using namespace std;

long long dp[N];
long long n;

long long rev(long long x) {
	long long p = 0;
	while(x > 0) {
		p = 10ll * p + (x % 10);
		x /= 10;
	}
	return p;
}
void evaluate(int C) {
	cin >> n;
	cout << "Case #" << C << ": " << dp[n] << endl;
}
int main() {
	
	freopen("Asmall.in", "r", stdin);
	freopen("Asmall.out", "w", stdout);
	
	for(int i = 1;i < N;i++) {
		dp[i] = -1;
	}
	queue< pair<int, int> > bfs;
	bfs.push({1, 1});
	while(!bfs.empty()) {
		int x = bfs.front().first, val = bfs.front().second;
		bfs.pop();
		if(x >= N || (dp[x] != -1 && dp[x] <= val)) {
			continue;
		}
		dp[x] = val;
		bfs.push({x+1, val+1});
		bfs.push({rev(x), val+1});
	}
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++) {
		evaluate(i);
	}
	return 0;
}
