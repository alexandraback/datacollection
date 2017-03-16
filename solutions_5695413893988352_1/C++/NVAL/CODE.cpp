#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>

using namespace std;

#pragma comment(linker, "/STACK:100000000")

#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()

ll best1 = -1, best2 = -1;

void checkans(ll i, ll j) {
	if(best1 == -1 && best2 == -1) {
		best1 = i;
		best2 = j;
	}
	else {
		if(abs(i-j) < abs(best1-best2) || abs(i-j) == abs(best1 - best2) && i < best1 || abs(i-j) == abs(best1 - best2) && i == best1 && j < best2) {
			best1 = i;
			best2 = j;
		}
	}
}

void go(string &s1, string &s2, int pos, ll cur1, ll cur2, ll deg10) {
	deg10 /= 10;
	pos++;
	if(deg10 == 0) { // конец
		checkans(cur1, cur2);
		return;
	}
	if(cur1 == cur2) { // много вариантов
		if(s1[pos] == '?' && s2[pos] == '?') {
			go(s1, s2, pos, cur1, cur2, deg10);
			go(s1, s2, pos, cur1 + 1LL * deg10, cur2, deg10);
			go(s1, s2, pos, cur1, cur2 + 1LL * deg10, deg10);
		}
		else if(s1[pos] == '?') {
			if(s2[pos] != '0') go(s1, s2, pos, cur1 + (ll)(s2[pos] - '0' - 1) * deg10, cur2 + (ll)(s2[pos] - '0') * deg10, deg10);
			if(s2[pos] != '9') go(s1, s2, pos, cur1 + (ll)(s2[pos] - '0' + 1) * deg10, cur2 + (ll)(s2[pos] - '0') * deg10, deg10);
			go(s1, s2, pos, cur1 + (ll)(s2[pos] - '0') * deg10, cur2 + (ll)(s2[pos] - '0') * deg10, deg10);
		}
		else if(s2[pos] == '?') {
			if(s1[pos] != '0') go(s1, s2, pos, cur1 + (ll)(s1[pos] - '0') * deg10, cur2 + (ll)(s1[pos] - '0' - 1) * deg10, deg10);
			if(s1[pos] != '9') go(s1, s2, pos, cur1 + (ll)(s1[pos] - '0') * deg10, cur2 + (ll)(s1[pos] - '0' + 1) * deg10, deg10);
			go(s1, s2, pos, cur1 + (ll)(s1[pos] - '0') * deg10, cur2 + (ll)(s1[pos] - '0') * deg10, deg10);
		}
		else {
			go(s1, s2, pos, cur1 + (ll)(s1[pos] - '0') * deg10, cur2 + (ll)(s2[pos] - '0') * deg10, deg10);
		}
	}
	else if(cur1 > cur2) { // 1 самый большой, 2 самый маленький
		ll bestcur1 = cur1;
		ll bestcur2 = cur2;
		if(s1[pos] == '?') bestcur1 = cur1;
		else bestcur1 = cur1 + deg10 * (ll)(s1[pos] - '0');
		if(s2[pos] == '?') bestcur2 = cur2 + deg10 * 9LL;
		else bestcur2 = cur2 + deg10 * (ll)(s2[pos] - '0');
		go(s1, s2, pos, bestcur1, bestcur2, deg10);
	}
	else {
		ll bestcur1 = cur1;
		ll bestcur2 = cur2;
		if(s1[pos] == '?') bestcur1 = cur1 + deg10 * 9LL;
		else bestcur1 = cur1 + deg10 * (ll)(s1[pos] - '0');
		if(s2[pos] == '?') bestcur2 = cur2;
		else bestcur2 = cur2 + deg10 * (ll)(s2[pos] - '0');
		go(s1, s2, pos, bestcur1, bestcur2, deg10);
	}
}


int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		string s1, s2;
		cin >> s1 >> s2;
		best1 = -1;
		best2 = -1;
		ll deg10 = 1;
		for(int i = 0; i < sz(s1); i++) {
			deg10 *= 10LL;
		}


		go(s1, s2, -1, 0LL, 0LL, deg10);


		printf("Case #%d: ", t);
		string str1 = "", str2 = "";
		for(int i = 0; i < sz(s1); i++) {
			str1 += best1 % 10 + '0';
			best1 /= 10;
		}
		for(int i = 0; i < sz(s2); i++) {
			str2 += best2 % 10 + '0';
			best2 /= 10;
		}
		reverse(str1.begin(), str1.end());
		reverse(str2.begin(), str2.end());
		cout << str1 << " " << str2 << endl;
	}


	return 0;
}