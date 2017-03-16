#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
using namespace std;

vector <int> c, j, x, y;
int n;
int diff=1000000;

int nm(vector <int> a) {
	int ans = 0;
	reverse(a.begin(), a.end());
	int deg = 1;
	for (auto k : a) {
		ans += deg * k;
		deg *= 10;
	}
	return ans;
}

void gen(int ps) {
	if (ps == n) {
		int dif = abs(nm(c) - nm(j));
		if (dif < diff) {
			x = c;
			y = j;
			diff = dif;
		}
		return;
	}
	if (c[ps] == j[ps] and j[ps] == -1) {
		for (int i = 0; i < 10; i++) {
			for (int t = 0; t < 10; t++) {
				c[ps] = i;
				j[ps] = t;
				gen(ps+1);
				c[ps] = -1;
				j[ps] = -1;
			}
		}
	}
	else if (c[ps] == -1) {
		for (int i = 0; i < 10; i++) {
			c[ps] = i;
			gen(ps+1);
			c[ps] = -1;
		}
	}
	else if (j[ps] == -1) {
		for (int i = 0; i < 10; i++) {
			j[ps] = i;
			gen(ps+1);
			j[ps] = -1;
		}
	}
	else {
		gen(ps+1);
	} 
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int st = 0; st < t; st++) {
		cout << "Case #" << st+1 << ": ";
		string a, b;
		diff = 100000;
		c.clear();
		j.clear();
		x.clear();
		y.clear();
		cin >> a >> b;
		int l = (int)a.size();
		n = l;
		for (int i = 0; i < l; i++) {
			if (a[i] == '?')
				c.push_back(-1);
			else
				c.push_back(a[i] - '0');
			if (b[i] == '?')
				j.push_back(-1);
			else
				j.push_back(b[i] - '0');
		}
		gen(0);
		for (int i = 0; i < n; i++) {
			cout << x[i];
		}
		cout << " ";
		for (int i = 0; i < n; i++) {
			cout << y[i];
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}