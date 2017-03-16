#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int T;
long long N;

long long reverse(long long n)
{
	long long ret = 0;
	while (n)
	{
		ret = ret *10 + n % 10;
		n /= 10;
	}
	return ret;
}

int digit(long long n)
{
	return (int)(log(n) / log(10) - 0.0000001) + 1;
}

long long Ten[16];

bool checkValid(long long n) // remove 100..001
{
	long long ten = 10;
	while (ten < n)
	{
		if (n == ten + 1)
		{
			return false;
		}
		ten *= 10;
	}
	return true;
}

long long getAns(long long N)
{
	long long ans = 0;
	int d;
	while ((d=digit(N)) > 1)
	{
		long long subn = N % Ten[(d+1)/2];
		if (subn == 0)
		{
			N -= 1;
			ans ++;
			continue;
		}
		ans += subn - 1;
		N -= subn - 1;
		if (checkValid(N))
		{
			N = reverse(N);
			++ ans;
		}
		else
		{
			N -= 2;
			ans += 2;
		}
	}
	ans += N;
	return ans;
}

int F[100000];

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    Ten[0] = 1;
    for (int i=1;i<16;++i)
	{
		Ten[i] = Ten[i-1] * 10;
	}
    scanf("%d",&T);
/*
	memset(F,0x20,sizeof F);
	F[0] = 0;
	for (int i=0;i<100000;++i)
	{
		F[i+1] = min(F[i+1], F[i] + 1);
		F[reverse(i)] = min(F[reverse(i)], F[i] + 1);
	}
	
	for (int i=0;i<100000;++i)
	{
		if (getAns(i) != F[i])
		{
			printf("%d %d %d\n",i,F[i],getAns(i));
			return 0;
		}
	}
*/	
    for (int cases=1;cases<=T;cases++)
	{
		cin >> N;
		
		cout << "Case #" << cases << ": " << getAns(N) << "\n";
	}
    return 0;
}
