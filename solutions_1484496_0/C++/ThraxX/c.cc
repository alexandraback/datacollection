#include <vector>

#include <string>
#include <cstdio>

#include <algorithm>
#include <utility>
#include <cstring>

#include <map>
#include <set>

#include <cassert>

#include <numeric>
#include <bitset>

#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>

#include <cmath>
#include <complex>
#include <cstdlib>

#include <list>
#include <deque>
#include <queue>
#include <stack>

#include <functional>
#include <cctype>
#include <ctime>

using namespace std;

const int INF = 1000000000;

const double pi = acos(-1);
const double eps = 1e-8;
const long double ep = 1e-20;


#if 1
#define DBG(z) cerr << #z << ": " << (z) << endl
#define NEWL() cerr << endl;
#else
#define DBG(z)
#define NEWL()
#endif

#define fill(f, a) memset(f, a, sizeof(f))
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define for_each(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define next_int() ({int __t; scanf("%d", &__t); __t;})

int cnt[20 * 100000 + 1];

int main() {
	int t, n;
	t = next_int();
	for (int kase = 1; kase <= t; ++kase) {
		n = next_int();
		vector <int> s(n);
		for (int j = 0; j < n; ++j)
			s[j] = next_int();
		for (int msk = 1; msk < (1 << n); ++msk) {
			int su = 0;
			for (int j = 0, mj = 1; j < n; ++j, mj <<= 1)
				if (mj & msk)
					su += s[j];
			cnt[su]++;
		}
		int target = -1;
		for (int i = 0; i < n * 100000; ++i) {
			int su = i + 1;
			if (cnt[su] > 1) {
				target = su;
				break;
			}
		}
		vector <int> ans1, ans2;
		for (int msk = 1; msk < (1 << n); ++msk) {
			int su = 0;
			for (int j = 0, mj = 1; j < n; ++j, mj <<= 1)
				if (mj & msk)
					su += s[j];
			if (su == target && ans1.size() == 0) {
				for (int j = 0, mj = 1; j < n; ++j, mj <<= 1)
					if (mj & msk)
						ans1.push_back(s[j]);
				continue;
			}
			if (su == target && ans2.size() == 0) {
				for (int j = 0, mj = 1; j < n; ++j, mj <<= 1)
					if (mj & msk)
						ans2.push_back(s[j]);
				break;
			}
		}
		printf("Case #%d:\n", kase);
		for (int j = 0, ln = false; j < ans1.size(); ++j, ln = true) {
			if (ln)
				printf(" ");
			printf("%d", ans1[j]);
		}
		printf("\n");
		for (int j = 0, ln = false; j < ans2.size(); ++j, ln = true) {
			if (ln)
				printf(" ");
			printf("%d", ans2[j]);
		}
		printf("\n");

		fill(cnt, 0);
	}
    return 0;
}



