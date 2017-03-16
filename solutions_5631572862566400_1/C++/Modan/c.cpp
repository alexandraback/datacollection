#include <iostream>
#include <vector>
#include <stack>
#include <algorithm	>
using namespace std;

int main(){
	int t,n,x; cin >> t;
	vector<int> g,v,special,ansv;
	stack<int> q;
	for (int tc = 1; tc <= t; tc++){
		cin >> n;
		g.assign(n, 0);
		special.assign(n, 0);
		ansv.assign(n, 0);
		for (int i = 0; i < n; i++){
			cin >> g[i]; g[i]--;
			q.push(i);
		}
	//	for (int i = 0; i < n; i++)cout << g[i] << endl;
		int ans = 0, ansnoloop = 0;
		for (int i = 0; i < n; i++){
			if (g[g[i]] == i){
				special[i] = 1;
				ans++;
			}
		}
	//	cout << ans << endl;
		for (int i = 0; i < n; i++){
			v.assign(n, 0);
			int tans = 0;
			int j = i;
			while (1){
				
				
				if (special[j]){
					ansv[j] = max(ansv[j], tans);
					break;
				}
				if (v[j]){
					if(j==i)ansnoloop = max(ansnoloop, tans);
					break;
				}
				tans++;
		//		cout << j << endl;
				v[j] = 1;
				j = g[j];
			}
		}

		for (int i = 0; i < n; i++){
		//	cout << ansv[i]<<endl;
			ans += ansv[i];
		}
	//	cout << ans << endl;
		
		cout << "Case #" << tc << ": " << max(ans,ansnoloop) << '\n';
	}
}