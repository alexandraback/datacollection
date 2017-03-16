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
#define mp make_pair



bool is_vowel(char c) {
	return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}

int solve(string const &s, int k) {
	vector<pair<int, int> > segs;
	vector<int> left_borders;
	vector<int> right_borders;
	int l = s.length();
	int i=0;
	while (i<l) {
		while (i<l && is_vowel(s[i])) ++i;
		if (i==l)break;
		int j=i;
		while (j<l && !is_vowel(s[j]))++j;
		if (j-i>=k) {
			segs.push_back(mp(i, j-1));
			left_borders.pb(i);
			right_borders.pb(j-1);
		}
		i=j;
	}
	lng res=0;
	for(int i=0;i<l;++i) {
		int t = upper_bound(left_borders.begin(), left_borders.end(), i)-left_borders.begin()-1;
		if (t==-1)
			continue;
		if (i<=right_borders[t]) {
			if (i-left_borders[t]+1>=k) {
				res += i-k+2;
			} else {
				if (t) {
					res += right_borders[t-1]-k+2;
				}
			}
		} else {
			if (t>=0) {
				res += right_borders[t]-k+2;
			}
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
		string s;
		int k;
		cin >> s >> k;
		int res = solve(s, k);
		++t;
		printf("Case #%d: %d\n", t, res);
	}


	return 0;

}