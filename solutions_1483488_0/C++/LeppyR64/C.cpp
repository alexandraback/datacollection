#include <cstdio>
using namespace std;

bool used[10000000];


long long process_case(int a, int b)
{
	for(int i = 0; i < 10000000; i++)
		used[i] = false;
	
	long long result = 0;
	int x=a, mod=1,y;
	while(x >= 10)
	{
		mod*=10;
		x/=10;
	}
	for(int i = a; i <= b; i++)
	{
		x = i;
		long long temp = 0;
		// printf("%d = ", i);
		if(!used[x])
		{
			while(!used[x])
			{
				// printf("%d ", x);
				y = x / mod;
				temp++;
				if(x < a || x > b)
					temp--;
				used[x] =  true;
				x = (x%mod)*10+y;
			}
		}
		//printf("= %d ", temp);
		if(temp > 1)
		{
			temp = temp*(temp-1ll)/2ll;
			// printf("= %d\n", temp);
			result += temp;
		}
		// else
		// {
			// printf("= 0\n");
		// }
	}
	return result;
}

int main()
{
	int t,a,b;
	scanf("%d", &t);
	for(int z = 1; z <= t; z++)
	{
		scanf("%d %d", &a, &b);
		printf("Case #%d: %lld\n", z, process_case(a,b));
	}
}
