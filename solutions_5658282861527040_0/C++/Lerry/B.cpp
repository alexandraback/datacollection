#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <cstdio>
using namespace std;

int bitAnd(int A, int B) {
	int test = 1;
	int ret = 0;
	while(test <= A && test <= B) {
		if( (test & A) == test && (test & B) == test ) ret += test;
		test *= 2;
	}
	return ret;
}

int main() {
	int T = 0;
	int k = 1;
	scanf("%d", &T);
	while(k <= T) {
		map<int, int> dmap;
		int A, B, K;
		scanf("%d %d %d", &A, &B, &K);
		for(int i = 0; i < A; i++) {
			for(int j = 0; j < B; j++) {
				int val = bitAnd(i, j);
				//cout << val << endl;
				if(dmap.find(val) != dmap.end()) {
					dmap[val] += 1;
				}
				else {
					dmap[val] = 1;
				}
			}
		}
		int ret = 0;
		for(int i = 0; i < K; i++) {
			if(dmap.find(i) != dmap.end()) {
				ret += dmap[i];
			}
		}
		//int a;
		//cin >> a;
		printf("Case #%d: %d\n", k, ret);
		k++;
	}
	return 0;
}