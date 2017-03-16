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

long count(long long num) {
	long res = 0;
	while (num > 0) {
		res = res | (1 << (num%10));
		num = num / 10;
	}
	return res;
}

long solve(string s) {
    string cur = "";
    cur = cur + s[0];
    for (int i = 1; i < s.length(); i ++) {
        long j = 0;
        while (j < cur.length() && s[i] == cur[j]) j ++;
        if (j == cur.length()) cur = cur + s[i];
        else {
            if (s[i] > cur[j]) cur = s[i] + cur;
            else cur = cur + s[i];
        }
    }
    cout << cur;
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
