#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
#include<sstream>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>

#define Author "DemoVersion"
#define DBG(x) cout<<#x<<" = "<<x<<";\n"


using namespace std;
int dx[] = { 0,0,-1,1,1,-1,1,-1 };
int dy[] = { 1,-1,0,0,1,1,-1,-1 };
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

/// Hey yo man, lets do some contest in 5:30 AM!

string brute(string s, int k) {
	string s1 = "",s2="";
	for (int i = 0;i < s.length();i++) {
		if (k & (1 << i)) {
			s1 += s[i];
		}
		else {
			s2 += s[i];
		}
	}
	reverse(s2.begin(), s2.end());
	s2 += s1;
	return s2;
}
string brute_op(string s) {
	int k;
	string ans = "",r;
	for (k = 0;k < (1 << s.length());k++) {
		r = brute(s, k);
		if (ans == "" || r > ans) {
			ans = r;
		}
	}
	return ans;
}
int main() {
	int n, test, t, i, tmp;
	string inp;
	cin >> t;
	for (test = 1;test <= t;test++) {
		cin >> inp;

		cout << "Case #" << test << ": " << brute_op(inp) << endl;
	}
	
	return 0;
}
