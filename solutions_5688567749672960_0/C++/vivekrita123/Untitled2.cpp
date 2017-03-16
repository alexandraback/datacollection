#include<bits/stdc++.h>
#include <iostream>
#include <queue>
#include<cstdio>
#include<vector>
 
#define MAX 1111111
using namespace std;
 
int man[MAX];
 
int reverse(int num)
{
	int xyz = 0;
	while (num > 0)
	{
		xyz = xyz * 10 + (num % 10);
		num /= 10;
	}
	return xyz;
}
 
queue<int> ns;
int main()
{
    int a,b,c;
	man[1] = 1;
	ns.push(1);
	while (!ns.empty())
	{
		int x = ns.front();
		ns.pop();
		if (x + 1 < MAX and man[x + 1] == 0)
		{
			man[x + 1] = man[x] + 1;
			ns.push(x + 1);
		}
		if (reverse(x) < MAX and man[reverse(x)] == 0)
		{
			man[reverse(x)] = man[x] + 1;
			ns.push(reverse(x));
		}
	}
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		long long number;
		cin >> number;
		printf("Case #%d: %d\n", t, man[number]);
	}
}
 
