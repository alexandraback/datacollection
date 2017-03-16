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


	vector<long long> num;

int work() {
	int count = 0;
	for (int i=0; i<num.size(); ++i)
		if (num[i] >= a && num[i] <=b)
			count++;
	return count;
}


int prepare() {
	num.clear();
	for (long long i=1; i *i <=100000000000000LL; ++i)
		if (check(i) && check(i*i))
			num.push_back(i*i);
	return 0;
}

int main() {
	freopen("C-large-1.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	prepare();
	cin >> T;
	for (int i=1; i<=T; i++) {
		init();
		cout << "Case #" << i << ": " << work() << endl;
	}
	return 0;
}