#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <numeric>
#include <utility>
#include <functional>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
	int nc;
	scanf("%d", &nc);
	for (int ci = 1; ci <= nc; ci++) {
		int n;
		static int a[1024], b[1024], d1[1024], d2[1024], s[1024];
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a[i], &b[i]);
			d1[i] = d2[i] = 0;
			s[i] = 2;
		}

		int ans = 0, m = 0;
		for ( ; ; ans++) {
			bool done = true;
			for (int i = 0; i < n; i++)
				if (d2[i] == 0) done = false;
			if (done) break;

			int best_i = -1, best = 0;
			for (int i = 0; i < n; i++) {
				if (d2[i] || m < b[i]) continue;
				if (best_i < 0)
					best_i = i;
			}
			if (best_i >= 0) {
				m += s[best_i];
				d1[best_i] = d2[best_i] = 1;
				s[best_i] = 0;
				continue;
			}

			best_i = -1;
			for (int i = 0; i < n; i++) {
				if (d1[i] || d2[i] || m < a[i]) continue;
				if (best_i < 0) best_i = i;
			}
			if (best_i >= 0) {
				m += 1;
				d1[best_i] = 1;
				s[best_i] = 1;
				continue;
			}
			break;	
		}
		bool done = true;
		for (int i = 0; i < n; i++)
			if (d2[i] == 0) done = false;
		
		if (done)
			printf("Case #%d: %d\n", ci, ans);
		else
			printf("Case #%d: Too Bad\n", ci);
	}

	return 0;
}
