#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <climits>
#include <cfloat>
#include <memory>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <bitset>
#include <queue>
#include <complex>
#include <utility>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

const double EPS = 0.0000000001;
const long long int INF = 1000000000;

const int MAX_D = 1000;

int D;
int P[MAX_D];

int solve()
{
	int lb = 0, ub = 1000;
	while (ub - lb > 1) {
		int mb = (ub + lb) / 2;
		// Use i turn, change all plates to have at most mb - i cakes.
		bool ok = false;
		for (int i = 0; !ok && i < mb; ++i) {
			int t = 0;
			int k = mb - i;
			for (int j = 0; j < D; ++j) {
				t += (P[j] - 1) / k;
			}
			ok = t <= i;

			//printf("mb: %d, i: %d, t: %d\n", mb, i, t);
		}

		if (ok) ub = mb;
		else lb = mb;
	}

	return ub;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d", &D);
		for (int j = 0; j < D; ++j)
			scanf("%d", &P[j]);

		printf("Case #%d: %d\n", i + 1, solve());
	}

	return 0;
}

