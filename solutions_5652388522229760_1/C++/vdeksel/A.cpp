#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <deque>

using namespace std;

int t,T;
ifstream ein;
ofstream aus;

#define ULL unsigned long long

void runtestcase()
{	
	ULL N;
	ein >> N;

	if (N == 0)
	{
		aus << "INSOMNIA";
		return;
	}

	bool dig[10];
	for (unsigned int i=0;i<10;i++)
		dig[i]=false;
	unsigned int ndigs = 0;

	ULL a = 0;

	while (true)
	{
		a += N;

		ULL b = a;
		while (b>0)
		{			
			ULL i = b % 10;
			if (!dig[i])
			{
				dig[i] = true;
				ndigs++;
				if (ndigs == 10)
				{
					aus << a;
					return;
				}
			}
			b = ((b-i) / 10);
		}
	}
}

void main()
{
	ein.open("A-large.in");
	aus.open("ausgabe.txt");

	ein >> T;
	for (t = 1; t <= T; t++)
	{
		printf("%d\n", t);
		aus << "Case #" << t << ": ";
		runtestcase();
		aus << endl;
	}

	aus.close();
	ein.close();
}