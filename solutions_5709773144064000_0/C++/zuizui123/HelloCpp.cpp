#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std;

#define fi "B-small-attempt0.in"
#define fo "out.txt"
const int MAXN = 200 + 5;
const int INF = 1e9;

int main() {
	freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);

	int T;
	cin >> T;
	double C, F, X;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		cin >> C >> F >> X;
		if (X <= C) {
			printf("%.7lf\n", X / 2);
			continue;
		}
		double res = C / 2;
		double cookiesPerSec = 2;
		int flag = 1;
		while (flag) {
			flag = 0;
			if (X / (cookiesPerSec + F) < (X - C) / cookiesPerSec) {
				res += C / (cookiesPerSec + F);
				cookiesPerSec += F;
				flag = 1;
			} else {
				flag = 0;
			}
		}
		res += (X - C) / cookiesPerSec;
		printf("%.7lf\n", res);
	}
}
