#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
#include <map>
#include <deque>
#include <string>

using namespace std;

int t,T;
ifstream ein;
ofstream aus;

#define ULL unsigned long long

void runtestcase()
{
	ULL K,C,S;
	ein >> K >> C >> S;
	if (C * S < K)
	{
		aus << "IMPOSSIBLE";
		return;
	}
	else
	{
		ULL k = 0;
		for (ULL s = 0; s < S; s++)
		{
			ULL r = 0;
			for (ULL c = 0; c < C; c++)
			{
				if (k<K)
					r = K * r + k;
				else
					r = K * r;
				k++;
			}
			aus << r+1 << " ";
			if (k >= K)
				return;
		}
	}
}

void main()
{
	ein.open("D-large.in");
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