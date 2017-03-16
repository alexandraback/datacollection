#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
ull d8 = 1000000000000000000LL;
ull r,t;

bool too_high(ull k)
{
    //(k+1)(2k+2r+1) > t
    double a = (double) k+1;
    double b = (double) 2*k + 2*r + 1;
    if(a*b > (double) 5*d8)
	return true;
    else
	return (((ull) k+1)*((ull)2*k + 2*r + 1) > t);
}
	    
int main()
{
    int nb_cas;
    scanf("%d", &nb_cas);
    for(int cas = 1; cas <= nb_cas; cas++)
    {
	scanf("%llu%llu",&r,&t);
	ull lb = (ull)0;
	ull ub = 1000000000LL;
	while(ub - lb > 0)
	{
	    ull mid = (ub+lb+1)/2;
	    if(too_high(mid))
		ub = mid-1;
	    else
		lb = mid;
	}
	printf("Case #%d: %llu\n",cas,lb+1);
    }
    return 0;
}
