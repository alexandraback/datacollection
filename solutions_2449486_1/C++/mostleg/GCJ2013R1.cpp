// GCJ2013R1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

int T;
int N,M;
int lawn[128][128];

void init()
{
	cin >> T;
}


void work()
{
	int bigN[128], bigM[128];

	for (int ca=1; ca<=T; ca++)
	{
		cin >> N >> M;
		for (int i=0; i<N; i++)
		{
			for (int j=0; j<M; j++)
			{
				cin >> lawn[i][j];
			}
		}

		cout << "Case #" << ca << ": ";
		bool result = true;	
		
		memset(bigN, 0, sizeof(bigN));
		memset(bigM, 0, sizeof(bigM));
		for (int i=0; i<N; i++)
		{
			for (int j=0; j<M; j++)
			{
				if (lawn[i][j] > bigN[i])
					bigN[i] = lawn[i][j];
				if (lawn[i][j] > bigM[j])
					bigM[j] = lawn[i][j];
			}
		}
		for (int i=0; i<N; i++)
		{
			for (int j=0; j<M; j++)
			{
				if (lawn[i][j] < bigN[i] && lawn[i][j] < bigM[j])
					result = false;				
			}
		}
		cout << (result ? "YES" : "NO") << endl;
	}
}


int main()
{
	freopen("C:\\Users\\yuazh\\Downloads\\B-large.in", "r", stdin);
	freopen("C:\\Users\\yuazh\\Downloads\\B-large.out", "w", stdout);
	init();
	work();

	return 0;
}

