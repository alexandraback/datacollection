/*
 * $File: solve.cc
 * $Date: Sun May 10 18:39:52 2015 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */


#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

int solve(FILE *fin) {
	int C, D, V;
	fscanf(fin, "%d%d%d", &C, &D, &V);
	std::vector<int> a(D);
	for (int i = 0; i < D; i ++)
		fscanf(fin, "%d", &a[i]);
	std::vector<int> f(V + 1);
	f[0] = true;

	auto add_coin = [&](int value) {
		for (int i = V; i >= value; i --)
			f[i] |= f[i - value];
	};

	for (auto &v: a)
		add_coin(v);

	int cur = 0, ret = 0;

	for (; ;) {
		while (cur <= V && f[cur])
			cur += 1;
		if (cur == V + 1)
			break;
		ret += 1;
		add_coin(cur);
	}
	return ret;
}

int main() {
	int T;
	FILE *fin = stdin;
	fscanf(fin, "%d", &T);
	for (int case_id = 1; case_id <= T; case_id ++) {
		std::cerr << "processing Case #" << case_id << std::endl;
		fflush(stderr);
		std::cout << "Case #" << case_id << ": " << solve(fin) << std::endl;
		fflush(stdout);
	}
	return 0;
}


/*
 * vim: syntax=cpp11.doxygen foldmethod=marker foldmarker=f{{{,f}}}
 */
