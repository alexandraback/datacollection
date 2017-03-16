#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdlib>
#define MP make_pair
#define PB push_back

using namespace std;

typedef vector<int> vi;
typedef map<string,int> msi;
typedef pair<int, int> pii;
typedef unsigned long long ulrik;

struct icecube {
	string s, t;
	ulrik x, y, diff;
	int n;
	icecube(string s, string t) : s(s), t(t) {
		x = 0;
		y = 0;
		n = (int)(s.length());
		for(int i = 0;i < n; ++i) {
			x *= 10;
			y *= 10;
			x += (int)(s[i]-'0');
			y += (int)(t[i]-'0');
		}
		if(x > y) {
			diff = x-y;
		} else {
			diff = y-x;
		}
	}
	bool operator <(const icecube& o) const {
		if(diff != o.diff) return diff < o.diff;
		if(x != o.x) return x < o.x;
		if(y != o.y) return y < o.y;
		return false;
	}
};

icecube smokesome(int n, string s, string t, int p, int x, int y, bool swapperlapper) {
	if(swapperlapper) swap(s,t);
	for(int i = 0;i < p; ++i) {
		if(s[i] == '?' && t[i] == '?') {
			s[i] = '0';
			t[i] = '0';
		} else if(s[i] == '?' && t[i] != '?') {
			s[i] = t[i];
		} else if(t[i] == '?' && s[i] != '?') {
			t[i] = s[i];
		}
	}
	if(s[p] == '?') s[p] = x+'0';
	if(t[p] == '?') t[p] = y+'0';
	for(int i = 0;i < n; ++i) {
		if(s[i] == '?') s[i] = '9';
		if(t[i] == '?') t[i] = '0';
	}
	if(swapperlapper) swap(s,t);
	return icecube(s, t);
}

void solve(int n, string s, string t) {
	icecube a = smokesome(n,s,t,0,0,0,false);
	for(int p = 0;p < n;++p) {
		for(int x = 0;x < 10; ++x) {
			for(int y = 0;y < 10; ++y) {
				for(int swapperlapper = 0;swapperlapper < 2; ++swapperlapper) {
					icecube b = smokesome(n,s,t,p,x,y,swapperlapper);
					if(b < a) a = b;
				}
			}
		}
	}
	cout << a.s << " " << a.t << endl;
}


int main() {
	int T;
	cin >> T;
	for(int t = 1;t <= T; ++t) {
		string s1,s2;
		cin >> s1 >> s2;
		int n(s1.length());
		cout << "Case #" << t << ": ";
		solve(n,s1,s2);
	}
	return 0;
}
