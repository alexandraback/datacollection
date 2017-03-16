#include <bits/stdtr1c++.h>

using namespace std;

typedef __int128 ll;

const ll INT_M = numeric_limits<long long>::min();
const ll INT_MX = numeric_limits<long long>::max();
string s, t;
ll memo[20][10][10], memo1[20][10][10], memo2[20][10][10], p[20], n;

ll abs(ll x) {
	if (x < 0) return -x;
	return x;
}

ll dpm(int i, int a, int b) {
	////cerr << i << " " << a << " " << b << endl;
	////cerr << s[i] << " " << t[i] << " " << (memo[i][a][b] != INT_M) << endl;
	if (memo1[i][a][b] != INT_M) return memo1[i][a][b];
	if (i == s.size()) return 0;
	
	if (s[i] == '?') {
		if (t[i] == '?') {
			//nothing!
		} else {
			int y = t[i]-'0';
			if (y != b) return INT_MX/20;
		}
	} else if (t[i] == '?') {
		int x = s[i]-'0';
		if (x != a) return INT_MX/20;
		
	} else {
		int x = s[i]-'0', y = t[i]-'0';
		if (x != a || y != b) return INT_MX/20;
	}
	
	ll tot = p[n-i-1] * (a-b);
	ll& val = memo1[i][a][b] = INT_MX;
	////cerr << "cand tot: " << (long long)(tot) << endl;
	for (int r = 0; r < 10; r++) {
		for (int s = 0; s < 10; s++) {
			if (tot + dpm(i+1, r, s) < val) {
				val = tot + dpm(i+1, r, s);
			}
		}
	}
	////cerr << "res: " << (long long)(val) << endl;
	return val;
}

ll dpM(int i, int a, int b) {
	////cerr << i << " " << a << " " << b << endl;
	////cerr << s[i] << " " << t[i] << " " << (memo[i][a][b] != INT_M) << endl;
	if (memo2[i][a][b] != INT_M) return memo2[i][a][b];
	if (i == s.size()) return 0;
	
	if (s[i] == '?') {
		if (t[i] == '?') {
			//nothing!
		} else {
			int y = t[i]-'0';
			if (y != b) return INT_M/20;
		}
	} else if (t[i] == '?') {
		int x = s[i]-'0';
		if (x != a) return INT_M/20;
		
	} else {
		int x = s[i]-'0', y = t[i]-'0';
		if (x != a || y != b) return INT_M/20;
	}
	
	ll tot = p[n-i-1] * (a-b);
	ll& val = memo2[i][a][b] = INT_M/20;
	////cerr << "cand tot: " << (long long)(tot) << endl;
	for (int r = 0; r < 10; r++) {
		for (int s = 0; s < 10; s++) {
			if (tot + dpM(i+1, r, s) > val) {
				val = tot + dpM(i+1, r, s);
			}
		}
	}
	////cerr << "res: " << (long long)(val) << endl;
	return val;
}


ll dp(int i, int a, int b) {
	////cerr << i << " " << a << " " << b << endl;
	////cerr << s[i] << " " << t[i] << " " << (memo[i][a][b] != INT_M) << endl;
	if (memo[i][a][b] != INT_M) return memo[i][a][b];
	if (i == s.size()) return 0;
	
	if (s[i] == '?') {
		if (t[i] == '?') {
			//nothing!
		} else {
			int y = t[i]-'0';
			if (y != b) return INT_MX/20;
		}
	} else if (t[i] == '?') {
		int x = s[i]-'0';
		if (x != a) return INT_MX/20;
		
	} else {
		int x = s[i]-'0', y = t[i]-'0';
		if (x != a || y != b) return INT_MX/20;
	}
	
	ll tot = p[n-i-1] * (a-b);
	ll& val = memo[i][a][b] = INT_MX;
	////cerr << "cand tot: " << (long long)(tot) << endl;
	for (int r = 0; r < 10; r++) {
		for (int s = 0; s < 10; s++) {
			if (abs(tot + dpm(i+1, r, s)) < abs(val)) {
				val = tot + dpm(i+1, r, s);
			}
			
			if (abs(tot + dpM(i+1, r, s)) < abs(val)) {
				val = tot + dpM(i+1, r, s);
			}
		}
	}
	////cerr << "res: " << (long long)(val) << endl;
	return val;
}

int main() {
    ios::sync_with_stdio(0);
	
	p[0] = 1;
	for (int i = 1; i < 20; i++) {
		p[i] = 10 * p[i-1];
	}
	
    int T; cin >> T;
    for (int ca = 1; ca <= T; ca++) {
		cin >> s >> t;
		
		n = s.size();
		for (int i = 0; i < 20; i++) {
			for (int a = 0; a < 10; a++) {
				for (int b = 0; b < 10; b++) {
					memo[i][a][b] = memo1[i][a][b] = memo2[i][a][b] = INT_M;
				}
			}
		}
		
		//cerr << (long long) (dp(0, 1, 0)) << endl;
		assert(s.size() == t.size());
		long long cdiff = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] != '?' && t[i] != '?') {
				// nothing
			} else {
				////cerr << i << " in else" << endl;
				//cerr << (long long)(dp(i, 9, 0)) << endl;
				if (s[i] == '?' && t[i] == '?') {
					ll bval = INT_MX;
					ll ba = 0, bb = 0;
					for (int a = 0; a < 10; a++) {
						for (int b = 0; b < 10; b++) {
							//cerr << "cand: " << a << " " << b << " " << cdiff << " " << (long long)(dp(i, a, b)) << " " << (long long)(abs(cdiff+dp(i, a, b))) << endl;
							if (abs(cdiff+dp(i, a, b)) < bval) {
								ba = a;
								bb = b;
								bval = abs(cdiff + dp(i, a, b));
								//cerr << a << " " << b << " " << (long long)(bval) << endl;
							}
						}
					}
					s[i] = '0' + ba;
					t[i] = '0' + bb;
				} else if (s[i] == '?') {
					ll bval = INT_MX;
					ll ba = 0, bb = t[i]-'0';
					for (int a = 0; a < 10; a++) {
						if (abs(cdiff+dp(i, a, bb)) < bval) {
							ba = a;
							bval = abs(cdiff + dp(i, a, bb));
						}
					}
					s[i] = '0' + ba;
				} else {
					ll bval = INT_MX;
					ll ba = s[i]-'0', bb = 0;
					for (int b = 0; b < 10; b++) {
						if (abs(cdiff+dp(i, ba, b)) < bval) {
							bb = b;
							bval = abs(cdiff + dp(i, ba, b));
						}
					}
					t[i] = '0' + bb;
				}
			}
			int x = s[i]-'0';
			int y = t[i]-'0';
			cdiff += p[n-i-1] * (x-y);
			////cerr << x << " " << y << endl;
		}
		
		cout << "Case #" << ca << ": ";
		cout << s << " " << t << endl;
		//cerr << cdiff << endl;
    }
	return 0;
}