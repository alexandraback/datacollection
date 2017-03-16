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
int main() {
	freopen("A-small-attempt5.in", "r", stdin);
	freopen("output.txt","w",stdout);
	int T, N, s[205], i, j, X, max = -1, n0 = 0;
	double re[205], xxx;
	bitset<205> bs;
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		scanf("%d", &N);
		X = 0;
		max = -1;
		bs.reset();
		n0 = 0;
		if (i == 2)
			int ads = 1;
		for (j = 0; j < N; j++) {
			scanf("%d", &s[j]);
			X += s[j];
			if (s[j] == 0) n0++;
			if (s[j] > max) 
				max = s[j];
		}
		xxx = ((double) X * 2) / N;
		int tt = X, n = N;
		bool flag = true;
		while (flag) {
			flag = false;
			for (j = 0; j < N; j++) {
				if (bs.test(j))
					continue;
				if (xxx < s[j]) {
					re[j] = 0;
					bs.set(j);
					tt -= s[j];
					n--;
					flag = true;
				}
			}
			if (flag) {
				xxx = ((double) X + tt) / n;
			} else {
				break;
			}
		}
		printf("Case #%d:", i);
		double rr;
		for (j = 0; j < N; j++) {
			//re = ((double)(2 * X - s[j] - (N - 1) * s[j])) / (N * X);
			//if (re < 0) re = 0;
			if (bs.test(j)) 
				rr = 0;
			else {
				rr = ((double)xxx - s[j]) / X;
			}
			printf(" %.6lf", rr * 100);
		}
		printf("\n");
	}
	return 0;
}