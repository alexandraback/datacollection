#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound

const double eps = 1e-8;
const double pi = acos(-1.0);

int A, B;
double S[110000];
int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &A, &B);
		double p = 1;
		S[0] = 0.0;
		for (int i = 1; i <= A; i++) {
			double fail;
			scanf("%lf", &fail);
			fail = 1. - fail;
			S[i] = S[i - 1] + p * fail;
			p = p * (1. - fail);
		}
		double ans = B + 2;
		for (int i = 1; i <= A; i++) {
			ans = min(ans, S[i] * (A - i + B - i + 1 + B + 1) + (1. - S[i]) * (A - i + B - i + 1));
		}
		printf("Case #%d: %.9f\n", ++ca, ans);
	}
}
