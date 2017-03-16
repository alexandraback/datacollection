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

bool check(int val, string &s) {
	int p1 = 1;
	for(int i = sz(s) - 1; i >= 0; i--) {
		if(s[i] != '?') {
			if(s[i] - '0' != val % 10) return false;
		}
		val /= 10;
	}
	return true;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		string s1, s2;
		cin >> s1 >> s2;
		int p1 = 1;
		if(sz(s1) == 1) p1 = 10;
		else if(sz(s1) == 2) p1 = 100;
		else p1 = 1000;
		int p2 = 1;
		if(sz(s2) == 1) p2 = 10;
		else if(sz(s2) == 2) p2 = 100;
		else p2 = 1000;
		int best1 = -1;
		int best2 = -1;
		for(int i = 0; i < p1; i++) {
			for(int j = 0; j < p2; j++) {
				if(check(i, s1) && check(j, s2)) {
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
			}
		}

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