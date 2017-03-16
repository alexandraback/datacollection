/*
 * Author: rush
 * Filename: C2.cpp
 * Timestamp: 06/05/2012 17:48:53 CST
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
#define FOR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long LL;

#define TWO(x) (1 << (x))

int T, N, M;
typedef pair<LL, int> PLI;
PLI a[105], b[105];

int main() {
	scanf("%d", &T);
	for (int id = 1; id <= T; ++id) {
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++i) scanf("%lld%d", &a[i].first, &a[i].second);
		for (int j = 0; j < M; ++j) scanf("%lld%d", &b[j].first, &b[j].second);
		
		LL ans = 0;
		if (N == 1) {
			LL sum = 0;
			for (int j = 0; j < M; ++j)
				if (b[j].second == a[0].second) sum += b[j].first;
			
			ans = max(ans, min(a[0].first, sum));
		} else if (N == 2) {
			for (int j = 0; j <= M; ++j) {
				LL tmp = 0;
				
				LL sum = 0;
				for (int k = 0; k < j; ++k)
					if (b[k].second == a[0].second) sum += b[k].first;
				tmp += min(a[0].first, sum);
				sum = 0;
				for (int k = j; k < M; ++k)
					if (b[k].second == a[1].second) sum += b[k].first;
				tmp += min(a[1].first, sum);
				
				ans = max(ans, tmp);
			}
		} else if (N == 3) {
			for (int j = 0; j <= M; ++j) {
				for (int t = j; t <= M; ++t) {
					LL tmp = 0;
					
					LL sum = 0;
					for (int k = 0; k < j; ++k)
						if (b[k].second == a[0].second) sum += b[k].first;
					tmp += min(a[0].first, sum);
					sum = 0;
					for (int k = j; k < t; ++k)
						if (b[k].second == a[1].second) sum += b[k].first;
					tmp += min(a[1].first, sum);
					sum = 0;
					for (int k = t; k < M; ++k)
						if (b[k].second == a[2].second) sum += b[k].first;
					tmp += min(a[2].first, sum);
					
					ans = max(ans, tmp);
				}
			}
		}
		
		for (int i = 0; i < N; ++i) {
			LL sum = 0;
			for (int k = 0; k < M; ++k)
				if (b[k].second == a[i].second) sum += b[k].first;
			LL sum2 = 0;
			for (int k = 0; k < N; ++k)
				if (a[k].second == a[i].second) sum2 += a[k].first;
			ans = max(ans, min(sum, sum2));
		}
		
		printf("Case #%d: %lld\n", id, ans);
	}
	return 0;
}
