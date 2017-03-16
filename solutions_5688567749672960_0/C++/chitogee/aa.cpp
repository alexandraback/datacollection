#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<ll, int> m;

ll reverse(ll x) {
    string s = to_string(x);
    reverse(s.begin(), s.end());
    return stoll(s);
}

ll getLower(ll x) {
    if (x == 1) return 1;
    if ((x % 10) == 0) --x;
    ll res;
    string s = to_string(x);
    int len = s.length();
    for (int i = len>>1; i < len; ++i) s[i] = '0';
    s[len-1] = '1';
    string rev = s;
    reverse(rev.begin(), rev.end());
    if (rev == s) res = getLower(stoll(s) - 2);
    else res = stoll(s);
    return res;
}

int f(ll x) {
    if (x <= 1) return x;
    if (m.count(x)) return m[x];
    ll low = getLower(x);
    if (low == x) return (m[x] = (f(reverse(x)) + 1));
    else return (m[x] = f(low) + (x - low));
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("counter_output.txt", "w", stdout);
	int test;
	cin >> test;
	ll inp;
	for (int cse = 1; cse <= test; ++cse) {
	    cin >> inp;
	    cout << "Case #" << cse << ": " << f(inp) << endl;
	}
	return 0;
}

