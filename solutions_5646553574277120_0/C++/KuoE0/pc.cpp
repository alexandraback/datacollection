/*
 * pc.cpp
 * Copyright (C) 2015 KuoE0 <kuoe0.tw@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> COINS;
vector<bool> canbe;

bool check() {
	for (int i = 0; i < (int)canbe.size(); ++i)
		if (!canbe[i])
			return true;
	return false;
}

int GetMin() {
	for (int i = 0; i < (int)canbe.size(); ++i) {
		if (!canbe[i]) {
			return i;
		}
	}
	return -1;
}

void CoinCombine(int now, int idx) {
	if (now >= (int)canbe.size())
		return;
	canbe[now] = true;

	if (idx == (int)COINS.size())
		return;
	CoinCombine(now + COINS[idx], idx + 1);
	CoinCombine(now, idx + 1);
}


int main() {

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t) {

		int C, D, V;

		scanf("%d %d %d", &C, &D, &V);

		COINS.clear();
		canbe = vector<bool>(V + 1);

		for (int i = 0; i < D; ++i) {
			int x;
			scanf("%d", &x);
			COINS.push_back(x);
		}

		do {
			CoinCombine(0, 0);
			int new_coin = GetMin();
			if (new_coin != -1)
				COINS.push_back(new_coin);
		} while (check());

		printf("Case #%d: %d\n", t + 1, (int)COINS.size() - D);
	}
	return 0;
}


