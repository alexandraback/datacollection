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

bool check(int x[], int y[])
{
	int tmp;
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<M; j++)
		{
			tmp = (x[i] < y[j]) ? x[i]+1 : y[j]+1;
			if (tmp != lawn[i][j])
				return false;
		}
	}
	return true;
}

bool add(int x[], int y[])
{
	int i=M;
	while (i>0 && y[i-1]==1)
	{
		i--;
		y[i]=0;
	}
	if (i==0)
	{
		i=N;
		while (i>0 && x[i-1]==1)
		{
			i--;
			x[i]=0;
		}
		if (i==0)
			return false;
		x[i-1]=1;
	}
	else
	{
		y[i-1]=1;
	}
	return true;
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

void work2()
{
	int hN[128], hM[128];

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
		bool result = false;	
		
		memset(hN, 0, sizeof(hN));
		memset(hM, 0, sizeof(hM));
		do {
			if (check(hN, hM))
			{
				result = true;
				break;
			}
		}while (add(hN, hM));	
		cout << (result ? "YES" : "NO") << endl;
	}
}

int main()
{
	freopen("C:\\Users\\yuazh\\Downloads\\B-small-attempt1.in", "r", stdin);
	freopen("C:\\Users\\yuazh\\Downloads\\B-small-attempt1.out", "w", stdout);
	init();
	work();

	return 0;
}

