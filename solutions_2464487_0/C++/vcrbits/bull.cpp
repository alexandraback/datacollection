#include<cstdio>
long long int search(long long int l,long long int h,long long int t,long long int r)
{
	int m = (l+h)/2,tmp;
	if (h < l)
		return -1;
	tmp = 2*r*m+2*m*m-m;
	if (tmp <= t)
	{
		int p = search(m+1,h,t,r);
		if (p==-1)
			return m;
		else
			return p;
	}
	else
		return search(l,m-1,t,r);
}
int main()
{
	long long int T,r,t,k,tmp,ca=0;
	scanf("%lld",&T);
	while(T--)
	{
		ca++;
		scanf("%lld%lld",&r,&t);
		k = 1;
		tmp = 2*r*k+2*k*k-k;
		if (tmp > t)
		{
			printf("Case #%lld: 0\n",ca);
			continue;
		}
		while(tmp <= t)
		{
			k = k*2;
			tmp = 2*r*k+2*k*k-k;
		}
		printf("Case #%lld: %lld\n",ca,search(0,k,t,r));
	}
	return 0;
}
