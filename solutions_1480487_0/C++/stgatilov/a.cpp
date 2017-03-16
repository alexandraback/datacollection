#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 256;

int n;
int arr[SIZE];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d", &n);
		for (int i = 0; i<n; i++) scanf("%d", &arr[i]);

		int all = 0;
		for (int i = 0; i<n; i++) all += arr[i];

		printf("Case #%d:", tt);

		for (int i = 0; i<n; i++) {
			double left = 0.0;
			double right = 1.0;

			while (right - left > 1e-12) {
				double middle = (left + right) * 0.5;

				double sum = middle;
				for (int j = 0; j<n; j++) if (i != j) {
					double need = middle - double(arr[j] - arr[i]) / all;
					if (need < 0.0) need = 0.0;
					sum += need;
				}

				if (sum < 1.0) left = middle;
				else right = middle;
			}

			printf(" %0.12lf", 100.0 * left);
		}

		printf("\n");
		fflush(stdout);
	}
	return 0;
}
