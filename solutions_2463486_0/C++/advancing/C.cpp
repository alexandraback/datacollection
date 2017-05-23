#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL d[] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001, 100220141022001, 102012040210201, 102234363432201, 121000242000121, 121242363242121, 123212464212321, 123456787654321, 400000080000004};

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	int M = sizeof(d) / sizeof(LL);
	
	int T;    cin >> T;
	LL A, B;
	for(int cas = 1; cas <= T; cas ++)
	{
		scanf("%lld %lld", &A, &B);
		int ans = 0;
		for(int i = 0; i < M; i ++) if(d[i] >= A && d[i] <= B)  ans ++;

		printf("Case #%d: %d\n", cas, ans);

	}
	return 0;	
}