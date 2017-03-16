#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int f[1000]={0};

vector<int> ans;

void rem(string s, int k) {
	for(int i = 0; i < f[s[0]]; ++i)
		ans.push_back(k);
	for(int i = 1; i < s.size(); ++i) {
		f[s[i]] -= f[s[0]];
	}
	f[s[0]] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		string s;
		cin >> s;
		for(int j = 0; j < 1000; ++j)
			f[j] = 0;
		for(int i = 0; i < s.size(); ++i)
			++f[s[i]];
		ans.clear();
		rem("ZERO",0);
		rem("XSI",6);
		rem("WTO",2);
		rem("GIEHT",8);
		rem("HTREE",3);
		rem("RFOU",4);
		rem("FIVE",5);
		rem("VSEEN",7);
		rem("ONE",1);
		rem("INEN",9);
		sort(ans.begin(),ans.end());
		cout << "Case #" << t << ": ";
		for(int i = 0; i < ans.size(); ++i)
			cout << ans[i];
		cout << "\n";
	}
	return 0;
}
