#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int sz = 0;
long long a[1000005];

long long pw[15] = {0};

bool Check(long long v)
{
	int ln = 0;
	long long t = v;
	while(t > 0)
	{
		ln++;
		t /= 10;
	}
	t = v;
	while(ln > 0)
	{
		if(t / pw[ln-1] != t % 10)
			return 0;
		t = (t % pw[ln-1]) / 10;
		ln -= 2;
	}
	return 1;
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	
	pw[0] = 1;
	for(int i = 1; i < 15; i++)
		pw[i] = pw[i-1]*10;

	a[sz++] = 1;
	long long vl = 1;
	for(int i = 2; i < 10000000; i++)
	{
		vl += i+i-1;
		if(Check(i) && Check(vl))
			a[sz++] = vl;
	}

	int T, tc = 1;
	scanf("%d", &T);
	while(T > 0)
	{
		printf("Case #%d: ", tc);
		long long l, r;
		scanf("%lld%lld", &l, &r);

		int cl = lower_bound(a, a + sz, l) - a, cr = lower_bound(a, a + sz, r+1) - a;
		printf("%d\n", cr - cl);

		T--;
		tc++;
	}

	/*
	printf("%d\n", a.size());
	for(int i = 0; i < a.size(); i++)
		printf("%lld\t%lld\n", a[i], a[i]*a[i]);
	*/

	return 0;
}