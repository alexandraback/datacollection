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

int res[10];

void sub(int idx, int ccc) {
	string wtf = num[idx];
	for(int i = 0; i < sz(wtf); i++) {
		cnt[wtf[i]-'A'] -= ccc;
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
		for(int i = 0; i < 10; i++) res[i] = 0;
		res[0] = cnt['Z'-'A'];
		sub(0, res[0]);
		res[6] = cnt['X'-'A'];
		sub(6, res[6]);
		res[7] = cnt['S'-'A'];
		sub(7, res[7]);
		res[2] = cnt['W'-'A'];
		sub(2, res[2]);
		res[8] = cnt['G'-'A'];
		sub(8, res[8]);
		res[3] = cnt['T'-'A'];
		sub(3, res[3]);
		res[4] = cnt['U'-'A'];
		sub(4, res[4]);
		res[1] = cnt['O'-'A'];
		sub(1, res[1]);
		res[9] = cnt['N'-'A']/2;
		sub(9, res[9]/2);
		res[5] = cnt['F'-'A'];
		sub(5, res[5]);
		printf("Case #%d: ", t);
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < res[i]; j++) {
				printf("%c", i + '0');
			}
		}
		printf("\n");
	}


	return 0;
}