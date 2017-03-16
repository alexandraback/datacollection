#include <stdio.h>
#include <math.h>

long long br_num(long long r, long long t)
{
	long long mid, i, j;
	i=0; j=sqrt((double)t);
	if (j > t/(2*r)) j=t/(2*r);
	while (i<j)
	{
		mid = (i+j)/2;
		if ((mid+1)*(mid+1) + (2.0*r+mid)*(mid+1) < t) i=mid+1;
		else j=mid;
	}
	i++;
	while (1) {
		if ((i+1)*(i+1) + (2*r+i)*(i+1) <= t) return i+1;
		i--;
	}
	return i+1;
}
	

int main()
{
	int T;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	scanf("%d",&T);
	for (int cas=1; cas<=T; cas++)
	{
		long long r,t;
		scanf("%lld%lld",&r,&t);
		printf("Case #%d: %lld\n", cas, br_num(r,t));
	}
	return 0;
}
		
