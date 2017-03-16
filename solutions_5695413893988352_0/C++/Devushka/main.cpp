#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
int n;
string c, jj;


string tostr(long long x) {
	string res = "";
	int cnt = 0;
	while (x > 0) {
		res += (char)(x % 10 + '0');
		x /= 10;
		cnt++;
	}
	while (cnt < n) {
		res += '0';
		cnt++;
	}
	reverse(res.begin(), res.end());
	return res;
}

long long bt2(long long cur, int pos, long long prev) {
	if (pos == n) {
		return cur;			
	}
	long long res = -1;
	if (jj[pos] != '?') {
		cur = cur * 10 + (jj[pos] - '0');
		return bt2(cur, pos + 1, prev);
	} 
	for (int i = 0; i < 10; i++) {
		long long tmp = cur * 10 + i;
		long long tmp1 = bt2(tmp, pos + 1, prev); 
		if (res == -1 || (abs(tmp1 - prev) < abs(res - prev))) res = tmp1;
	}
	return res;
}



pair<long long, long long> bt(long long cur, int pos) {
	pair<long long, long long> res;
	if (pos == n) {
		res.first = cur;
		res.second = bt2(0, 0, cur);
		return res;		
	}
	res.first = -1;
	res.second = -1;
	if (c[pos] != '?') {
		cur = cur * 10 + (c[pos] - '0');
		return bt(cur, pos + 1);
	} 
	for (int i = 0; i < 10; i++) {
		long long tmp = cur * 10 + i;
		pair<long long, long long> tmp1 = bt(tmp, pos + 1); 
		if (res.first == -1 || abs(tmp1.first - tmp1.second) < abs(res.first - res.second)) res = tmp1;
	}
	return res;
}

int main() {

	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		cin >> c >> jj;
		n = (int)c.size();
        pair<long long, long long> res = bt(0, 0);               		
        string a = tostr(res.first);
        string b = tostr(res.second);
		cout << "Case #" << tt + 1 << ": " << a << " " << b << endl;			
	}

	return 0;
}
