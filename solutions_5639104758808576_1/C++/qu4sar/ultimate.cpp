#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, n;
	char s[1001];
	int c;
	cin >> t;

	for(int cs=1;cs<=t;cs++){
		cin >> n >> s;
		c = 0;
		int ans = 0;
		for (int i = 0; i <= n; i++){
			int tmp= max(0,  (i-c));
			ans += tmp;
			c += tmp;
			c += s[i] - '0';
		}
		cout << "Case #"<<cs<<": "<<ans << endl;
	}
}