/*
 * a.cpp
 *
 *  Created on: May 6, 2012
 *      Author: lyl
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

int n, a[510];

map<int, int> mp;

void print(int i) {
	bool first = true;
	for (int j = 0; j < n; j++) {
		if ((i & (1 << j)) > 0) {
			if (first) {
				printf("%d", a[j]);
				first = false;
			}
			else
				printf(" %d", a[j]);
		}
	}
	printf("\n");
}

int main() {
	int ca;
	cin >> ca;
	for (int tt = 0; tt < ca; tt++) {
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		mp.clear();
		printf("Case #%d:\n", tt+1);
		bool flag = false;
		for (int i = 0; i < (1<<n); i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if ((i & (1 << j)) > 0)
					sum += a[j];
			}
			if (mp.count(sum) == 0)
				mp[sum] = i;
			else {
				print(mp[sum]);
				print(i);
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << "Impossible" << endl;
	}
}
