/*
 * pb.cpp
 * Copyright (C) 2015 KuoE0 <kuoe0.tw@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
string Keys, Target;
int times, banana, MIN;
int K, L, S, T;
map<string, int> string_set;

void BT(string now, int remain) {
	if (!remain) {
		if (string_set.find(now) == string_set.end())
			string_set[now] = 0;
		++string_set[now];
		++times;
		return;
	}

	for (int i = 0; i < (int)Keys.size(); ++i) {
		BT(now + Keys[i], remain - 1);
	}
}

int main() {


	scanf("%d", &T);

	for (int t = 0; t < T; ++t) {
		scanf("%d %d %d", &K, &L, &S);
		cin >> Keys >> Target;
		times = 0;
		MIN = 0;
		string_set.clear();
		BT("", S);

		double ret = 0;
		for (auto iter = string_set.begin(); iter != string_set.end(); ++iter) {
			string str = iter->first;
			int cnt = iter->second;


			int tmp = 0;
			for (int i = 0; i <= (int)str.size() - L; ++i) {
				if (str.compare(i, L, Target) == 0) {
					++tmp;
				}
			}
			MIN = max(tmp, MIN);
			ret += (double)tmp * (double)cnt / (double)times;
		}
		printf("Case #%d: %.6f\n", t + 1, MIN - ret);
	}

	return 0;
}


