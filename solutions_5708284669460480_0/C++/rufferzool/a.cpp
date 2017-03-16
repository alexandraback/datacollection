#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string K, L;

vector <string> S;

bool check(string a, string b) {
	for(int i = 0; i < b.length(); i ++) {
		if(i >= a.length())
			return false;
		if(a[i] != b[i])
			return false;
	}
	return true;
}

void generate(int s, int curr, string temp, char c ) {
	if(c != ' ')
		temp.push_back(c);
	if(curr == s) {
		S.push_back(temp);
		return;
	}
	for(int i = 0; i < K.length(); i ++) {
		generate(s, curr + 1, temp, K[i]);
	}
	return;
}

int cnt(string a, string b) {
	int ret = 0;
	for(int i = 0; i < a.length(); i ++) {
		ret += check(a.substr(i), b);
	}
	return ret;
}

int main() {
	int T;
	scanf(" %d", &T);
	for(int z = 0; z < T; z ++) {
		S.clear();
		int k, l, s;
		scanf(" %d %d %d", &k, &l, &s);
		cin >> K >> L;
		char c = ' ';
		generate(s, 0, "", c);
		int tot = 0, maxi = 0;
		for(int i = 0; i < S.size(); i ++) {
			tot += cnt(S[i], L);
			maxi = max(maxi, cnt(S[i], L));
		}
		printf("Case #%d: %.7Lf\n", z + 1, ((long double) maxi) - (((long double) tot ) / ((long double) S.size())));
	}
	return 0;
}
