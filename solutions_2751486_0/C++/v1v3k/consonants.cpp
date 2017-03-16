#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <cstring>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

int find_max_cons(string s) {
	int lmax = 0, len = 0;

	for(int i=0; i < sz(s); i++) {
		switch(s[i]) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': lmax = max(lmax, len);
			     len = 0;
			     break;
			default: ++len;
		}
	}
	lmax = max(lmax, len);
	return lmax;
}


int main() {
	string s;
	int T, n;

	cin >> T;

	for(int t=1; t <= T; t++) {
		cin >> s >> n;
		int cnt = 0;
		for(int i=0; i < sz(s); i++)
			for(int j=1; j <= sz(s) - i; j++)
				if (find_max_cons(s.substr(i, j)) >= n)
					cnt++;
		cout << "Case #" << t << ": " << cnt << endl;
	}
	return 0;
}