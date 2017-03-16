#include <cstdio>

using namespace std;

int main()
{
	int T ;
	long long r , t , k , count;
	scanf("%d" , &T);
	for(int a=1 ; a<=T ; a++)
	{
		printf("Case #%d: " , a);
		scanf("%lld %lld" , &r , &t);
		k = 1;
		r *= 2;
		count = 0;
		while(t>=0)
		{
			
			t = t- (r+k);
			k = k+4;
			if(t>=0)
				count++;
			
		}
		printf("%lld\n" , count);
	}
	return 0;
}
