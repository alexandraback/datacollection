#include<cstdio>
#include<iostream>
using namespace std;

int CaseNumber;
long long R,T;

double upper = 1LL << 62;
long long upperll = (1LL << 63) - 1LL;

long long f(long long n)
{
	double nf = n;
	if (nf * (2*R+1) + 2*nf*(nf-1) > upper)
		return upperll;
	return (2*R+1)*n + 2*n*(n-1);
}

long long bsearch()
{
	long long l = 1LL,r = T + 1;
	while (r - l > 1)
	{
		long long m = (l+r) >> 1;
		if (f(m) > T)
			r = m;
		else
			l = m;
	}
	return l;
}


int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin >> CaseNumber;
	for (int cases=1;cases<=CaseNumber;cases++)
	{
		cin >> R >> T;
		long long ans = bsearch();
		cout << "Case #"<< cases <<": "<<ans<<"\n";
	}
	return 0;
}
