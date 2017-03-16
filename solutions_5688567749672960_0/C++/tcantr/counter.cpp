#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <math.h>

using namespace std;

long long reverse(long long a)
{
	long long b;
	b = 0;
	while (a>0)
	{
		b=((b*10)+(a%10));
		a/=10;
	}
	return b;
}

int main()
{
    long long T,N;
    long long i,j,x;
    long long min;
    long long F[1000000];

    cin >> T;
    
    for (x=0;x<T;x++)
    {

	cin >> N;

	for (i=0;i<11;i++)
		F[i] = i;

	for (i=11;i<=N;i++)
	{
		j = reverse(i);

		//printf("i= %lld j = %lld F[j] = %lld F[i-1] = %lld\n",i,j,F[j],F[i-1]);
		
		if (i%10!=0 && reverse(j)==i && j!=i)
		{
			if (j<i && F[j]<F[i-1])
				F[i] = F[j]+1;
			else F[i] = F[i-1]+1;
			
		}
		else F[i] = F[i-1]+1;
	}

	//printf("%lld ... %lld\n",F[21],F[12]);
	printf("Case #%lld: %lld\n",x+1,F[N]);
		
    }
}
