#include <stdio.h>
#include <stdbool.h>

long long int split(long long int n,bool ten[])
{
	int count = 0, i;
	long long int z = n;
	for(i=1;i>0 && count!=10;i++)
	{
		int p = z;
		while(p != 0)
		{
			int k = p % 10;
			if (ten[k] == false)
			{
				ten[k] = true;
				count++;
			}
			p = p / 10;
		}
		if (count == 10)
		{
			return z;
		}
		z=n*(i+1);
	}
	return z;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long int t,b,i,j;
	bool ten[10];
	scanf("%lld", &t);
	for (i = 0; i < t; i++){
		for(j = 0; j < 10; j++){
			ten[j] = false;
		}
		scanf("%lld", &b);
		if (b == 0)
		{
			printf("Case #%lld: INSOMNIA\n", i+1);
		}
		else {
			long long int z = split(b,ten);
			printf("Case #%lld: %lld\n", i+1, z);
		}
	}
	return 0;
}
