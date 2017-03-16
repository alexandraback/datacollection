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

int cnt[26];

string num[10] = {
	"ZERO",
	"ONE",
	"TWO",
	"THREE",
	"FOUR",
	"FIVE",
	"SIX",
	"SEVEN",
	"EIGHT",
	"NINE"
};

string ans = "";

void go(int idx, string cur) {
	bool ok = true;
	for(int i = 0; i < 26; i++) {
		if(cnt[i] < 0) return;
		if(cnt[i] != 0) ok = false;
	}
	if(ok) {
		ans = cur;
		return;
	}
	for(int nxt = idx; nxt <= 9; nxt++) {
		string wtf = num[nxt];
		for(int i = 0; i < sz(wtf); i++) cnt[wtf[i]-'A']--;
		go(nxt, cur + (char)(nxt + '0')); 
		for(int i = 0; i < sz(wtf); i++) cnt[wtf[i]-'A']++;
	}
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		string s;
		cin >> s;
		for(int i = 0; i < 26; i++) cnt[i] = 0;
		for(int i = 0; i < sz(s); i++) cnt[s[i]-'A']++;
		ans = "";
		go(0, "");
		printf("Case #%d: ", t);
		cout << ans << endl;
	}


	return 0;
}