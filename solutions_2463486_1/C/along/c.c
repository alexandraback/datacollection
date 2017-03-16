#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
using namespace std;

int isfair(long long n )
{
	char buf[1024];
	sprintf(buf, "%lld", n);
	int l = strlen(buf);
	int i;
	for(i=0; i<l; i++)
		if (buf[i] != buf[l-1-i])
			return 0;
	return 1;
}

int main()
{
	int i,j,k;
	vector<long long> v;
	v.push_back(1);
	v.push_back(4);
	v.push_back(9);
	for(k=3; k<3000; k++)
	{
		long long t = 0;
		int kk = k;
		long long u = 1;
		while(kk > 0)
		{
			t += u*(kk%3);
			u*=10; kk/=3;
		}
		if (isfair(t) && isfair(t*t))
			v.push_back(t*t);
	}
	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		long long a,b;
		cin >> a >> b;
		int r = 0;
		for(i=0; i<v.size(); i++)
			if (v[i] >= a && v[i] <= b)
				r++;
		printf("Case #%d: %d\n", cc, r);
	}
}
