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

int tn;
int n, m, w;

int main() {
	//assert(freopen("input.txt","r",stdin));
	//assert(freopen("output.txt","w",stdout));

	scanf("%d", &tn);

	for (int test = 1; test <= tn; test++) {
		scanf("%d %d %d", &n, &m, &w);
		
		int row = 0;
		row = m / w;

		int after = w - 1;
		if ((m % w) != 0)
			after++;

		int ans = n * row + after;
		printf("Case #%d: %d\n", test, ans);
	}

	return 0;
}