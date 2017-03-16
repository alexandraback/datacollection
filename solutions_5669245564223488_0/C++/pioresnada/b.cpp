#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

struct Gr {
	vector<int> s, e;
};

long fact(int d) {
	long l = 1;
	for (int i = 2; i <= d; ++i) {
		l*=i;
	}
	return l;
}

void fu() {
	int n; long y = 1; cin >> n;
	//Gr g[26];
	string s;
	vector<string> v;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		v.push_back(s);
	}
	//for (int i = 0; i < n; ++i) cout << v[i] << ' '; cout << endl;
	int a,b,c,d,e,f,h=n,g;a=b=c=d=e=0;
	for (int k = 0; k < 26; ++k) {
		d=e=f=g=0;
		for (int i = 0; i < n; ++i) {
			a=b=0;c=1;
			for (size_t j = 0; j < v[i].size(); ++j) {
				if (v[i][j] == k+'a') {
					if (j==0) a=1;
					else if (j==v[i].size()-1) b=1;
					else if (!c) ++g;
				}
				else c=0;
			}
			if (c) ++d;
			else {
				if (a) ++e;
				if (b) ++f;
			}
			if (e>1||f>1||g>1) {
				cout << 0 << endl;
				return;
			}
			if ((e||f)&&g) {
				cout << 0 << endl;
				return;
			}
		}
		y *= fact(d);
		if (e==1 && f==1)  {--h;if (d) h-=d;}
		else if (d && (e || f)) {--h;--d;}
		if (!e&&!f&& d)	h -= d-1;
		//y %= 1000000007L;
	}
	y *= fact(h);
	cout << y % 1000000007L << endl;
}
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-large.in", "r", stdin);
	freopen("out", "w", stdout);
	int t; cin >> t;
	for (int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		fu();
	}
	//cout << LLONG_MAX << endl;
}
