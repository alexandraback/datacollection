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
	for (int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
		
		int a, b, k; cin >> a >> b >> k;
		int r = 0;
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < b; ++j) {
				if ((i & j) < k) {
					++r;
				}
			}
		}

		cout << r << endl;
	}


	
	cerr << endl << endl << "Time: " << (double)(clock() - _start) / CLOCKS_PER_SEC << endl;
	return 0;
}