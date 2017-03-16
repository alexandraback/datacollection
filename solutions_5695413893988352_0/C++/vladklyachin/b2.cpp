#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

#define NN 20

int t;
char A[NN], B[NN];

int main() {
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%s%s", A, B);
		int sz = strlen(A);
		int64_t best_df = INT64_MAX;
		int64_t best_aa = INT64_MAX;
		int64_t best_bb = INT64_MAX;
		for (int i1 = 0; i1 < 10; ++i1) {
		for (int i2 = 0; i2 < 10; ++i2) {
		for (int i3 = 0; i3 < 10; ++i3) {
		for (int i4 = 0; i4 < 10; ++i4) {
		for (int i5 = 0; i5 < 10; ++i5) {
		for (int i6 = 0; i6 < 10; ++i6) {

		string a(A);
		string b(B);
		if (a[0] == '?') a[0] = '0' + i1;
		if (b[0] == '?') b[0] = '0' + i2;
		if (sz > 1 && a[1] == '?') a[1] = '0' + i3;
		if (sz > 1 && b[1] == '?') b[1] = '0' + i4;
		if (sz > 2 && a[2] == '?') a[2] = '0' + i5;
		if (sz > 2 && b[2] == '?') b[2] = '0' + i6;

		int64_t aa = strtoll(a.data(), nullptr, 10);
		int64_t bb = strtoll(b.data(), nullptr, 10);
		int64_t df = llabs(aa - bb);
		if (best_df > df ||
			(best_df == df && best_aa > aa) ||
			(best_df == df && best_aa == aa && best_bb > bb))
		{
			best_df = df; best_aa = aa; best_bb = bb;
		}

		}}}}}}
		printf("Case #%d: %0*lld %0*lld\n", ti+1, sz, best_aa, sz, best_bb);
		fflush(stdout);
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
