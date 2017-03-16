#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 30;
const int MAX = 5;

int tn;
int c, d, v;
bool can[MAXN];
int ans = 10000;

bool isOne(long long &x, int pos) {
	if (x & (1ll << pos))
		return true;
	return false;
}

void go(long long mask, int cur, int added) {
	if (mask == (1ll << (v + 1)) - 1) {
		if (ans > added)
			ans = added;
		return;
	}	
	if (added == MAX)
		return;
	for (int i = cur; i <= v; i++) {
		long long goMask = mask;
		for (int j = v; j >= i; j--) {
			int prev = j - i;
			if (isOne(mask, prev))
				goMask |= (1ll << j);
		}                 
		go(goMask, i + 1, added + 1); 
	}
}  

int main() {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));

	scanf("%d", &tn);
	
	for (int test = 1; test <= tn; test++) {
		scanf("%d %d %d", &c, &d, &v);

		memset(can, 0, sizeof(can));
		can[0] = 1;

		for (int i = 1; i <= d; i++) {
			int x;
			scanf("%d", &x);
			for (int j = v; j >= x; j--)
				if (can[j - x])
					can[j] = true;
		}

		long long mask = 0;
		for (int i = 0; i <= v; i++)
			if (can[i])
				mask |= 1ll << i;

		//cout << mask << endl;

		ans = 10000;
		go(mask, 1, 0);

		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}