#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;


int mfl[4][4] {
	{0, 0, 0, 0},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{0, 0, 1, 1}
};

int ma[4][4] {
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};


struct qq {
	int fl, x;
	qq() {
		fl = 0;
		x = 0;
	}
	bool operator==(qq a) {
		return fl == a.fl && x == a.x;
	}
	qq operator*(qq a) {
		qq ans;
		ans.fl = fl ^ a.fl ^ mfl[x][a.x];
		ans.x = ma[x][a.x];
		return ans;
	}
	qq operator*(int k) {
		qq ans;
		ans.fl = fl ^ mfl[x][k];
		ans.x = ma[x][k];
		return ans;
	}
};


qq ps[82000];


qq pow(qq x, ll k) {
	qq ans;
	while (k) {
		while (!(k & 1))
			k >>= 1, x = x * x;
		--k, ans = ans * x;
	}
	return ans;
}


int solve(string s, ll k) {
	int n = s.size();
	s = s + s + s + s;
	s = s + s;
	ps[0].fl = 0;
	ps[0].x = 0;
	int fll = 0;
	int sti = 0;
	int stj = 0;
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == 'i')
			ps[i + 1] = ps[i] * 1;
		if (s[i] == 'j')
			ps[i + 1] = ps[i] * 2;
		if (s[i] == 'k')
			ps[i + 1] = ps[i] * 3;
		if (fll == 0 && ps[i + 1].fl == 0 && ps[i + 1].x == 1)
			sti = i + 1, fll = 1; 
		else if (fll == 1 && ps[i + 1].fl == 0 && ps[i + 1].x == 3) {
			stj = i + 1;
			fll = 2;
		}
	}
	qq all = pow(ps[n], k);
	if (all.fl != 1 || all.x != 0)
		return false;
	if (fll == 2 && sti <= n * k && stj <= n * k)
		return true;
	else
		return false;
}


int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		ll k;
		string s;
		cin >> n >> k;
		cin >> s;
		cout << "Case #" << i + 1 << ": ";
		if (solve(s, k))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}


