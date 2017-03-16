#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	freopen("B-small-attempt1.in.txt", "r", stdin);
	freopen("small.txt", "w", stdout);
	int n;
	cin >> n;
	for (int l = 1; l <= n; l++) {
		printf("Case #%d: ", l);
		string c, j;
		cin >> c >> j;
		bool cg = false, jg = false;
		for (int i = 0; i < c.length(); i++) {
			if (c[i] == '?' || j[i] == '?') {
				if (c[i] != '?') {
					if (cg == jg) j[i] = c[i];
					else {
						if (cg) j[i] = '9';
						else j[i] = '0';
					}
				}
				else if (j[i] != '?') {
					if (cg == jg) c[i] = j[i];
					else {
						if (jg) c[i] = '9';
						else c[i] = '0';
					}
				}
				else {
					if (cg == jg) c[i] = j[i] = '0';
					else {
						if (cg) {
							c[i] = '0';
							j[i] = '9';
						} else {
							j[i] = '0';
							c[i] = '9';
						}
					}
				}
			} else {
				if (cg == jg) {
					cg = c[i] > j[i];
					jg = j[i] > c[i];
				}
			}
		}
		cout << c << " " << j << endl;
	}
	return 0;
}