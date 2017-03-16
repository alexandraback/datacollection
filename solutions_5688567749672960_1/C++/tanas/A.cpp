#include <iostream>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int inf = 1e9;
const double eps = 1e-7;
const int maxn = 1001000;
const int mod = 1000000007;

ll rev(ll x) {
	ll ret = 0;
	while (x) {
		ret = ret * 10 + (x % 10);
		x /= 10;
	}
	return ret;
}

ll get(ll x) {
	
	//cout << x << endl;
	if (x <= 20) return x;
	
	if (x % 10 == 0) return get(x - 1) + 1;
	
	stringstream ss;
	ss << x;
	string s;
	ss >> s;
	
	//cout << s << endl;
	for (int i = 0, j = s.size() - 1; i <= j; ++i, --j) {
		if (i == 0) {
			if (s[i] != '1') {
				s[j] = '1';
				break;
			} else {
				s[j] = '1';
			}
			continue;
		}
		
		if (s[i] != '0') {
			s[j] = s[i] - 1;
			break;
		}
		
		s[j] = '0';
	}
	
	//cout << s << endl;
	
	stringstream iss(s);
	ll nx;
	iss >> nx;
	
	//cout << x << ' ' << nx << endl;
	
	ll add = x - nx;
	
	ll rv = rev(nx);
	if (rv < nx) return get(rv) + add + 1;
	return get(nx - 1) + add + 1;
}

int main() 
{
#ifdef DEBUG
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif
	vi f(maxn, inf);
	f[0] = 0;
	for (int i = 0; i < maxn - 1; ++i) {
		f[i + 1] = min(f[i + 1], f[i] + 1);
		int r = rev(i);
		if (r < maxn) {
			f[r] = min(f[r], f[i] + 1);
		}
	}
	
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		ll x;
		scanf("%lld", &x);
		
		printf("Case #%d: %lld\n", t + 1, get(x));
		
	}
	return 0;
}
