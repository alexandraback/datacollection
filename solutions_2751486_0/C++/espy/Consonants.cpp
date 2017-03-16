#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <deque>

using namespace std;


int n, m, res, k;
bool v[125];
string in;

int main () {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int _c;
	v['a'] = v['e'] = v['i'] = v['o'] = v['u'] = true;
	for (int i = 97; i < 123; i++) v[i] = !v[i];
	scanf ("%d", &_c);
	for (int c = 1; c <= _c; c++) {
		res = 0;
		cin >> in;
		scanf ("%d", &m);
		n = in.size();
		for (int i = 0; i < n - m + 1; i++) {
			string s;
			for (int j = i; j < n; j++) {
				bool f = false;
				k = 0;
				s += in[j];
				for (int p = 0; p <= j - i && !f; p++) {
					if (v[s[p]]) {
						k++;
						if (k == m) f = true;
					} else k = 0;
				}
				if (f) res++;
			}
		}
		printf ("Case #%d: %d\n", c, res);
	}
	return 0;
}