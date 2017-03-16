#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

typedef unsigned int uint;
typedef long long ll; // 0 - 89223372036854775807i64 (8.92 * 10^19)
typedef unsigned long long ull; // 0 - 818446744073709551615i64 (8.18 * 10^20)
typedef vector<int> vi;

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORCHR(str, c) for(string::size_type c = 0; c < str.length(); c++)
#define FOREACH(c, it) for (auto it = (c).begin(); it != (c).end(); it++)
#define RESET(obj, val) memset(obj, val, sizeof obj)

string input_file = "A-large.in";

int s[202], sorted[202], N, x;

double max_points(int i, double res) {
	int j = (i == sorted[0])? 1 : 0;
	double max_val = s[sorted[j]];
	int cont = 1;
	for(; j < N; j++) {
		if (sorted[j] == i) continue;
		int jnext = (sorted[j + 1] == i)? j + 2 : j + 1;
		if (jnext < N) {
			double diff = s[sorted[jnext]] - max_val;
			if ((res / cont) * x < diff) return max_val + (res / cont) * x;
			max_val += diff;
			res -= diff * cont / x;
			cont++;
		}
	}
	return max_val + (res / cont) * x;
}

bool test(int i, double y) {
	double ci = (double)s[i] + x * y;
	return max_points(i, 1 - y) < ci;
}

int sort_elems(int i, int j) {
	return s[i] < s[j];
}

int main() {
	freopen(input_file.c_str(), "r", stdin);
	string output_file = input_file.substr(0, input_file.find_last_of('.')) + ".out";
	freopen(output_file.c_str(), "w", stdout);

	int tc;
	cout.precision(5);
	cout.setf(ios::fixed);

	cin >> tc;
	FOR(t, 1, tc) {
		cin >> N;
		x = 0;
		REP(i, N) {
			cin >> s[i];
			x += s[i];
			sorted[i] = i;
		}
		sort(sorted, sorted + N, sort_elems);

		cout << "Case #" << t << ":";
		REP(i, N) {
			double ymin = 0.0, ymax = 100.0, y = 50.0;
			while (ymax - ymin > 0.000001) {
				if (test(i, y / 100.0)) ymax = y;
				else ymin = y;
				y = (ymin + ymax) / 2;
			}
			cout << " " << y;
		}
		cout << endl;
	}
	return EXIT_SUCCESS;
}