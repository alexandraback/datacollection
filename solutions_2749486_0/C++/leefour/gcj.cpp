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

typedef long long int64;
const double pi = acos (-1.0);
const double eps = 1.0e-10;

void solve()
{
	int x, y;
	scanf("%d%d", &x, &y);
	if (x > 0) {
		for (int i = 0; i < x; ++i)
			printf("WE");
	}
	if (x < 0) {
		for (int i = 0; i < -x; ++i)
			printf("EW");
	}
	if (y > 0) {
		for (int i = 0; i < y; ++i)
			printf("SN");
	}
	if (y < 0) {
		for (int i = 0; i < -y; ++i)
			printf("NS");
	}
	printf("\n");
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	for (int icase = 1; icase <= ncase; ++icase) {
		printf("Case #%d: ", icase);
		solve();
	}
}
