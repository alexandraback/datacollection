/*
 * Author: rush
 * Filename: A.cpp
 * Timestamp: 06/05/2012 00:11:36 CST
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <utility>
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

int T, N;
struct data_t {
	int idx;
	double s, ans;
} data[205];

bool cmp(data_t const &a, data_t const &b) {
	return a.s < b.s;
}
bool cmp2(data_t const &a, data_t const &b) {
	return a.idx < b.idx;
}

int main() {
	scanf("%d", &T);
	for (int id = 1; id <= T; ++id) {
		scanf("%d", &N);
		FOR(i, N) scanf("%lf", &data[i].s), data[i].idx = i;
		
		sort(data, data + N, cmp);
		double sum = 0.0;
		FOR(i, N) sum += data[i].s;
		
		for (int i = N; i >= 2; --i) {
			double remain = sum * 2.0;
			for (int j = i; j < N; ++j)
				remain -= data[j].s;
			//double sum = 0.0;
			//FOR(j, i) sum += data[j].s;
			FOR(j, i) data[j].ans = (remain / i - data[j].s) / sum;
			for (int j = i; j < N; ++j)
				data[j].ans = 0.0;
				
			OUT(id);
			cerr << i << ": ";
			for (int k = 0; k < N; ++k) cerr << data[k].ans << " "; cerr << endl;
			
			bool ok = true;
			FOR(j, i) if (data[j].ans < 0.0) ok = false;
			if (ok) break;
		}
		
		sort(data, data + N, cmp2);
		printf("Case #%d:", id);
		FOR(i, N) {
			printf(" %.9f", data[i].ans * 100.0);
		}
		printf("\n");
	}
	return 0;
}
