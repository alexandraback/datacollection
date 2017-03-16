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

void runtestcase()
{
	unsigned int N;
	unsigned long long J;
	ein >> N >> J;	
	for (unsigned long long j=0; j<J; j++)
	{
		aus << endl;	
		unsigned long long K = 1;
		aus << "11";
		unsigned int n;
		for (n=0; 2*n + 4 < N; n++)
		{
			if ((j & K) == K)
			{
				aus << "11";
			}
			else
			{
				aus << "00";
			}
			K *= 2;
		}		
		aus << "11 ";
		for (unsigned int k=2;k<=10;k++)
			aus << k+1 << " ";
	}
}

void main()
{
	ein.open("C-small-attempt0.in");
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