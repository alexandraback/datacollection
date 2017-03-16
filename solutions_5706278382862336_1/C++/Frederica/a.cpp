#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<functional>
#include<cstdlib>
#include<list>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

long long x,y;
char ch;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

bool power2(long long x) {
	while (x != 1) {
		if (x & 1) return 0;
		x >>= 1;
	}
	return 1;
}

int main()
{
	freopen("A-large.in","r",stdin);
	int test;
    scanf("%d",&test);
	for (int t = 1; t <= test; ++ t) {
		printf("Case #%d: ",t);
		cin>>x>>ch>>y;
		long long d = gcd(x,y);
		x/=d, y/=d;
		if (! power2(y)) {
			puts("impossible");
			continue;
		}
		int ans = 0;
		while (x < (y >> 1)) {
			y >>= 1;
			++ ans;
		}
		if (ans > 40)
			puts("impossible");
		else
			printf("%d\n",ans + 1);
	}
	return 0;
}
