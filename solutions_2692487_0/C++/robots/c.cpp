#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>
using namespace std;
int rec (vector<int> &m,int a,int i = 0)
{
	if (i == m.size())
		return 0;
	if (m[i] < a)
	{
		return rec (m,a + m[i],i + 1);
	}
	else
	{
		int p = rec (m,a,i + 1) + 1;
		
		if (a <= 1)
			return p;
		int cnt = 0;
		int add = a;
		while (add <= m[i])
		{
			add += add - 1;
			cnt++;
		}
		int q = rec (m,add + m[i],i + 1) + cnt;
		return min (p,q);
	}
	return 0;
}
int main( )
{
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt2.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a,n,c;
		cin >> a >> n;
		vector<int> motes;
		for (int j = 0; j < n; j++)
		{
			cin >> c;
			motes.push_back (c);
		}
		sort (motes.begin(),motes.end());
		int it = 0;
		int ans = rec (motes,a);
		printf ("Case #%d: %d\n",i + 1,ans);
	}

	return 0;
}
