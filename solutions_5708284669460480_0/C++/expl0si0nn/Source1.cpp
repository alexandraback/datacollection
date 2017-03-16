#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <set>
#include <map>

#define ll long long
#define ld long double
#define sqr(x) ((x) * (x))
#define mp make_pair
#define TASKNAME ""

const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const ll infll = (ll)1e18;
const ld eps = 1e-9;

using namespace std;

int k, l, s;
vector<int> ts;
string str, word;

int cv(const string &str1, const string &str2) {
	string form = str1 + '#';
	form.append(str2);
	int n = (int)form.length();
	vector<int> pi(n);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && form[i] != form[j])
			j = pi[j - 1];
		if (form[i] == form[j])  ++j;
		pi[i] = j;
	}
	int res = 0;
	for (int i = str1.size(); i < n; i++) {
		if (pi[i] == str1.size())
			res++;
	}
	return res;
}

void go(int pos, string cur) {
	if (pos == s) {
		int t = cv(word, cur);
		ts.push_back(t);
		return;
	}
	for (int i = 0; i < k; i++) {
		string ncur = cur + str[i];
		go(pos + 1, ncur);
	}
}

void solve() {
	scanf("%d %d %d", &k, &l, &s);
	char buff[100];
	scanf("%s", &buff);
	str = string(buff);
	scanf("%s", &buff);
	word = string(buff);
	ts.clear();
	go(0, "");
	sort(ts.begin(), ts.end());
	int m = ts.back();
	ld p = 0;
	ld prob = (ld)1 / pow((ld)k, (ld)s);
	for (int i = 0; i < ts.size(); i++) {
		p += prob * ts[i];
	}
	ld ans = (ld)m - p;
	printf("%.7Lf", ans);
}

int main() {
#ifdef __DEBUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif
	int tests;
	scanf("%d", &tests);
	for (int i = 1; i <= tests; i++) {
		printf("Case #%d: ", i);
		solve();
		printf("\n");
		fprintf(stderr, "Case #%d Done\n", i);
	}

#ifdef __DEBUG__
	fprintf(stderr, "\nTime: %Lf\n", ((clock() - start) / (ld)CLOCKS_PER_SEC));
#endif
	return 0;
}