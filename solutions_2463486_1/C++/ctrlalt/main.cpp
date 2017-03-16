#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

int comp(const void *a, const void *b) {
	return (*(int *)a) - (*(int *)b);
}

bool pal(__int64 n) {
	int c = 0, a[110];
	while (n) {
		a[c++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < c / 2; i++)
		if (a[i] != a[c - i - 1])
			return 0;
	return 1;
}

__int64 a, b, ans[] = { 0, 1, 4, 9, 
						121, 484, 
						10201, 12321, 14641, 40804, 44944, 
						1002001, 1234321, 4008004,
						100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404,
						10000200001, 10221412201, 12102420121, 12345654321, 40000800004,
						1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004,
						100000020000001, 100220141022001, 102012040210201, 102234363432201, 121000242000121, 121242363242121, 123212464212321, 123456787654321, 400000080000004 };

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
	int n;
	scanf("%d", &n);
	for (int t = 1; t <= n; t++) {
		int cnt = 0;
		scanf("%I64d%I64d", &a, &b);
		for (int i = 0; i < 49; i++)		
			if (a <= ans[i] && ans[i] <= b)
				cnt++;
		printf("Case #%d: %d\n", t, cnt);
	}
	return 0;
}