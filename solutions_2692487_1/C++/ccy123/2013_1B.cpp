// 2013_1B.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

#include <mpirxx.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(int A, vector<int>&v, int k=0)
{
	if (k > v.size())
		return v.size();
	if (v.size() == 0)
		return 0;

	if (A > v[0])
	{
		A += v[0];
		v.erase(v.begin());
		return calc(A, v);
	}
	
	int c2 = v.size();
	int c1 = calc(A+A-1, v, k+1) + 1; 


	if (c1 > c2)
		return c2;
	else
		return c1;
	
};

void PA(int num)
{
	int A;
	int n;
	cin >> A;
	cin >> n;
	vector<int> v(n);

	for(auto &item : v)
		cin >> item;

	sort(v.begin(), v.end());

	auto z = calc(A, v);


	printf("Case #%d: %d\n", num+1, z);
};

void PB(int num)
{
	printf("Case #%d:", num++);
};

void C(int num)
{
	printf("Case #%d:", num++);
};

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		PA(i);
	}
	
	return 0;
}

