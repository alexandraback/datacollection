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
	string s;
	cin >> s;
	vector<int> app(300);
	for (char c : s) {
		app[c]++;
	}

	vector<int> ans(10);
	ans[0] = app['Z'];
	ans[2] = app['W'];
	ans[4] = app['U'];
	ans[6] = app['X'];
	ans[8] = app['G'];
	
	ans[3] = app['H'] - ans[8];
	ans[5] = app['F'] - ans[4];
	ans[7] = app['S'] - ans[6];

	ans[1] = app['O'] - ans[0] - ans[2] - ans[4];
	ans[9] = app['N'] - ans[1] - ans[7];
	ans[9] /= 2;
	
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i]; j++) {
			cout << i;
		}
	}
	cout << endl;
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





