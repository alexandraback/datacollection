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

bool eq(vector<string>& a, vector<string>& b){
	if (a.size() != b.size()) return false;

	for (int i = 0; i < a.size(); i++){
		if (a[i] != b[i]) return false;
	}
	return true;
}

void un(vector<string>& a){
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
}

void p(vector<string>& a){
	for (string s : a){
		cout << s << " ";
	}
	cout << endl;
}

void solve(){
	int n;
	cin >> n;
	vector<pair<string, string> > a(n);
	vector<string> xx, yy;
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
		xx.push_back(a[i].first);
		yy.push_back(a[i].second);
	}
	un(xx);
	un(yy);
	int result = 1e9;

	for (int mask = 0; mask < (1 << n); mask++){
		vector<string> x, y;
		int ans = 0;
		for (int i = 0; i < n; i++){
			if (mask & (1 << i)){
				x.push_back(a[i].first);
				y.push_back(a[i].second);
				ans++;
			}
		}
		un(x);
		un(y);
		//p(x);
		//p(y);
		if (eq(x, xx) && eq(y, yy) && ans < result){
			result = ans;
		}
	}
	cout << n - result << endl;
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