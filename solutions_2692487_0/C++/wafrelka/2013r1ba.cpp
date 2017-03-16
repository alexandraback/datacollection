#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long int64;
const int inf = (int)1e9;

int main()
{
	int testcase;

	scanf("%d", &testcase);

	for(int casenum = 1; casenum <= testcase; ++casenum) {

		int a, n;
		vector<int> x;
		int mincost, ans;

		scanf("%d%d", &a, &n);
		x.resize(n);
		for(int i = 0; i < n; ++i)
			scanf("%d", &x[i]);
		sort(x.begin(), x.end());

		if(a == 1) {

			ans = n;

		} else {

			mincost = n;
			int h = a;
			int op = 0;

			for(int i = 0; i < n; ++i) {

				while(h <= x[i]) {
					op += 1;
					h = h + (h - 1);
				}

				h += x[i];
				//printf("%d -> %d\n", i, op);

				mincost = min(mincost, op + n - i - 1);
			}

			ans = mincost;
		}

		printf("Case #%d: %d\n", casenum, ans);
	}

	return 0;
}

/* ハラスメントに負けず */
/* 0完太陽にも負けず */
/* はやく人権を獲得したい */
