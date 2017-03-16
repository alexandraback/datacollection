/*
 * a.cpp
 *
 *  Created on: May 4, 2013
 *      Author: AhmedHamza
 */

#include<cstdio>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int arr[100000];
int tc, a, n;

map<pair<ll, pair<int, int> > , int> mem;

int dp(ll sum, int i, int j)
{
	pair<ll, pair<int, int> > p = make_pair(sum, make_pair(i, j));
	if (mem.find(p) != mem.end())
		return mem[p];
	while (i < n && sum > arr[i])
		sum += arr[i++];
	if (i > j)
		return 0;
	int mn = dp(sum, i, j - 1);
	if (sum - 1)
		mn = min(mn, dp(sum + sum - 1, i, j));
	return mem[p] = mn + 1;
}

int main()
{
//	freopen("a.in", "rt", stdin);
		freopen("A-small-attempt0 (1).in", "rt", stdin);
		freopen("a.txt1", "wt", stdout);
	scanf("%d", &tc);
	for (int T = 1; T <= tc; ++T)
	{
		scanf("%d%d", &a, &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", arr + i);
		sort(arr, arr + n);
		//		ll sum = a;
		//		int i;
		//		for (i = 0; i < n && sum > arr[i]; ++i)
		//			sum += arr[i];
//		cerr << T << endl;
		mem.clear();
		printf("Case #%d: %d\n", T, dp(a, 0, n - 1));
//		for (__typeof(mem.begin()) it = mem.begin(); it != mem.end(); ++it)
//			cerr << it->first.first << ", " << it->first.second.first << ", " << it->first.second.second << " = " << it->second << endl;
	}
	return 0;
}

