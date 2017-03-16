#pragma comment(linker, "/STACK:512000000")
#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <string>
#include <sstream>
#include <math.h>
#include <stack>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

long double brute(int s, const string& target, const string& have) {
	
	vector<int> p(s, 0);
	
	long long ma = 0;
	long long sum = 0;
	long long cases = 0;

	while (true) {

		int in = 0;
		for (int from = 0; from + target.size() - 1 < s; ++from) {
			int j = 0;
			while (j < target.size() && target[j] == have[p[from + j]]) {
				++j;
			}

			if (j == target.size()) {
				++in;
			}
		}

		if (in > ma) {
			ma = in;
		}

		sum += in;
		++cases;

		int j = 0;
		while (j < p.size() && p[j] == have.size() - 1) {
			p[j] = 0;
			++j;
		}

		if (j >= p.size()) break;
		++p[j];
	}

	return (ma * cases - sum) / static_cast<long double>(cases);
}




int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#else
	#define taskname "cutting"
		//freopen(taskname".in","r",stdin);
		//freopen(taskname".out","w",stdout);
	#endif



	int tests_; cin >> tests_;
	for (int test_ = 1; test_ <= tests_; ++test_) {
		int k, l, s;
		string have, target;
		cin >> k >> l >> s >> have >> target;

		long double res = brute(s, target, have);
		
		cout.precision(8);
		cout << "Case #" << test_ << ": " << fixed << res << endl;;
		
		cerr.precision(8);
		cerr << "Case #" << test_ << ": " << fixed << res << endl;;
	}

	return 0;
}