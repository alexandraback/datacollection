#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;
inline long gcd ( long a, long b )
{
	long c;
	while ( a != 0 ) {
		c = a; a = b%a;  b = c;
	}
	return b;
}
int main()
{
	int T;
	long p,q;
	scanf("%d",&T);
	for (int iT=1; iT<=T; ++iT) {
		scanf("%ld/%ld",&p,&q);
		long ans=ceil(log2(q)-log2(p));
		if (log2(q/gcd(p,q))!=int(log2(q/gcd(p,q)))) {
			printf("Case #%d: impossible\n",iT);
		}
		else
			printf("Case #%d: %ld\n",iT,ans);
	}
    return 0;
}