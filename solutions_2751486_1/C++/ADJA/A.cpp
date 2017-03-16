#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <utility>

using namespace std;

int t, n, len, l, r, num;
long long ans, add;
string s;
queue < pair<int, int> > con;
int sum[2000000];

bool vowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d\n", &t);

	for (int test = 1; test <= t; test++) {
		cin >> s;
		scanf("%d\n", &n);
		len = s.length();

		ans = 0;
		
		while (!con.empty())
			con.pop();

		for (int i = 1; i <= len; i++) {
			if (vowel(s[i - 1]))
				sum[i] = 0;
			else
				sum[i] = sum[i - 1] + 1;

			if (sum[i] == 0 && sum[i - 1] >= n) {
				con.push(make_pair(i - sum[i - 1], i - 1)); 
			}
		}
		if (sum[len] >= n) {
			con.push(make_pair(len - sum[len] + 1, len)); 
		}

		for (int i = 1; i <= len; i++) {
			while (!con.empty() && i + n - 1 > con.front().second)
				con.pop();

			if (!con.empty()) {
				l = con.front().first; r = con.front().second;
				if (i <= l)
					r = l + n - 1;
				else
					r = i + n - 1;
				add = len - r + 1;
				ans += add;
			}
		}

		printf("Case #%d: %I64d\n", test, ans);
	}

	return 0;
}