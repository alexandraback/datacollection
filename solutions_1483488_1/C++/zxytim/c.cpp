#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

using namespace std;

int length(int a)
{
	if (a == 0)
		return 1;
	int n = 0;
	while (a)
		n ++, a /= 10;
	return n;
}

int tens[10];
int move(int n, int len)
{
	return n % 10 * tens[len - 1] + n / 10;
}

bool is_recycle(int a, int b)
{
	if (a == b)
		return false;
	int len = length(b);
	if (length(a) != length(b))
		return false;
	if (len == 1)
		return false;
	if(a == 12 && b == 21)
		int asdf = 0;
	for (int i = 0; i < len - 1; i ++)
	{
		b = move(b, len);
		if (b / tens[len - 1])
			if (a == b)
				return true;
	}
	return false;
}

int nrecycle(int n, int L, int R)
{
	int t = n, len = length(n), ret = 0;
	do
	{
		t = move(t, len);
		if (t >= tens[len - 1] && t < n && t >= L && t <= R)
			ret ++;
	} while (t != n);
	return ret;
}

void solve(int id)
{
	int L, R;
	scanf("%d%d", &L, &R);
	int ans = 0;
	tens[0] = 1;
	for (int i = 1; i <= 9; i ++)
		tens[i] = tens[i - 1] * 10;
	for (int n0 = L; n0 <= R; n0 ++)
		ans += nrecycle(n0, L, R);
	/*
	for (int n0 = L; n0 <= R; n0 ++)
		for (int n1 = n0 +1; n1 <= R; n1 ++)
			ans += is_recycle(n0, n1);
	*/
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i ++)
	{
		printf("Case #%d: ", i);
		solve(i);
	}
	return 0;
}

