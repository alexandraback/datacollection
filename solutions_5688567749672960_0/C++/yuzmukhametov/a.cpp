// -Wl,--stack,9001 
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define rep(i, N) for (int i = 0; i < N; ++i)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
typedef long long lint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
const lint INF = 1LL << 60;

lint reverse_num(lint x) {
	char s[30];
	sprintf(s, "%lld", x);
	reverse(s, s + strlen(s));
	lint res;
	sscanf(s, "%lld", &res);
	return res;
}

vector<lint> brute(lint n) {
	queue<lint> q;
	q.push(1);
	vector<lint> d(n + 1, 1LL << 60);
	d[1] = 1;	
	while (!q.empty()) {
		lint u = q.front();
		q.pop();
		if (u + 1 <= n && d[u + 1] == INF) {
			q.push(u + 1);
			d[u + 1] = d[u] + 1;
		}
		lint t = reverse_num(u);
		if (t <= n && d[t] == INF) {
			q.push(t);
			d[t] = d[u] + 1;
		}
	}
	return d;
}

lint calc(lint x) {
	lint res = 1;

	while (x != 1) {
		++res;
		lint t = reverse_num(x);
		if (t < x && x % 10) {
			x = t;
		} else {
			--x;
		}
	}
	return res;
}

vector<lint> D;

void solve(int num) {
	int x;
	cin >> x;
	lint ans = D[x];
	printf("Case #%d: %lld\n", num, ans);
}


int main() {
	lint n = 1000000;
	D = brute(n);
	// for (lint i = 1; i <= n; ++i) {
	// 	lint t1 = calc(i);
	// 	lint t2 = d[i];
	// 	cout << i << " "  << t1 << " " <<t2 << endl;
	// }
	//cout << d[n] << endl;
	//return 0;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tst;
	cin >> tst;
	for (int i = 1; i <= tst; ++i) {
		solve(i);
	}
    return 0;
}
