#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

//#define SMALL
#define LARGE

using namespace std;

char inp[1000005];
int n, num;
long long ans;

bool is_vowel(const char& c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u')
		return true;
	return false;
}

void check() {
	int len = strlen(inp);
	int d = 0, left = 0;
	for (int i = 0; i < len; ++i) {
		if (!is_vowel(inp[i]))
			d++;
		else
			d = 0;
		if (d >= n) {
			ans += 1LL * (len - i) * (i - n - left + 2);
			left = i - n + 2;
			num++;
		}
	}
}

int main()
{
#ifdef SMALL
	freopen("A_small.in", "r", stdin);
	freopen("A_small.out", "w", stdout);
#endif
#ifdef LARGE
	freopen("A_large.in", "r", stdin);
	freopen("A_large.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int Case = 1; Case <= t; ++Case) {
		scanf("%s %d", inp, &n);
		int len = strlen(inp);
		num = ans = 0;
		check();
//		printf("%d %lld\n", num, ans);
		printf("Case #%d: %lld\n", Case, ans);
	}
	return 0;
}
