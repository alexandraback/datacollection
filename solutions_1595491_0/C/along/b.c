#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int i,j,k;
	int cc,ca;
	int N, S, p;
	int s[1000];
	int f[1000];

	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> N >> S >> p;
		for(i=0; i<N; i++) cin >> s[i];
		for(i=0; i<N; i++)
		{
			if (s[i]%3 == 0)
			{
				if (s[i] >= p*3) f[i] = 2;
				else if (s[i] >= (p-2)*3+2) f[i] = 1;
				else f[i] = 0;
				if (p == 0)
					f[i] = 2;
				if (p == 1)
				{
					if (s[i] >= 3) f[i] = 2;
					else f[i] = 0;
				}
			}
			else
			{
				if (s[i] > (p-1)*3) f[i] = 2;
				else if (s[i] >= (p-2)*3+2) f[i] = 1;
				else f[i] = 0;
				if (p == 0)
					f[i] = 2;
				if (p == 1)
				{
					if (s[i] >= 1) f[i] = 2;
					else f[i] = 0;
				}
			}
//			printf("%d %d\n", i, f[i]);
		}
		int r = 0;
		for(i=0; i<N; i++) if (f[i] == 2) r++;
		int rr = 0;
		for(i=0; i<N; i++) if (f[i] == 1) rr++;
		if (S < rr) rr = S;
//		printf("%d %d\n", r, rr);
		r += rr;
		printf("Case #%d: %d\n", cc, r);
	}
}
