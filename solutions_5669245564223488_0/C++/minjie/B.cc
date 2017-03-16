#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <iostream>
#include <map>
typedef long long ll;
const long long MOD = 1000000007ll;
using namespace std;

int n;
string str[110];

string gao(string s) {
	int len = s.length();
	bool v[110] = {0};
	for(int i = 0;i < len - 1; ++i) {
		if(s[i] == s[i+1]) v[i+1] = 1;
	}
	string ans = "";
	for(int i = 0;i < len; ++i) {
		if (!v[i]) ans += s[i];
	}
	return ans;
}
bool valid(string &s) {
	int last[26];
	memset(last, -1, sizeof(last));
	for(size_t j = 0;j < s.length(); ++j) {
		if (last[s[j]-'a'] == -1) {
			last[s[j]-'a'] = j;
			continue;
		}
		if (last[s[j]-'a'] + 1 != j) 
			return false;
		last[s[j]-'a'] = j;
	}
	s = gao(s);
	return true;
}

int main() {
	int cas;
	scanf("%d", &cas);
	for(int it = 1;it <= cas; ++it) {
		printf("Case #%d: ", it);
		scanf("%d", &n);
		int ok = 1;
		for(int i = 0;i < n; ++i) {
			cin >> str[i];
			if (!valid(str[i])) ok = 0;
			//cout << str[i] << endl;
		}
		if (!ok) {
			puts("0");
			continue;
		}
		int id[11];
		for(int i = 0;i < n; ++i) id[i] = i;
		ll ans = 0;
		do {
			string tmp = "";
			for(int i = 0;i < n; ++i) 
				tmp += str[id[i]];

			if (valid(tmp)) {
				ans ++;
				//cout << tmp << endl;
			}
		}while(next_permutation(id, id + n));
		ans %= MOD;
		printf("%lld\n", ans);
	}
}
