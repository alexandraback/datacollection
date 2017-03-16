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

const int N = 1e6 + 5;
long long memo[N];

long long rev(long long x) {
	long long t = 0;
	while (x) {
		t = t * 10 + x % 10;
		x /= 10;
	}
	return t;
}

long long brute(long long at, long long n) {
	if (memo[at] != -1) {
		return memo[at];
	}

	if (at == n) return 0;

	return memo[at] = min(brute(at + 1, n) + 1, (rev(at) > at && rev(at) < N? brute(rev(at), n) : 1000000000) + 1);
}

long long solve(long long n) {
	return 0;
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
		memset(memo, -1, sizeof(memo));
		long long x; cin >> x;
		long long ans = brute(0, x);

		cout << "Case #"<< test_ << ": ";
		cout << ans << endl;
	
		
		cerr << "Case #"<< test_ << ": ";
		cerr << ans << endl;
	 
	}
	
	return 0;
}