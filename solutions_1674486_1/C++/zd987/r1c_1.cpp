#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;


int cl[1001][1001] = {0};
int num[1001] = {0};
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("output.txt","w",stdout);
	int T, t, N, i, j, k, tmp, x;
	bitset<1001> bs;
	deque<int> qu;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (i = 1; i <= N; i++) {
			scanf("%d", &tmp);
			num[i] = tmp;
			for (j = 1; j <= tmp; j++) {
				scanf("%d", &x);
				cl[i][j] = x;
			}
		}
		bool flag = true;;
		for (i = 1; i <= N; i++) {
			qu.push_back(i);
			flag = true;
			bs.reset();
			while (!qu.empty()) {
				tmp = qu.front();
				qu.pop_front();
				if (tmp == 0)
					continue;
				if (bs.test(tmp)) {
					flag = false;
					break;
				}
				bs.set(tmp);
				for (j = 1; j <= num[tmp]; j++) {
					qu.push_back(cl[tmp][j]);
				}
			}
			while (!qu.empty())
				qu.clear();
			if (!flag)
				break;
		}
		if (flag)
			printf("Case #%d: No\n", t);
		else
			printf("Case #%d: Yes\n", t);
	}
	return 0;
}