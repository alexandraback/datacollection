/*************************************************************************
    > File Name: C.cpp
    > Author: wmg_1001
    > Mail: wmg_1007@163.com 
    > Created Time: Sun 03 May 2015 02:05:53 AM CST
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <set>
using namespace std;

long long tot = 0;
long long s[15], t[15];

int main() {
	long long T;
	cin >> T;
	for (long long case_T = 1; case_T <= T; case_T++) {
		long long n;
		cin >> n;
		long long res;
		tot = 0;
		for (long long i = 0; i < n; i++) {
			long long t1, t2, t3;
			cin >> t1 >> t2 >> t3;
			for (long long j = 0; j < t2; j++) {
				s[tot] = t1;
				t[tot] = t3 + j;
				tot++;
			}
		}
		if (tot == 1 || t[0] == t[1]) {
			res = 0;
		} else {
			double v1 = 360.00 / (double)t[0];
			double v2 = 360.00 / (double)t[1];
			long long tt1, tt2 = 0;
			if (v2 > v1) {
				double l1 = (360.00 - (double)s[0]) / (v2 - v1);
				if (l1 < 360.00 / v1) {
					tt1++;
					double l2 = 360.00 / v1 - l1;
					tt1 += (long long)(l2 / (360.00 / (v2 - v1)));
				}
			} else {
				double l1 = (double)s[0] / (v1 - v2);
				if (l1 < 360.00 / v1) {
					tt1++;
					double l2 = 360.00 / v1 - l1;
					tt1 += (long long)(l2 / (360.00 / (v1 - v2)));
				}
			}
			if (v1 > v2) {
				double l1 = (360.00 - (double)s[1]) / (v1 - v2);
				if (l1 < 360.00 / v2) {
					tt2++;
					double l2 = 360.00 / v2 - l1;
					tt2 += (long long)(l2 / (360.00 / (v1 - v2)));
				}
			} else {
				double l1 = (double)s[1] / (v2 - v1);
				if (l1 < 360.00 / v2) {
					tt2++;
					double l2 = 360.00 / v2 - l1;
					tt2 += (long long)(l2 / (360.00 / (v2 - v1)));
				}
			}
			res = min(tt1, tt2);
		}
		cout << "Case #" << case_T << ": " << res << endl;
	}
	return 0;
}
			