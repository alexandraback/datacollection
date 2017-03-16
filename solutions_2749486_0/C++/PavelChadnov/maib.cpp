#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define forn(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define lng long long

bool is_vowel(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

bool ok(string const &s, int n) {
	int l = s.length();
	int i=0;
	while (i<l) {
		while (i<l && is_vowel(s[i])) ++i;
		if (i==l)break;
		int j=i;
		while (j<l && !is_vowel(s[j]))++j;
		if (j-i>=n)return true;
		i=j;
	}
	return false;
}

string solve(int x, int y) {
	string res="";
	if (x>0) {
		forn(i, x) {
			res += "WE";
		}
	} else if (x<0) {
		x=-x;
		forn(i,x) {
			res+="EW";
		}
	}

	if (y>0) {
		forn(i, y) {
			res += "SN";
		}
	} else if (y<0) {
		y=-y;
		forn(i,y) {
			res+="NS";
		}
	}
	return res;
}

int main() {
#ifdef __ASD__ 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	

	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	int t=0;
	while (tc--) {
		int x, y;
		cin >> x >> y;
		string res = solve(x, y);
		++t;
		printf("Case #%d: %s\n", t, res.c_str());
	}


	return 0;

}