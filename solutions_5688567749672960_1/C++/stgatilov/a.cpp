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
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

int64 n;

char buff[256];
int64 rev(int64 x) {
	sprintf(buff, "%I64d", x);
	int k = strlen(buff);
	std::reverse(buff, buff+k);
	sscanf(buff, "%I64d", &x);
	return x;
}
/*
static const int ALL = 1<<20;
int dist[ALL], father[ALL];

vector<int64> PrintPath(int64 x) {
	vector<int64> path;
	while (x > 1) {
		path.push_back(x);
		printf("%I64d <- \n", x);
		x = father[x];
	}
	path.push_back(1);
	printf("1\n");
	return path;
}*/


static const int MAXD = 15;
int dig[MAXD+1];
int64 pow10[MAXD+1];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

/*	vector<int64> qarr;
	dist[1] = 1;
	qarr.push_back(1);
	for (int i = 0; i < qarr.size(); i++) {
		int x = qarr[i];
		for (int t = 0; t < 2; t++) {
			int y = (t == 0 ? x + 1 : rev(x));
			if (y >= ALL || dist[y] > 0)
				continue;
			dist[y] = dist[x] + 1;
			father[y] = x;
			qarr.push_back(y);
		}
	}

	PrintPath(173948);
	for (int i = 1; i <= 1000; i++) {
		printf("%d: %d\n", i, dist[i]);
	}
	for (int i = 1; i <= 1000000; i++) {
		auto q = PrintPath(1);
		int cc = 0;
		for (int j = 0; j+1 < q.size(); j++)
			cc += (q[j+1] - q[j] != 1);
		assert(cc <= 1);
	}*/

	pow10[0] = 1;
	for (int i = 0; i < MAXD; i++) pow10[i+1] = pow10[i] * 10;

	dig[1] = 0;
	for (int i = 1; i < MAXD; i++) {
		int tres = dig[i];
		tres += pow10[i/2];
		tres += pow10[(i+1)/2] - 1;
		dig[i+1] = tres;
	}
	dig[1]++;
	for (int i = 1; i<=MAXD; i++) Ef("%d -> %d\n", i, dig[i]);

	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%I64d", &n);

		int dd = 1;
		while (pow10[dd] <= n) dd++;
		Eo(n);
		Eo(dd);

		int64 ans = 1000000000000LL;
		int bnd = min(pow10[dd/2+1], 11000000LL);
		Eo(bnd);

		int64 curr = pow10[dd-1];
		int64 crev = rev(curr);
		char tbuff[256];
		sprintf(tbuff, "%I64d", curr);
		reverse(tbuff, tbuff + dd);
		for (int incr = 0; incr <= bnd; incr++) {
			int64 tmp = curr;

			if (tmp == n) {
				ans = min(ans, int64(dig[dd]) + incr);
				break;
			}
			if (tmp >= pow10[dd])
				break;

			//tmp = rev(tmp);
			tmp = crev;

			curr++;
            for (int i = 0; i < dd; i++) {
            	tbuff[i]++;
            	crev += pow10[dd - 1 - i];
            	if (tbuff[i] != '9' + 1)
            		break;
            	tbuff[i] -= 10;
            	crev -= pow10[dd - 1 - i] * 10;
            }


			if (tmp > n)
				continue;
			int64 tres = dig[dd] + incr + (n - tmp) + 1;
//			Ef("%d -> %d\n", int(incr), int(tres));
			ans = min(ans, tres);
		}

		Ef("\n");
		printf("Case #%d: %I64d\n", tt, ans);
		fflush(stdout);
	}
	return 0;
}
