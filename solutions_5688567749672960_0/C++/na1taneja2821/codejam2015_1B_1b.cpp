#include <bits/stdc++.h>
using namespace std;
int visited[1000005];
int main() {
	int t;
	cin >> t;
	int run = 1;
	for(run = 1; run <= t; run++) {
		memset(visited, 0, sizeof(visited));
		queue <pair<long long int, long long int> > q;
		long long int n;
		cin >> n;
		q.push(make_pair(1LL, 1));
		int cnt = 0;
		while(1) {
			long long int temp = q.front().second;
			long long int temp1 = q.front().first + 1;
			long long int temp2 = q.front().first;
			if(temp2 == n) {
				break;
			}
			q.pop();
			long long int rev = 0;
			while(temp2) {
				rev = rev * 10 + temp2 % 10;
				temp2 = temp2 / 10;
			}
			//cout << rev << endl;
			if(visited[temp1] != 1) {
				q.push(make_pair(temp1, temp + 1));
				visited[temp1] = 1;
			}
			if(visited[rev] != 1) {
				q.push(make_pair(rev, temp + 1));
				visited[rev] = 1;
			}
		}
		printf("Case #%d: %lld\n", run, q.front().second);
	}
	return 0;
}