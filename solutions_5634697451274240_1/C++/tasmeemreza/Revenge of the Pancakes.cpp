#include <bits/stdc++.h>
using namespace std;
typedef pair <char, int> pii;
vector <pii> v;

int main() {
	freopen("sublime-in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int t, cs = 0;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int n = s.size();
		int cnt = 1;

		for(int i = 1; i < n; i++) {
			if(s[i] == s[i - 1]) {
				++cnt;
			} else {
				v.push_back(make_pair(s[i - 1], cnt));
				cnt = 1;
			}
		} 
		v.push_back(make_pair(s[n - 1], cnt));

		int ans = int(v.size()) - 1;
		if(v[ans].first == '-') ans += 1;
		cout << "Case #" << ++cs << ": " << ans << "\n";
		v.clear();
	}
	return 0;
}