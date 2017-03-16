// GCJ2013R2C.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

#pragma warning(disable:4996)

using namespace std;

int T,N;
string s;
int n;

void init()
{
	cin >> T;
}

struct _tribe
{
	int d;
	int n;
	int dc;
	int w;
	int e;
	int wec;
	int s;
	int sc;
}tr[1024];
int wall[200002];

void work()
{
	for (int ca=1; ca<=T; ca++)
	{
		cin >> N;
		memset(wall,0,sizeof(wall));
		cout << "Case #" << ca << ": ";
		for (int i=0; i<N; i++)
		{
			cin >> tr[i].d >> tr[i].n >> tr[i].w >> tr[i].e >> tr[i].s >> tr[i].dc >> tr[i].wec >> tr[i].sc;
		}
		int day=0;
		int win=0;
		while (1)
		{
			int TD = 10000000;			
			for (int i=0; i<N; i++)
			{
				if (tr[i].n <= 0)
				{
					continue;
				}
				if (tr[i].d < TD)
				{
					TD = tr[i].d;
				}
			}
			if (TD == 10000000)
				break;
			for (int i=0; i<N; i++)
			{
				if (tr[i].n <= 0)
				{
					continue;
				}
				
				if (tr[i].d == TD)
				{					
					for (int j=tr[i].w; j<tr[i].e; j++)
					{
						if (wall[j+100000] < tr[i].s)
						{
							win++;
							break;							
						}
					}					
				}
			}
			for (int i=0; i<N; i++)
			{
				if (tr[i].n <= 0)
				{
					continue;
				}
				
				if (tr[i].d == TD)
				{
					tr[i].n--;
					for (int j=tr[i].w; j<tr[i].e; j++)
					{
						if (wall[j+100000] < tr[i].s)
						{
							wall[j+100000] = tr[i].s;						
						}
					}
					tr[i].w += tr[i].wec;
					tr[i].e += tr[i].wec;
					tr[i].d += tr[i].dc;
					tr[i].s += tr[i].sc;
				}
			}
		}
		
		cout << win << endl;
		
	}
}


int main()
{
	freopen("C:\\Users\\yuazh\\Downloads\\C-small-attempt0.in", "r", stdin);
	freopen("C:\\Users\\yuazh\\Downloads\\C-small-attempt0.out", "w", stdout);
	init();
	work();

	return 0;
}



