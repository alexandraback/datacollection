#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

int x, n, m;

int main()
{
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	int T = 0;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		bool ok = 0;
		scanf("%d%d%d", &x, &n, &m);
		if(n > m) swap(n, m);
		if(n * m % x == 0)
		{
			if(x == 1) ok = 1;
			if(x == 2) ok = 1;
			if(x == 3)
			{
				if(n >= 2) ok = 1;
			}
			if(x == 4)
			{
				if(n >= 3) ok = 1;
			}
			if(x == 5)
			{
				if(n >= 3 && (n > 3 || m > 5)) ok = 1;
			}
			if(x == 6)
			{
				if(n >= 4) ok = 1;
			}
		}
				
		if(ok)
			printf("Case #%d: GABRIEL\n", t);
		else
			printf("Case #%d: RICHARD\n", t);
	}
	
	return 0;
}

