#include<stdio.h>
#include<math.h>

int is_palindrome(long long int num)
{
	int l,i;
	int a,b;
	long long int s=10;
	l=1;
	for(;;)
		if (s>num)
			break;
		else {
			s*=10;
			l++;
		}
	s/=10;
	while(l>0)
	{
		a = num/s;
		b = num%10;
		if (a != b) break;
		num = num - a*s;
		num /=10;
		s/=100;
		l-=2;
	}
	if (l>0) return 0;
	else return 1;
}

int main()
{
	long long int t;
	int i,j,k;
	long long int a,b;

	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		long long int aa,bb;
		long long int n;
		int count=0;
		scanf("%lld%lld",&a,&b);
		aa = (long long int) sqrt((double)a);
		bb = (long long int) sqrt((double)b);
		if (aa*aa < a) aa++;
		if (bb*bb > b) bb--;

		for(n=aa;n<=bb;n++)
		{
			long long int tmp;
			if (is_palindrome(n))
			{
				tmp = n*n;
				if (is_palindrome(tmp))
					count++;
			}
		}

		printf("Case #%d: %d\n",i+1,count);
	}
	return 0;
}




	

