#include "stdio.h"
#include "algorithm"
#include "vector"
#include "string"
#include "math.h"
#include "iostream"
#define MAX 111
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	int cas=0;
	std::vector<long long int> v;
	while(cas++<t)
	{
		long long int a;
		int n;
		scanf("%lld %d",&a,&n);
		for (int i = 0; i < n; ++i)
		{
			long long int temp;
			scanf("%lld",&temp);
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		int i;
		
		for (i = 0; v[i] < a && i<n; ++i)
		{
			
			a+=v[i];
		}
		int insert=0;
		int lowest=n-i;
		while(i<n)
		{
			int delet;
			insert +=1;
			a+= (a-1);
			if(insert>MAX) break;
			for (; v[i] < a && i<n; ++i)
			{
				a+=v[i];
			}
			delet = n-i;
			if(lowest> insert+delet) lowest=insert+delet;
		}
		v.clear();
		printf("Case #%d: %d\n",cas,lowest );
	}
	return 0;
}