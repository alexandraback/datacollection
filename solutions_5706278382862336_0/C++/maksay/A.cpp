#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define inf 1000000000
#define L(s) ((int)(s).size())
#define x first 
#define y second
#define pii pair<int, int>
#define mp make_pair
int t;
ll p, q;
inline ll gcd(ll p, ll q) {
	while(p && q)
		if (p >= q) p %= q; else q %= p;
	return p + q;
}
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;
	for(int tc = 1; tc <= t; ++tc) {
		string s;
		cin >> s;
		p = q = 0;
		while(s[0] != '/') {
			p = p * 10 + s[0] - '0';
			s.erase(0, 1);
		}
		s.erase(0, 1);
		while(L(s)) {
			q = q * 10 + s[0] - '0';
			s.erase(0, 1);
		}
		cout << "Case #" << tc <<": ";
		ll g = gcd(p, q);
		p /= g; 
		q /= g;
		ll v = 1;
		while(v < q) v *= 2;
		if (v != q) {
			cout << "impossible\n";
			continue;
		}
		int tot = 1;
		while(p * 2 < q) {
			++tot;
			p *= 2;
		}
		cout << tot << "\n";
	}
}
