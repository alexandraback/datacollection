#include <cstdio>
#include <iostream> 
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>

using namespace std;
/*
bool isPal(long long n)
{
	int q = 0;
	long long tn, tn1 = 10;
	for(tn = 1; ; tn *= 10, ++q)
		if(n / tn == 0)
			break;
	tn /= 10;
	while(tn >= tn1)
	{
		long long n1 = (n / tn) % 10;
		long long n2 = (n % tn1) / (tn1 / 10);
		if(n1 != n2)
			return false;
		tn /= 10;
		tn1 *= 10;

	}
	return true;
}*/

long long mas[] = {
1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001,
10221412201,
12102420121,
12345654321,
40000800004,
1000002000001,
1002003002001,
1004006004001,
1020304030201,
1022325232201,
1024348434201,
1210024200121,
1212225222121,
1214428244121,
1232346432321,
1234567654321,
4000008000004,
4004009004004,
100000020000001,
100220141022001,
102012040210201,
102234363432201,
121000242000121,
121242363242121,
123212464212321,
123456787654321,
400000080000004
};

int main()
{
	freopen("C-large-1.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	long long a, b;
	cin >> t;
	for(int tt = 0; tt < t; ++tt)
	{
		cin >> a >> b;
		int ans = 0;
		for(int i = 0; ; ++i)
		{
			if(mas[i] > b)
				break;
			if(mas[i] >= a)
				++ans;
		}
		printf("Case #%d: %d\n", tt+1, ans);
	}

	return 0;
}