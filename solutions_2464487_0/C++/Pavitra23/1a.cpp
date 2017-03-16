#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

typedef unsigned long long ull;

#define REPI(i,s,n)  	for(int i=s;i<(n);++i)
#define FORI(i, n)		REPI(i, 0, n)


int main()
{
#if 0
	freopen("..//Debug//in.txt", "r", stdin); 
	freopen("..//Debug//out.txt", "w", stdout);
#endif
	int tc=0;

	ull r=0, t=0;
	scanf("%d\n", &tc);
	FORI(i, tc)
	{
		scanf("%llu %llu\n", &r, &t);
		ull sum=2*r + 1;
		ull ri=0;
		for(ri=1; t >=  sum; ri++)
			sum += 2*r + 4*ri + 1;

		printf("Case #%d: %llu\n", i+1, ri-1);
	}
	//====//
	return getchar();
}