#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, n;
	int a[1001];
	cin >> t;

	for(int cs=1;cs<=t;cs++){
		int mx = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		int ans = 1 << 30;
		for (int i = 1; i <= mx; i++){
			int ctr = i;
			for (int j = 0; j < n; j++)
				ctr += ceil(((double)(a[j] - i)) / i);
			ans = min(ans, ctr);
		}

		cout << "Case #"<<cs<<": "<<ans << endl;
	}
}