#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <sstream>
#include <bitset>
#include <ctime>
using namespace std;

typedef long long LL;

LL l, r;
#define MAXN 10000001
int data[MAXN];

int q[10];

bool ok(int x)
{
	LL y = x;
	int wei = 0;
	while (x)
	{
		q[wei++] = x % 10;
		x /= 10;
	}
	for (int i = 0, j = wei - 1; i < j; ++i, --j)
		if (q[i] != q[j]) return false;
	y *= y;
	wei = 0;
	while (y)
	{
		q[wei++] = y % 10;
		y /= 10;
	}
	for (int i = 0, j = wei - 1; i < j; ++i, --j)
		if (q[i] != q[j]) return false;
	return true;
}

int main()
{
	int T, cases = 0;
	scanf("%d", &T);
	data[0] = 0;
	for (int i = 1; i < MAXN; ++i)
		data[i] = data[i - 1] + (ok(i) ? 1 : 0);
/*	for (int i = 1; i < 1000; ++i)
		if (data[i] > data[i - 1])
			cout << i << ' ' << i * i << endl;
	cout << endl;*/
	while (T--)
	{
		printf("Case #%d: ", ++cases);
		scanf("%lld%lld", &l, &r);
		int left = LL(ceil(sqrt(l*1.0)));
		int right = LL(floor(sqrt(r*1.0)));
//		cout << left << ' ' << right << endl;
		printf("%d\n", data[right] - data[left - 1]);
	}
	return 0;
}
