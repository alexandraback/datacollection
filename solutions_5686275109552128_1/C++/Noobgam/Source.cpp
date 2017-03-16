#include <cstdio>
#include <ctime>
#include <cassert>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <random>
#include <set>
using namespace std;

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int cnt1 = 1;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		vector <int> a;
		a.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int p = *max_element(a.begin(), a.end());
		int result = 10000;
		for (int q = 1; q <= p; q++)
		{
			int cur = 0;
			for (int i = 0; i < n; i++)
				cur += (a[i] - 1) / q;
			result = min(cur + q, result);
		}
		printf("Case #%d: %d\n", cnt1, result);
		cnt1++;
	}
	return 0;
}