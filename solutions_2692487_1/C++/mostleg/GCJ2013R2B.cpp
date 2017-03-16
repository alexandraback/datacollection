// GCJ2013R2B.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#pragma warning(disable:4996)

using namespace std;

int T;
long A,N;
long m[128];



void init()
{
	cin >> T;
}


void work()
{
	for (int ca=1; ca<=T; ca++)
	{
		cin >> A >> N;

		cout << "Case #" << ca << ": ";
		int count=0;	
		int best=N;
		for (int i=0; i<N; i++)
		{
			cin >> m[i];			
		}
		sort(m, m+N);
		
		/*for (int i=0; i<N; i++)
		{
			cout << m[i] << ' ';
		}
		cout << "A=" << A << endl;*/
		if (A == 1)
		{
			;
		}
		else
		{
			for (int i=0; i<N; i++)
			{
				if (m[i] < A)
				{
					A += m[i];
				}
				else
				{
					if (N-i+count < best)
					{
						best = N-i+count;
					}

					while (A <= m[i])
					{
						A += A-1;
						count++;						
					}
					A+=m[i];
				}
				if (count >= best)
				{
					break;
				}
			}
			if (count < best)
			{
				best = count;
			}
		}
		cout << best << endl;
	}
}


int main()
{
	freopen("C:\\Users\\yuazh\\Downloads\\A-large.in", "r", stdin);
	freopen("C:\\Users\\yuazh\\Downloads\\A-large.out", "w", stdout);
	init();
	work();

	return 0;
}

