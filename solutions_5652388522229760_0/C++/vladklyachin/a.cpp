#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int t;
int64_t n;

int64_t solve(int64_t N)
{
	char used[16];
	char buffer[64];
	int count = 0;

	memset(used, 0, sizeof(used));
	for (int64_t i = 1; true; ++i) {
		snprintf(buffer, sizeof(buffer), "%lld", N*i);
		for (char * p = buffer; *p != '\0'; ++p) {
			if (!used[*p - '0']) {
				used[*p - '0'] = true;
				++count;
				if (count == 10) {
					return N*i;
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%lld", &n);
		if (n == 0) {
			printf("Case #%d: INSOMNIA\n", ti+1);
		} else {
			printf("Case #%d: %lld\n", ti+1, solve(n));
		}
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
