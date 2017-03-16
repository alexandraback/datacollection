#include<cstdio>
#include<limits.h>
using namespace std;

int main()
{
    int t;
    double ar[10000], p[10000];
    int a, b;
    int i;
    int j = 0;
    scanf("%d", &t);
    while(t--)
    {
	j++;
	double prod = 1;
	scanf("%d%d", &a, &b);
	for(i = 0; i < a; i++)
	{
	    scanf("%lf", &ar[i]);
	    prod *= ar[i];
	    p[a-1-i] = prod;
	}
	double k = INT_MAX;
	for(i = 0; i < a; i++)
	{
	    double temp;
	    temp = (b-a+1+2*i)*p[i] + (b-a+1+b+1+2*i)*(1-p[i]);
	    if(temp < k)
		k = temp;
	}

	if(b+2 < k)
	    k = b+2;
	printf("Case #%d: %lf\n",j, k);
    }
    return 0;
}

