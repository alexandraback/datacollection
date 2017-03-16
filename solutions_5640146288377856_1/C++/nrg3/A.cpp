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

int solve(int r, int c, int w) {
	int have = (r - 1) * (c / w);

	while (c >= 2 * w) {
		c -= w;
		++have;
	}

	if (c == w) {
		have += w;
	} else {
		have += w + 1;
	}

	return have;
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

		int r, c, w;
		cin >> r >> c >> w;
		int ans = solve(r, c, w);

		
		cout << "Case #" << test_ << ": " << ans << endl;
		
		cerr << "Case #" << test_ << ": " << ans << endl;
	}

	return 0;
}