#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for(int i = a; i < (int)(b); ++i)
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define ll long long

string s;

bool isc(char c) {
	return !(c == 'e' || c == 'i' || c == 'o' || c == 'a' || c == 'u');
}

char buf[1234567];

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int t;
	cin >> t;
	getline(cin, s);
	forn(tt, t) {
		int n;
		scanf("%s %d", buf, &n);
		long long res = 0;
		s = buf;
		int c = 0;
		int plast = -1;
		int pfir = -1;
		forn(i, s.length()) {
			if (isc(s[i])){
				++c;
				if (c >= n) {
					if (pfir < 0)
						pfir = i - n + 1;
					plast = i - n + 1;
				}
			}else{
				c = 0;
			}
			if (pfir >= 0){
				long long add = i+1;
				add -= i - plast;
				res += add;
			}
		}

		cout << "Case #" << (tt + 1) << ": " << res << endl;
	}
	
	return 0;
}