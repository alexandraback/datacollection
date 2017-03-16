#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long nwd(long long a, long long b)
{
	if(a < b) swap(a, b);
	while(b > 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

char s[100];

int main()
{
	int prz;
	cin >> prz;
	for(int licz = 0; licz < prz; ++licz)
	{
		cin >> s;
		long long p, q;
		p = q = 0;

		for(int i = 0; s[i]; ++i)
		{
			if(s[i] == '/') swap(p, q);
			else
			{
				p *= 10;
				p += s[i] - '0';
			}
		}
		swap(p, q);

		cout << "case #" << licz + 1 << ": ";
		long long d = nwd(p, q);
		p /= d;
		q /= d;

		long long pod = 1 << 20;
		pod *= pod;

		if(pod % q != 0) cout << "impossible\n";
		else
		{
			long long c = pod / q;
			pod /= p;
			pod /= 2;
			int w = 1;
			while(c < pod)
			{
				pod /= 2;
				w++;
			}
			cout << w << '\n';
		}
	}

	return 0;
}