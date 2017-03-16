#include<bits/stdc++.h>
 
#define MAX 1111111
using namespace std;
 
int arr[MAX];
 
int func(int x)
{
	int a = 0;
	while (x > 0)
	{
		a = a* 10 + (x % 10);
		x /= 10;
	}
	return a;
}
 
queue<int> ns;
int main()
{
    int a,b,c;
	arr[1] = 1;
	ns.push(1);
	while (!ns.empty())
	{
		int x = ns.front();
		ns.pop();
		if (x + 1 < MAX and arr[x + 1] == 0)
		{
			arr[x + 1] = arr[x] + 1;
			ns.push(x + 1);
		}
		if (func(x) < MAX and arr[func(x)] == 0)
		{
			arr[func(x)] = arr[x] + 1;
			ns.push(func(x));
		}
	}
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		long long num;
		cin >> num;
		printf("Case #%d: %d\n", t, arr[num]);
	}
}
 
