#include<stdio.h>
#include<map>

#define LIMIT 100000000000000

using namespace std;

long long reverse(long long n)
{
	long long res=0;
	while(n>0)
	{
		res=res*10+(n%10);
		n/=10;
	}
	return res;
}

bool IsPalindrome(long long n)
{
	long long rev = reverse(n);
	return rev == n;
}

int main()
{
	int T;
	long long start,end;
	map<long long, long long> res;
	long long ind = 0;
	for(long long i=1; i*i<=LIMIT; i++)
	{
		if(IsPalindrome(i))
		{
			long long square = i*i;
			if(IsPalindrome(square))
				res.insert(res.end(),pair<long long, long long>(square, ind++));
		}
	}
	long long total = res.size();

	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%lld %lld",&start,&end);
		long long count;
		map<long long, long long>::iterator lower = res.lower_bound(start);
		map<long long, long long>::iterator upper = res.upper_bound(end);
		if(lower == res.end())
			count = 0;
		else if(upper == res.end())
			count = total - lower->second;
		else
			count = upper->second - lower->second;
		printf("Case #%d: %d\n",i,count);
	}
	return 0;
}