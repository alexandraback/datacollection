#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;

void invert(char *l, char *r)
{
	while (l < --r) {
		char t = *l;
		*l = *r;
		*r = t;
		l++;
	}
}

void solve()
{
	char ss[16];
	char *s = ss;
	scanf("%s", s);
	while (s[0] == '0') s++;
	int n = strlen(s);
	int k = (n +1) /2;
	int w = atoi(s + n - k);
	if (0 == w) {
		int i = 0;
		for (; i < k; i++) {
			s[n - i -1] = '9';
		}
		bool r = 1;
		for (; i < n; i++) {
			if (r) --s[n - i -1];
			r = ('0' > s[n - i -1]);
			if (r) s[n -i -1] = '9';
		}
		assert(!r);
		while (s[0] == '0') s++;
		n = strlen(s);
		k = (n +1) /2;
		w = atoi(s + n - k);
		assert(0 != w);
	}
	int res = w;
	if (1 == n) {
		printf("%i", res);
		return;
	}
	invert(s, s + n);
	int x = atoi(s + k);
	res += (1 == x)? 0: x;
	int p = 1;
	while (k) {
		p *= 10;
		--k;
	}
	res += p -1;
	while (--n > 1) {
		if (n %2) p /= 10;
		res += p *2 -1;
	}
	res++;
	printf("%i", res);
}

int main()
{
	int t;
	scanf("%i", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%i: ", i +1);
		solve();
		printf("\n");
	}
	return 0;
}

