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
		int n, total = 0;
		static int a[1000];

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			total += a[i];
		}
		double c = total * 2;
		double t = (double) total * 2 / n;
		printf("Case #%d:", ci);
		int num = 0, m = 0;
		for (int i = 0; i < n; i++)
			if (a[i] < t) {
				m += a[i];
				num++;
			}
		double tt = (double) (total + m) / num;
		for (int i = 0; i < n; i++) {
			if (a[i] >= t) printf(" %f", 0.0);
			else printf(" %f", (double) (tt - a[i]) * 100.0 / total);
		}
		printf("\n");
	}

	return 0;
}
