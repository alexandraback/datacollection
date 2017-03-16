#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int dp[10000000];
typedef pair<int, int> pii;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	queue<pair<int, int> > q;
	q.push(pii(1, 1));
	while (!q.empty()){
		auto here = q.front();
		q.pop();
		if (here.first >= 10000000) continue;
		if (dp[here.first] && (dp[here.first] <= here.second)) continue;
		dp[here.first] = here.second;
		q.push(pii(here.first + 1, here.second + 1));
		string str = to_string(here.first);
		reverse(str.begin(), str.end());
		int there = stoi(str);
		q.push(pii(there, here.second + 1));
	}

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++){
		cout << "Case #" << tc << ": ";
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
}