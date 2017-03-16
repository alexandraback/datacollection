#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi = acos(-1.);
const double eps = 1e-6;

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	double c, f, x;
	int T, ca = 0;
	for (scanf("%d", &T); T; T--) {
		scanf("%lf%lf%lf", &c, &f, &x);
		double ans = x / 2., use = 0;
		for (int i = 1; ; i++) {
			use += c / ((i - 1) * f + 2);
			if (ans > use + x / (i * f + 2))
				ans = use + x / (i * f + 2);
			else
				break;
		}
		printf("Case #%d: %.7f\n", ++ca, ans);
	}
}
