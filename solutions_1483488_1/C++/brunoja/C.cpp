#include <cstdio>
#include <set>

using namespace std;

int numdigs(int num)
{
	int res= 0;
	while (num) num /= 10, ++res;
	return res;
}

int calc(int num, int a, int b)
{
	int ori = num, res = 0, dig = numdigs(num), ten = 1;
	for (int i = 1; i < dig; ++i) ten *= 10;
	
	set<int> gone;
	
	for (int i = 0; i < dig; ++i)
	{
		int aux = num%10;
		num /= 10;
		num += aux*ten;
		if (num > ori && num <= b && !gone.count(num)) ++res, gone.insert(num);
	}
	
	//if (res) printf("%d = %d\n", ori, res);
	
	return res;
}

int solve(int a, int b)
{
	int res = 0;
	for (int i = a; i <= b; ++i)
		res += calc(i,a,b);
	return res;
}

int main()
{
	int t, a, b;
	//printf("%d\n", calc(12345, 1, 1111111));
	scanf("%d", &t);
	
	for (int q = 1; q <= t; ++q)
	{
		printf("Case #%d: ", q);
		scanf("%d%d", &a, &b);
		printf("%d\n", solve(a, b));
	}
	
	return 0;
}

