#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<(n);i++)
#define MOD 1000000007
#define MP make_pair
#define PB push_back
typedef long long ll;

int T, ans;
string s;
vector<int> v;

int main () {
	cin >> T;
	for (int _ = 1; _ <= T; _++) {
		v.clear(), ans = 0;
		cin >> s;
		fo(i, (int) s.size()) {
			if (!i || s[i] != s[i-1]) {
				v.PB(s[i] == '+');
			}
		}
		fo(i, (int) v.size()) if (v[i] == 0) {
			if (i == 0) ans++;
			else ans += 2;
		}
		printf("Case #%d: %d\n", _, ans);
	}
	return 0;
}
