#include <bits/stdc++.h>

using namespace std;

#define ll long long

int t;


void solve();

int main() {
	ios::sync_with_stdio(0);

	bool file = true;
	if (file) {
		freopen("B-small-attempt0.in","r", stdin);
		freopen("output.out", "w", stdout);
	}

	cin >> t;
	for (int z = 1; z<= t; z++) {
		cout << "Case #" << z << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

bool is_valid( int num, string s ) {
	int cur = s.length() - 1;
	while(num || cur >= 0) {
		if (s[cur] == '?' || s[cur] - '0' == num%10)
			num/= 10;
		else
			return false;
		cur--;
	}
	return true;
}

void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	int res = 10000;
	int resa, resb;
	for (int i = 0; i < 1000; i++) {
		for (int j = 0; j < 1000; j++) {
			if (abs(j-i) < res && is_valid(i, s1) && is_valid(j, s2)) {
				res = abs(j-i);
				resa = i;
				resb = j;
			}
		}
	}
	int len = s1.length();
	cout << setfill('0') << setw(len) << resa;
	cout << " ";
	cout << setfill('0') << setw(len) << resb;
	/*
	if (s1.length() == 1)
		printf("%01d %01d", resa, resb);
	else if (s1.length() == 2)
		printf("%02d %02d", resa, resb);
	else
		printf("%03d %03d", resa, resb);
		*/
}
