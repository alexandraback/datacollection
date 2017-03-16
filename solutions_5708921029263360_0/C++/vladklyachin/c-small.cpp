#include <algorithm>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <strstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
typedef int64_t i64;
typedef double dbl;

#define NN 12*12*12

int t;
int J, P, S, K;

int main()
{
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%d%d%d%d", &J, &P, &S, &K);
		int count = J*P*S;
		int cases = 1 << count;
		vector<int> vj;
		vector<int> vp;
		vector<int> vs;
		vj.reserve(count);
		vp.reserve(count);
		vs.reserve(count);
		for (int j = 0; j < J; ++j) {
			for (int p = 0; p < P; ++p) {
				for (int s = 0; s < S; ++s) {
					vj.push_back(j);
					vp.push_back(p);
					vs.push_back(s);
				}
			}
		}
#if DEBUG
		for (int v = 0; v < count; ++v) {
			printf("COMPLEX %d: %d %d %d\n", v, vj[v], vp[v], vs[v]);
		}
#endif
		vector<int> dj;
		vector<int> dp;
		vector<int> ds;
		dj.reserve(count);
		dp.reserve(count);
		ds.reserve(count);
		int bestDays = 0;
		int bestMask = 0;
		if (K >= S) {
			bestDays = count;
			bestMask = cases-1;
		} else {
			for (int mask = 1; mask < cases; mask += 2) {
				dj.clear();
				dp.clear();
				ds.clear();
				for (int bit = 0; bit < count; ++bit) {
					if (mask & (1 << bit)) {
						dj.push_back(vj[bit]);
						dp.push_back(vp[bit]);
						ds.push_back(vs[bit]);
					}
				}
				int days = dj.size();
#if DEBUG
				printf("-----\nCASE:%d\n", mask);
				for (int d = 0; d < days; ++d) {
					printf("DAY %d: %d %d %d\n", d, dj[d], dp[d], ds[d]);
				}
#endif
				bool ok = true;
				// verify j&p
				for (int j = 0; j < J; ++j) {
					for (int p = 0; p < P; ++p) {
						int count = 0;
						for (int d = 0; d < days; ++d) {
							if (dj[d] == j && dp[d] == p) {
								++count;
							}
						}
						if (count > K) {
							ok = false;
#if DEBUG
							printf("count=%d j=%d p=%d\n", count, j, p);
#endif
						}
					}
				}
				// verify j&s
				for (int j = 0; j < J; ++j) {
					for (int s = 0; s < S; ++s) {
						int count = 0;
						for (int d = 0; d < days; ++d) {
							if (dj[d] == j && ds[d] == s) {
								++count;
							}
						}
						if (count > K) {
							ok = false;
#if DEBUG
							printf("count=%d j=%d s=%d\n", count, j, s);
#endif
						}
					}
				}
				// verify p&s
				for (int p = 0; p < P; ++p) {
					for (int s = 0; s < S; ++s) {
						int count = 0;
						for (int d = 0; d < days; ++d) {
							if (dp[d] == p && ds[d] == s) {
								++count;
							}
						}
						if (count > K) {
							ok = false;
#if DEBUG
							printf("count=%d p=%d s=%d\n", count, p, s);
#endif
						}
					}
				}
				if (ok) {
					if (bestDays < days) {
						bestDays = days;
						bestMask = mask;
					}
#if DEBUG
					printf("mask:%d OK days:%d\n", mask, days);
#endif
				}
			}
		}
		printf("Case #%d: %d\n", ti+1, bestDays);
		dj.clear();
		dp.clear();
		ds.clear();
		for (int bit = 0; bit < count; ++bit) {
			if (bestMask & (1 << bit)) {
				dj.push_back(vj[bit]);
				dp.push_back(vp[bit]);
				ds.push_back(vs[bit]);
			}
		}
		int days = dj.size();
		for (int d = 0; d < days; ++d) {
			printf("%d %d %d\n", dj[d]+1, dp[d]+1, ds[d]+1);
		}
		fflush(stdout);
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
