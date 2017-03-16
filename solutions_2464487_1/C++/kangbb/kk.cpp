
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

unsigned long long search(
		unsigned long long r,
		unsigned long long t){
	unsigned long long beg = 0;
	unsigned long long end = ((unsigned long long)1 << 18);
	unsigned long long mid;
	unsigned long long area;

	do{
		mid = ( beg + end + 1) >> 1;
		area = ( 2 * mid - 1 + 2 * r );
		if( area <= t / mid ){
			beg = mid;
		}
		else
			end = mid-1;
	}while(beg < end);
	return end;
}

int main()
{
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &cases);
	while(cases--)
	{
		unsigned long long r, t;
		scanf("%llu%llu", &r, &t);
		printf("Case #%d: %llu\n", casenum++, search(r, t));
	}
	return 0;
}

