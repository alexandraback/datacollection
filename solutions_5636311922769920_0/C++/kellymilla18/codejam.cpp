#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mod 1000000007
using namespace std;

main(){
	ios::sync_with_stdio(0);
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t, cs = 1, k, c, s;
	cin >> t;
	
	while(t--) {
		cin >> k >> c >> s;
		cout << "Case #" << cs++ << ":";
		if((k+c-1)/c > s) 
			cout << " IMPOSSIBLE\n";
		else {
			vector <int> answer;
			int now = 1;
			while(now <= k) {
				int curr = now;
				now++;
				for(int i = 1; i < c; i++) {
					curr = (curr-1) * k + min(k, now);
					now++;
				}
				answer.push_back(curr);
			} 
			sort(answer.begin(), answer.end());
			for(int i = 0; i < answer.size(); i++)
				cout << " " << answer[i];
			cout << endl;
		}
	}
}

