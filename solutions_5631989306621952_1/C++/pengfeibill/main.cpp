#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

#define uchar unsigned char
#define ushort unsigned short
#define ull unsigned ll
#define ll long long
#define ull unsigned ll

#define E 2.718281828
#define PI 3.14159265358979323846264338328

string s;

void solve() {
	string res;
	for (int i = 0; i < s.size(); i++) {
		string t1 = res + s[i];
		string t2;
		t2 += s[i];
		t2 += res;
		res = max(t1, t2);
	}
	cout << res << endl;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		cin >> s;
		solve();
	}
	return 0;
}