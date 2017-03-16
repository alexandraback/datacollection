#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1234;
int f[maxn];
void reverse(char *s, int len)
{
	for(int i = 0; i < len - 1 - i; ++i)
		swap(s[i], s[len - 1 - i]);
}
long long solve(long long n)
{
	if(n < 1000)
		return f[n];
	char str[20];
	sprintf(str, "%lld", n);
	int len = strlen(str);
	long long want = 0, ret;
	for(int i = 0; i < len >> 1; ++i)
		want = want * 10 + 9;
	for(int i = len >> 1; i < len - 1; ++i)
		want = want * 10;
	++want;
	ret = n - want;
	{
		long long tmp = 0, now;
		for(int i = len + 1 >> 1; i < len; ++i)
			str[i] = '0';
		str[len - 1] = '1';
		sscanf(str, "%lld", &now);
		tmp += n - now + 1;
		reverse(str, len);
		sscanf(str, "%lld", &now);
		tmp += now - want;
		if(tmp < ret)
			ret = tmp;
	}
	return ret + solve(want);
}
int main()
{
	int t;
	long long n;
	memset(f, 0x3f, sizeof f);
	f[1] = 1;
	for(int i = 1; i < 1000; ++i)
	{
		if(f[i + 1] > f[i] + 1)
			f[i + 1] = f[i] + 1;
		int j = i, k = 0;
		while(j)
		{
			k = k * 10 + j % 10;
			j /= 10;
		}
		if(k > i && f[k] > f[i] + 1)
			f[k] = f[i] + 1;
	}
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i)
	{
		scanf("%lld", &n);
		printf("Case #%d: %lld\n", i, solve(n));
	}
	return 0;
}
