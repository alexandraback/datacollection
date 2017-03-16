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

int n;
char s[10000];

int solve()
{
	int res = 0;
	int t = 0;

	for (int i = 0; i <= n; ++i) {
		if (t < i) {
			res += i - t;
			t = i;
		}
		t += s[i] - '0';
	}

	return res;
}

int main()
{
	int c;
	scanf("%d", &c);
	for (int i = 1; i <= c; ++i) {
		scanf("%d", &n);
		scanf("%s", s);
		printf("Case #%d: %d\n", i, solve());
	}

	return 0;
}

