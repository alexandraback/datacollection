/*
 * Problem : 
 * Author : Hwhitetooth
 * Date : 
 * Result :
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

const int H = 2500 + 1;

int cnt[H];
int testCases, n;

int main() {
	cin >> testCases;
	for (int _ = 1; _ <= testCases; ++_) {
		memset(cnt, 0, sizeof cnt);
		cin >> n;
		for (int i = 0; i < 2 * n - 1; ++i) {
			for (int j = 0; j < n; ++j) {
				int h;
				cin >> h;
				cnt[h] ^= 1;
			}
		}
		cout << "Case #" << _ << ":";
		for (int h = 1; h < H; ++h) {
			if (cnt[h] == 1) {
				cout << " " << h;
			}
		}
		cout << endl;
	}
	return 0;
}
