#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

#define For(i,a,b) for(int i = a; i < b; i++) 

int n, m;
vector <string> s;
string s0;
int f[111][111];

int cost(int idx) {
	vector <int> a(n);
	For(i,0,n) {
		a[i] = f[i][idx];
	}
	sort(a.begin(), a.end());
	int center = a[n/2];
	int res = 0;
	For(i,0,n) {
		res += abs(a[i] - center);
	}
	return res;
}

bool getf() {
	memset(f, 0, sizeof(f));
	
	For(i,0,n) {
		int sz = s[i].size();
		int c = 0;
		For(j,0,sz) {
			if (s[i][j] == s0[c]) {
				f[i][c]++;
			}
			else {
				if (f[i][c] == 0)
					return false;
				c++;
				j--;
			}
		}
	}
	
	For (i,0,n) {
		For(j,0,m) {
			if (f[i][j] == 0)
				return false;
		}
	}
	return true;
}

int main() {
	freopen("small.in", "r", stdin);
	freopen("small.out", "w", stdout);
	int tt;
	
	cin >> tt;
	For(t, 1, tt+1) {
		s.clear();
		
		cin >> n;
		
		For(i, 0, n) {
			string d;
			cin >> d;
			s.push_back(d);
		}
		m = 1;
		s0 = "";
		s0 += s[0][0];
		For (i,1,(int)s[0].size()) {
			if (s[0][i] != s[0][i-1]) {
				m++;
				s0 += s[0][i];
			}
		}
		//cout << s0 << endl;
		bool valid = getf();
		if (valid == false) {
			cout << "Case #" << t << ": Fegla Won" << endl;
		}
		else {
			int res = 0;
			For (i,0,m) {
				res += cost(i);
			}
			cout << "Case #" << t << ": " << res << endl;
		}
	}
}
