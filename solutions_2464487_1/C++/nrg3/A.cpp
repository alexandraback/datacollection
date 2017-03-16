#pragma comment(linker, "/STACK:256000000")

#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <ctime>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>

using namespace std;

// #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
//#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)


const double PI = acos(-1.0);
const int INF = 1000000000;
const int MOD = 1000000007;

bool is(long long r, long long n, long long t) {
	unsigned long long a = (2 * r + 1 + 2 * (n - 1));
	unsigned long long b = n;
	if (a > t / b || t % b && a == t / b) {
		return 0;
	}

	return a * b <= t;
}


long long solve(long long r, long long t) {
	long long down = 1;
	long long up = t;

	while (down + 1 < up) {
		long long mid = down + (up - down) / 2;
		 
		if (is(r, mid, t)) {
			down = mid;
		} else {
			up = mid;
		}
	}

	return down;
}


int main() {

#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#else
#define taskname "comb"
    //freopen(taskname".in","r",stdin); 
    //freopen(taskname".out","w",stdout);
#endif

	int T; cin >> T;

	for (int test = 1; test <= T; ++test) {
		long long r, t;
		cin >> r >> t;

		cout << "Case #" << test << ": " << solve(r, t) << endl;
	}

	
	return 0;
}
