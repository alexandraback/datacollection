
#include <iostream>
using namespace std;

int n, m;
char ans[200];
char str[200];
int rep[200][200];
int arr[200];
__int64 p, q;
bool flag = true;
int cmp(const void*a, const void*b) {
	return *(int*)a - *(int*)b;
}
__int64 gcd(__int64 x, __int64 y) {
	if (y % x == 0) {
		return x;
	} else {
		return gcd(y, x % y);
	}
}
int solve(__int64 x, __int64 y) {
	if (x >= y)
	{
		while (y > 1)
		{
			if (y % 2 == 0)
			{
				y /= 2;
			} else {
				flag = false;
				return 0;
			}
		}
		return 0;
	} else {
		if (y % 2 == 0)
		{
			return solve(x, y/2) + 1;
		} else {
			flag = false;
			return 0;
		}
	}
}
void solve(int tc)
{
	char str[100];
	flag = true;
	scanf("%s", &str);
	p = q = 0;
	int i;
	for (i = 0; str[i] != '/'; i++)
	{
		p *= 10;
		p += (str[i] - '0');
	}
	for (i++; str[i] != 0; i++)
	{
		q *= 10;
		q += (str[i] - '0');
	}
	__int64 g = gcd(p, q);
	p /= g;
	q /= g;
	int rt = solve(p, q);
	if (flag)
	{
		printf("Case #%d: %d\n", tc, rt);
	} else {
		printf("Case #%d: impossible\n", tc);
	}
	
	
}
int main()
{
//	freopen("c:\\data\\r1\\A-small-attempt0 (1).in", "r", stdin);
//	freopen("c:\\data\\r1\\A-small-attempt0 (1).out", "w", stdout);
	
	int tc;
	scanf("%d", &tc);
	int i;
	for (i = 1; i <= tc; i++)
	{
		solve(i);
	}
	return 0;
}