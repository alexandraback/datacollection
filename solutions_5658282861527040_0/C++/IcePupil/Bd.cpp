#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int TestCase, A, B, C;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &TestCase);
	for (int Case = 1; Case <= TestCase; Case ++) {
		scanf("%d%d%d", &A, &B, &C);
		long long ret = 0;
		for (int i = 0; i < A; i ++) {
			for (int j = 0; j < B; j ++)
			if ((i & j) < C) {
				ret ++;
			}
		}
		printf("Case #%d: %I64d\n", Case, ret);
	}
	return 0;
}
