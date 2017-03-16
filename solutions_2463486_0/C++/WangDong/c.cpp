#include<string>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int T;
long long a, b;

void init() {
	cin >> a >> b;
}

bool check(long long a) {
	string s = "";
	while (a > 0) {
		s = s + char(48 + (a % 10));
		a /= 10;
	}
	for (int i=0; i<s.length(); ++i)
		if (s[i] != s[s.length() - i - 1])
			return false;
	return true;
}

int work() {
	int count = 0;
	for (long long i=1; b / i >= i; ++i)
		if (i*i>=a && i*i<=b && check(i*i) && check(i)) {
			count++;
		}
	return count;
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	for (int i=1; i<=T; i++) {
		init();
		cout << "Case #" << i << ": " << work() << endl;
	}
	return 0;
}