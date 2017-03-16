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

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const double PI = acos(-1.0);
const int INF = 1000000000;
const int MOD = 1000000007;

long long gcd(long long a, long long b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	int _start = clock();
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	/*
#ifndef ONLINE_JUDGE
    
    freopen("output.txt","w",stdout);
#else
#define taskname "cutting"
	//freopen(taskname".in","r",stdin);
    //freopen(taskname".out","w",stdout);
#endif
*/

	int T; cin >> T;
	char c;
	for (int test = 1; test <= T; ++test) {
		printf("Case #%d: ", test);
		long long p, q;
		cin >> p >> c >>  q;
		

		long long gc = gcd(p, q);
		p /= gc; q /= gc;

		while (q < (1ll << 40)) {
			p *= 2;
			q *= 2;
		}

		if (q > (1ll << 40)) {
			cout << "impossible" << endl;
			continue;
		}

		int level = 40;
		while (p > 0) {
			--level;
			p /= 2;
		}

		cout << level + 1 << endl;
	}


	
	cerr << endl << endl << "Time: " << (double)(clock() - _start) / CLOCKS_PER_SEC << endl;
	return 0;
}