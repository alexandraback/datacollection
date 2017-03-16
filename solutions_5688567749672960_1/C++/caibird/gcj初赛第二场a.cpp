#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int countbit(long long x) {
	int count = 0;
	while(x != 0) {
		count ++;
		x /= 10;
	}
	return count;
}

string decode(long long x) {
	string s = "";
	while (x != 0) {
		s = char(x % 10 + '0') + s;
		x /= 10;
	}
	if (s == "") {
		return "0";
	} else {
		return s;
	}
}

long long encode(string s) {
	long long ret = 0;
	for (int i = s.size() - 1;i >= 0;i--) {
		ret = ret * 10 + (s[i] - '0');
	}
	return ret;
}

string reverse(string s) {
	string ret = "";
	for (int i = s.size() - 1;i >= 0;i--) {
		ret.push_back(s[i]);
	}
	return ret;
}

long long count(long long start, long long end) {
	if (start == end) {
		return 0;
	}
	long long ret = 0;
	string s = decode(start);
	string e = decode(end);
	int n = s.size();
	long long a = encode(e.substr(0, n / 2));
	long long b = encode(reverse(e.substr(n / 2, n)));
	if (b == 0) {
		return count(start, end - 1) + 1;
	} else {
		if (a == 1 || a == 0) {
			ret += b + a - 1;
		} else {
			ret += a + b;
		}
	}
	if (end < 10) {
		return ret + 1;
	} else {
		return ret;
	}
}

long long solve(long long n) {
	if (n == 1) {
		return 1;
	}
	long long ret = 0;
	long long temp = 1;
	while (temp * 10 - 1 < n) {
		ret += count(temp, temp * 10 - 1) + 1;
		temp = temp * 10;
	}
	return ret + count(temp, n);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int ii = 1;ii <= t;ii++) {
		long long n;
		scanf("%lld", &n);
		printf("Case #%d: %lld\n", ii, solve(n));
	}

	return 0;
}