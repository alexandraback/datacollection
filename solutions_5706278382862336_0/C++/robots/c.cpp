#include <iostream>
using namespace std;
long long gcd (long long a,long long b)
{
	return b == 0 ? a : gcd (b,a % b);
}
long long lcm (long long a,long long b)
{
	return a / gcd (a,b) * b;
}
int cmp (long long a,long long b,long long c,long long d)
{
	if (a == c){

		if (b < d)
			return 1;
		else if(b > d)
			return -1; // a/b less
		else
			return 0;
	}
	if (b == d)
	{
		if (a < c)
			return -1; // a/b less
		else if(a > c)
			return 1;
		else
			return 0;
	}
	long long p = lcm (b,d);
	return cmp (a * (p / b),p,c * (p / d),p);
}
int main()
{
	freopen ("in.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	int t;
	cin >> t;
	long long parent = 1099511627776;
	for (int i = 0; i < t; i++)
	{
		int p,q;
		scanf("%d/%d",&p,&q);
		int d = gcd (p,q);
		p /= d;
		q /= d;
		//int ans = 0;
		//for (long long j = 1; ans < 41 ; j *= 2)
		//{
		//	if (cmp(p,q,1,j) >= 0){
		//		break;
		//	}
		//	ans++;
		//}
		if ((parent * p) % q != 0)
			printf ("Case #%d: impossible\n",i + 1);
		else{
			unsigned long long all = (parent * p) / q;
			int ans2 = 0;
			while (all != 0)
			{
				ans2++;
				all >>= 1;
			}
			ans2 = 40 - ans2 + 1;
			printf ("Case #%d: %d\n",i + 1,ans2);
		}
	}
	return 0;
}