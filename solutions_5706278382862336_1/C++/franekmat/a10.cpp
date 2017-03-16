#include "cstdio"
#include "cmath"
using namespace std;
long long t,x,a,b,w,z;
bool ok;
int main()
{
	scanf ("%lld", &t);
	for (int i=0; i<t; i++)
	{
		scanf ("%lld/%lld", &a, &b);
		x=0;
		while (b%2<=0) b/=2,x++;
		
		if (a%b>0) printf ("Case #%d: impossible\n", i+1);
		else
		{
			a/=b;
			z=0;
			while (pow(2,z+1)<=a) z++;
			printf ("Case #%d: %lld\n", i+1, x-z);
		}
	}
	
	return 0;
}
