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
string s1, s2;
long long res,r1,r2;
int a[22], b[22];

        // if (t < res || (t == res && t1 < r1) || (t == res && t1 == r1 && t2 < r2)) {
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


long dfs(int p, long long t1, long long t2, long long m) {
    if (p >= s1.length()) {
        long long t = abs(t1-t2);
        if (t < res || (t == res && t1 < r1) || (t == res && t1 == r1 && t2 < r2)) {
            res = abs(t1-t2);
            r1 = t1; r2 = t2;
        }
        return 0;
    }
    long long nm = m / 10;
    if (a[p] != -1 && b[p] != -1) {
        dfs(p+1,t1 + a[p] * m, t2 + b[p] * m, nm);
        return 0;
    }

    long long diff = t1 - t2;
    if (a[p] == -1 && b[p] == -1) {
        for (int i = 0; i <= 9; i ++)
            for (int j = 0; j <= 9; j ++)
                dfs(p+1,t1 + i * m, t2 + j * m, nm);
        return 0;
    }

    if (a[p] == -1) {
        long long next = t2 + b[p] * m;
        for (int i = 0; i <= 9; i ++)
            dfs(p+1,t1 + i * m, next, nm);
        return 0;
    }

    if (b[p] == -1) {
        long long next = t1 + a[p] * m;
        for (int i = 0; i <= 9; i ++)
            dfs(p+1, next, t2 + i * m, nm);
        return 0;
    }
}

string tostring(long p,long t) {
    string res = "";
    while (p > 0){
        res = char('0' + p%10) + res;
        p /= 10;
    }
    while (res.length() < t) res = '0' + res;
    return res;
}

long solve() {
    for (int i = 0; i < s1.length(); i ++)
        if (s1[i] == '?') a[i] = -1;
        else a[i] = s1[i] - '0';
    for (int i = 0; i < s1.length(); i ++)
        if (s2[i] == '?') b[i] = -1;
        else b[i] = s2[i] - '0';
    res = 9223372036854775807;
    long t = 1;
    for (int i = 1; i < s1.length(); i ++)
        t = t * 10;
    dfs(0,0,0,t);
    cout << tostring(r1,s1.length()) << " " << tostring(r2,s1.length());
}

int main() {
	long t = 0;
	freopen("B-small-attempt3.in","r",stdin);
	freopen("bout2.out","w",stdout);
	string s;
	cin >> t;
	for (int i = 0; i < t; i ++) {
		cin >> s1 >> s2;
		printf("Case #%d: ", i + 1);
		solve();
		printf("\n");
	}
	return 0;
}
