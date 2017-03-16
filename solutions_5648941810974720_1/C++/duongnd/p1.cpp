#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;
typedef long long int ll;

string digit[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

long count(long long num) {
	long res = 0;
	while (num > 0) {
		res = res | (1 << (num%10));
		num = num / 10;
	}
	return res;
}

long toint(char c) {
    return c - 'A';
}

long solve(string s) {
    int cnt[33] = {};
    int ans[11] = {};
    for (int i = 0; i < s.length(); i ++) {
        cnt[s[i] - 'A'] ++;
    }
    ans[0] = cnt[toint('Z')];
    ans[2] = cnt[toint('W')];
    ans[6] = cnt[toint('X')];
    ans[4] = cnt[toint('U')];
    ans[8] = cnt[toint('G')];
    ans[5] = cnt[toint('F')] - ans[4];
    ans[3] = cnt[toint('H')] - ans[8];
    ans[7] = cnt[toint('V')] - ans[5];
    ans[9] = cnt[toint('I')] - ans[5] - ans[6] - ans[8];
    ans[1] = cnt[toint('O')] - ans[0] - ans[2] - ans[4];
    for (int i =0; i <= 9; i ++)
        for (int j = 0; j < ans[i]; j ++)
            cout << i ;
}

int main() {
	long t = 0;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	string s;
	cin >> t;
	for (int i = 0; i < t; i ++) {
		cin >> s;
		printf("Case #%d: ", i + 1);
		solve(s);
		printf("\n");
	}
	return 0;
}
