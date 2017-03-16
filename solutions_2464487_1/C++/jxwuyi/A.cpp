#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<cassert>
#include<complex>
using namespace std;

#define LL long long

LL run()
{
	LL r, t;
	scanf("%lld %lld", &r, &t);
	//cerr << r << " "  << t << endl;
	++r;
	LL lo = 0, hi = 10 + (t + 1 >> 1), mid;
	while(lo + 1 < hi)
	{
		mid = lo + hi >> 1;
		// assert (mid * (r - mid + 1)) <= t
		if(mid > t / (2 * r + 2 * mid - 3)) hi = mid;
		//if(2 * mid * (r + mid - 1) > t) hi = mid;
		else lo = mid;
	}
	return lo;
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	int test;scanf("%d",&test);
	for(int no=1;no<=test;++no)
		printf("Case #%d: %lld\n", no, run());
}
