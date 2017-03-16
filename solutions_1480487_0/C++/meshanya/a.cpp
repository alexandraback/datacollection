#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <map>
#include <sstream>
#include <algorithm>
#include <vector>
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define taskname "a"
using namespace std;

const int N = 1000;
const double eps = 1e-10;
int a[N], t, n, sum;

int main() {
	freopen(taskname".in", "r", stdin);
	freopen(taskname".out", "w", stdout);
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d", &n);
		sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		printf("Case #%d:", it + 1);
		for (int i = 0; i < n; ++i) {
			double l = 0, r = 1;
			while (r - l > eps) {
				double q = (l + r) / 2, score = a[i] + q * sum, cur = 0;
				for (int j = 0; j < n; ++j)
					if (j != i)
						cur += max(0.0, (score - a[j]) / sum);
				if (cur + q < 1 - eps)
					l = q;
				else 
					r = q;
			}
			printf(" %.10lf", 100 * l);
		}
		printf("\n");
	}
	return 0;
}