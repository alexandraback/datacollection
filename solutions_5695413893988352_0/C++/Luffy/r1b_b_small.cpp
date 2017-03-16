#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

typedef pair<int, int> P;

bool can_fit (int n, string w) {
	for (int i=w.length()-1; i>=0; i--) {
		if (w[i] != '?' && w[i] - '0' != n%10) return false;
		n/=10;
	}
	return n==0;
}

int main(){
	freopen("output.txt","w",stdout);
	freopen("input.in","r",stdin);
	int T;
	cin >> T;
	string w1, w2;
	int n;
	int flag; // 1: w1 bigger, 2: w2 bigger
	int idx;
	int first_diff;
	int best1, best2;
	for (int t=1; t<=T; t++) {
		cin >> w1 >> w2;
		n = w1.length();
		int smallest = 10000;
		for (int i1=0; i1<1000; i1++) {
			if (!can_fit(i1, w1)) continue;
			for (int i2 = 0; i2 < 1000; i2++) {
				if (!can_fit(i2, w2)) continue;
				if (abs(i1 - i2) < smallest) {
					smallest = abs(i1 - i2);
					best1 = i1;
					best2 = i2;
				}
			}
		}
		if (n==3)
			printf("Case #%d: %03d %03d\n", t, best1, best2);
		else if (n==2)
			printf("Case #%d: %02d %02d\n", t, best1, best2);
		else if (n==1)
			printf("Case #%d: %d %d\n", t, best1, best2);
		else
			printf("GGGGG\n");

	}
	return 0;
}