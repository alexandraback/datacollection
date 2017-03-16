#include<bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)a.size())
#define init(a,v) memset(a, v, sizeof(a))
#define all(a) a.begin(), a.end()

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

int t, shy, cnt, res;
string s;

int main() {
	cin >> t;
	for (int c = 1; c <= t; c++) {
		cout << "Case #" << c << ": ";
		cnt = 0;
		res = 0;
		cin >> shy >> s;
		for (int i = 0; i <= shy; i++) {
			if (cnt < i) {
				cnt++;
				res++;
			}
			cnt += s[i] - '0';
		}
		cout << res << endl;
	}
	return 0;
}
