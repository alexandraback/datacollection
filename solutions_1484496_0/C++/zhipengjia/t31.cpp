#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; test ++) {
		int n, a[20];
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
		map<int, int> have;
		bool flag = false;
		printf("Case #%d:\n", test + 1);
		for (int i = 0; i < 1 << n; i ++) {
			int sum = 0;
			for (int j = 0; j < n; j ++)
				if (i & 1 << j) sum += a[j];
			if (have.find(sum) != have.end()) {
				int t1 = have[sum], t2 = i;
				vector<int> L1, L2;
				for (int j = 0; j < n; j ++) {
					if (t1 & 1 << j) L1.push_back(a[j]);
					if (t2 & 1 << j) L2.push_back(a[j]);
				}
				for (int j = 0; j < L1.size(); j ++)
					if (j < L1.size() - 1) printf("%d ", L1[j]); else printf("%d\n", L1[j]);
				for (int j = 0; j < L2.size(); j ++)
					if (j < L2.size() - 1) printf("%d ", L2[j]); else printf("%d\n", L2[j]);
				flag = true;
				break;
			}
			have[sum] = i;
		}
		if (! flag) printf("Impossible\n");
	}
	
	return 0;
}
