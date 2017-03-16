#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 10000100
#define INF 1000000000

int a[MAXN];
int b[15];
bool check(long long x) {
	int k = 0;
	while (x) {
		b[++k] = x % 10;
        x /= 10;
	}
	for (int i = 1; i <= k / 2; i++)
		if (b[i] != b[k - i + 1])
			return 0;
	return 1; 
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	for (int i = 1; i <= 10000000; i++) {
		if (check(i)) {
			long long x = (long long)i * i;
			if (check(x))
				a[i]++;
		}
	}

	for (int i = 1; i <= 10000000; i++)
		a[i] += a[i - 1];
	int test;
	scanf("%d", &test);
	for (int i = 0; i < test; i++) {
		long long xa, xb;
		cin >> xa >> xb;		
		int p1 = (int)sqrt(xb + .0);
		int p2 = (int)sqrt(xa + .0);
		int ans = a[p1] - a[p2 - 1];
		if (check(p2) && check((long long)p2 * p2))
			if ((long long)p2 * p2 < xa)
				ans--;
		printf("Case #%d: %d\n", i + 1, ans);
	}
}