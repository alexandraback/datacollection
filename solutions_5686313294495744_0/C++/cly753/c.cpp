#include <stdio.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cassert>

#define SHOW(...) {;}
#define REACH_HERE {;}
#define PRINT(s, ...) {;}
#define PRINTLN(s, ...) {;}

// #undef HHHDEBUG
#ifdef HHHDEBUG
#include "template.h"
#endif

using namespace std;

template<typename T>
using Grid = vector<vector<T>>;

const double E = 1e-8;
const double PI = acos(-1);

void sol() {
	int n;
	cin >> n;
	vector<string> sa(n);
	vector<string> sb(n);
	for (int i = 0; i < n; i++)
		cin >> sa[i] >> sb[i];

	int ans = 0;
	int top = 1 << n;
	for (int x = 0; x < top; x++) {
		set<string> ta;
		set<string> tb;

		for (int k = 0; k < n; k++) {
			int mask = 1 << k;
			if (mask & x) {
				ta.insert(sa[k]);
				tb.insert(sb[k]);
			}
		}

		int fake = 0;
		bool can = true;
		for (int k = 0; k < n; k++) {
			int mask = 1 << k;
			if ((mask & x) == 0) {
				fake++;
				if (ta.find(sa[k]) == end(ta) || tb.find(sb[k]) == end(tb)) {
					can = false;
					break;
				}
			}
		}
		if (can) {
			if (ans < fake)
				ans = fake;
		}
	}
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);

    int nc;
    cin >> nc;
    for (int i = 1; i <= nc; i++) {
    	printf("Case #%d: ", i);
    	sol();
    }
}





