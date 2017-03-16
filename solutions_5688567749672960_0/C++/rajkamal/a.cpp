#include <iostream>
#include <queue>
#include<cstdio>
#include<vector>
 
#define MAX 1111111
using namespace std;
 
int xx[MAX];
 
int xyz(int x)
{
	int abc = 0;
	while (x > 0)
	{
		abc = abc * 10 + (x % 10);
		x /= 10;
	}
	return abc;
}
 
queue<int> ns;
int main()
{
    int a,b,c;
	xx[1] = 1;
	ns.push(1);
	while (!ns.empty())
	{
		int x = ns.front();
		ns.pop();
		if (x + 1 < MAX and xx[x + 1] == 0)
		{
			xx[x + 1] = xx[x] + 1;
			ns.push(x + 1);
		}
		if (xyz(x) < MAX and xx[xyz(x)] == 0)
		{
			xx[xyz(x)] = xx[x] + 1;
			ns.push(xyz(x));
		}
	}
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		long long number;
		cin >> number;
		printf("Case #%d: %d\n", t, xx[number]);
	}
}
 
