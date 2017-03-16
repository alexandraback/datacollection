#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

typedef long long lint;

using namespace std;

vector <lint> list;

int ispalim(lint x)
{
	lint old = x, rev = 0;
	while (x) {
		rev = 10LL*rev + (x%10);
		x /= 10;
	}
	return rev == old;
}

void gen_squares()
{
	for (lint x = 1; x <= 11234567; x++) {
		if (ispalim(x) && ispalim(x*x))
			list.push_back(x*x);
		
	}
}

int main(int argc, char ** argv)
{
	gen_squares();

	int ntest;

	scanf("%d", &ntest);

	for (int t = 0; t < ntest; t++) {
		int a, b;
		scanf("%d %d", &a, &b);
		lint a2 = a, b2 = b;

		printf("Case #%d: %d\n", t+1, upper_bound(list.begin(), list.end(), b2) - lower_bound(list.begin(), list.end(), a2));
	}

	return 0;
}
