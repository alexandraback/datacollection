#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;

string rep(string a, char old, char nw){
	string r = a;
	for (int i = 0; i < (int)r.size(); i++){
		if (r[i] == old) r[i] = nw;
	}
	return r;
}

ll toll(string a){
	ll r = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		r = r * 10 + a[i] - '0';
	}
	return r;
}

string A, B;
ll difference = 1e18;

void maximize(string a, string b){
	ll x = toll(a);
	ll y = toll(b);
	if (abs(x - y) < difference || 
		abs(x - y) == difference && a < A || 
		abs(x - y) == difference && a == A && b < B) {
		A = a;
		B = b;
		difference = abs(x - y);
	}
}

char eq(char a, char b){
	return a == '?' || b == '?' || a == b;
}

void solve(){
	difference = 1e18;
	string a, b, x, y;
	cin >> a >> b;
	int n = a.size();

	int max_diff = 0;
	for (; max_diff < n && eq(a[max_diff], b[max_diff]); max_diff++);

	//cout << max_diff << endl;
	for (int i = 0; i < max_diff; i++) {
		int la, ra, lb, rb;
		if (a[i] == '?') la = '0', ra = '9';
		else la = ra = a[i];

		if (b[i] == '?') lb = '0', rb = '9';
		else lb = rb = b[i];

		x = a;
		y = b;
		for (int j = 0; j < i; j++) {
			int c;
			if (a[j] != '?' && b[j] != '?')
				c = a[j];
			else if (a[j] == '?' && b[j] == '?')
				c = '0';
			else
				c = a[j] + b[j] - '?';
			x[j] = y[j] = c;
		}
		//cout << x << " " << y << endl;
		for (x[i] = la; x[i] <= ra; x[i]++){
			for (y[i] = lb; y[i] <= rb; y[i]++){
				maximize(rep(x, '?', '0'), rep(y, '?', '9'));
				maximize(rep(x, '?', '9'), rep(y, '?', '0'));
			}
		}
	}
	maximize(rep(a, '?', '0'), rep(b, '?', '9'));
	maximize(rep(a, '?', '9'), rep(b, '?', '0'));

	cout << A << " " << B << endl;
}

int main() {
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++){
		cout << "Case #" + to_string(test) + ": ";
		solve();
	}
	return 0;
}